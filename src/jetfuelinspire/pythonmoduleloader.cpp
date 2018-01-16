/*
* Jetfuel Game Engine- A SDL-based 2D game-engine
* Copyright (C) 2018 InfernoStudios
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "pythonmoduleloader.h"

#include "pythonclassloader.h"

namespace jetfuel {
    namespace inspire {
		#ifdef _WIN32
			//std::mutex Python_module_loader::m_pythonoperationsmutex;
			bool Python_module_loader::m_pythoninited = false;
		#else
				//static std::mutex Python_module_loader::m_pythonoperationsmutex;
				static bool Python_module_loader::m_pythoninited = false;
		#endif

        Python_module_loader::Python_module_loader(const std::string filename, 
									const std::string functionname,
                                    const std::string directoryoffilename,
                                    const std::string filetoreplace,
                                    const std::string directoryoffiletoreplace) {
            m_filename = filename;
            m_functionname = functionname;
            m_directoryoffilename = directoryoffilename;
            m_filetoreplace = filetoreplace;
            m_directoryoffiletoreplace = directoryoffiletoreplace;
            m_usingclasses = false;

            Py_Initialize();
        }

        Python_module_loader::Python_module_loader(
						jetfuel::inspire::Python_class_loader *pythonclasstouse,
                                                const std::string functionname) {
            pythonclass = pythonclasstouse->pythonclass;
            m_functionname = functionname;
            m_usingclasses = true;

            Py_Initialize();
            m_pythoninited = true;
        }

		Python_module_loader::~Python_module_loader() {
			Py_Finalize();
		}

		std::string Python_module_loader::Get_py_error(PyObject *errorobject) {
			std::string returnvalue;

			if (PyUnicode_Check(errorobject)) {
				PyObject * temp_bytes = PyUnicode_AsEncodedString(
					errorobject, "ASCII", "strict");
				if (temp_bytes != NULL) {
					returnvalue = PyBytes_AS_STRING(temp_bytes);
					returnvalue = strdup(returnvalue.c_str());
					Py_DECREF(temp_bytes);
				}
				else {
					throw exceptions::
						Python_returnvalue_ASCII_encoding_exception(
							"Jetfuel Game Engine",
							"Python_module_loader::Py_err_to_cstring()");
				}
			}

			return returnvalue;
		}

        std::string Python_module_loader::Py_err_to_string(
									PyObject *pythonerrortype, 
									PyObject *pythonerrorvalue,
                                    PyObject *pythonerrortraceback){
            std::string returnvalue;

            if(pythonerrorvalue != nullptr){
				returnvalue = Get_py_error(pythonerrorvalue);
            }

            if(pythonerrortype != nullptr){
                returnvalue.append("\nType:");
                returnvalue.append(Get_py_error(pythonerrortype));
            }

            if(pythonerrortraceback != nullptr){
                returnvalue.append("\nTraceback:");
                returnvalue.append(Get_py_error(pythonerrortraceback);
            }


            return returnvalue;
        }

        void Python_module_loader::Add_to_py_path(
								const std::string pathlocationtoadd){
			// Get python path, append the path location to add,
			// and set it as the new path.

            //Lock_python_operations_mutex();

            std::string pythonpathtouse = Get_string(Py_GetPath());

            if(pythonpathtouse.find(pathlocationtoadd) == std::string::npos){
				#ifdef _WIN32
					pythonpathtouse.append(";" + pathlocationtoadd);
				#else
					pythonpathtouse.append(":" + pathlocationtoadd);
				#endif

				wchar_t *newpythonpath = Get_wchar(pythonpathtouse.c_str());

                PySys_SetPath(newpythonpath);
            }

            //Unlock_python_operations_mutex();
        }

        void Python_module_loader::Base_execute_py_object(
														PyObject *pythonfunction,
                                                          PyObject *args, 
														  bool *executed, 
														  std::string *error){
			// Checks if the function object is not nullptr, and check
			// that it is callable.

			PyObject *pythonerrortype;
			PyObject *pythonerrorvalue;
			PyObject *pythonerrortraceback;

            if(pythonfunction==nullptr){
                PyErr_Fetch(&pythonerrortype, &pythonerrorvalue, 
							&pythonerrortraceback);

                *error = Py_err_to_string(pythonerrortype,pythonerrorvalue,
											pythonerrortraceback);
                *executed = false;
                return;
            }
            if(!PyCallable_Check(pythonfunction)){
                PyErr_Fetch(&pythonerrortype, &pythonerrorvalue, 
							&pythonerrortraceback);

                *executed = false;
                *error = Py_err_to_string(pythonerrortype,pythonerrorvalue,
										   pythonerrortraceback);
                return;
            }
            *executed=true;
        }

        void Python_module_loader::Execute_py_object(PyObject *args,
									bool *executed, std::string *error){
			// Sets up the Python objects, calls the function, 
			// gets any error, and if there were any, mark this 
			// function as not executed. Otherwise, mark it as 
			// executed.

			PyObject *pythonfunction;
			PyObject *pythonfile;
			PyObject *pythonmodule;

			PyObject *pythonerrortype;
			PyObject *pythonerrorvalue;
			PyObject *pythonerrortraceback;

            //Lock_python_operations_mutex();

            if(!Using_classes()){
                pythonfile = PyUnicode_DecodeFSDefault(Get_file_name().c_str());
                pythonmodule = PyImport_Import(pythonfile);

                if(pythonmodule == nullptr){
                    *executed=false;
                    *error = "Could not open "+ Get_file_name()+"."+
                             " Does the file exist?";
                }else{
                    pythonfunction = PyObject_GetAttrString(pythonmodule,
                                             Get_function_name().c_str());
                }
            }else{
                pythonfunction = PyObject_GetAttrString(pythonclass,
                                                  Get_function_name().c_str());
            }

            if(pythonfunction == nullptr && *error == ""){
                *executed=false;
                *error = "Could not find function "+ Get_function_name();
            }else if(pythonfunction != nullptr && pythonmodule != nullptr){
                Base_execute_py_object(pythonfunction,args,executed,error);
            }

            if(!*executed){
                return;
            }

            PyObject_CallObject(pythonfunction,args);

            PyErr_Fetch(&pythonerrortype, &pythonerrorvalue,
                                          &pythonerrortraceback);

            if(pythonerrorvalue==nullptr){
                *executed = true;
            }else{
                *executed = false;

                *error = Py_err_to_string(pythonerrortype,pythonerrorvalue,
										   pythonerrortraceback);

                if(*error == ""){
                    *error = std::string()+
                            "Module was not found (MoudleNotFoundError)."+
                             " Is the file valid?";
                }

                return;
            }

            if(pythonclass==NULL){
                Py_DECREF(pythonfile);
                Py_DECREF(pythonmodule);
            }
            Py_DECREF(pythonfunction);

            //Unlock_python_operations_mutex();
        }

        bool Python_module_loader::Execute_py_object_bool(PyObject *args,
											bool *executed, std::string *error){
			// Sets up the Python objects, calls the function
			// (making sure to get a return type), gets any error, and 
			// if there were any, mark this function as not executed. 
			// Otherwise, mark it as executed.

            //Lock_python_operations_mutex();

            PyObject *pythonfile, *pythonmodule, *pythonfunction;
            if(!Using_classes()){
                pythonfile = PyUnicode_DecodeFSDefault(Get_file_name().c_str());
                pythonmodule = PyImport_Import(pythonfile);
                pythonfunction = PyObject_GetAttrString(pythonmodule,
													Get_function_name().c_str());
            }else{
                pythonfunction = PyObject_GetAttrString(pythonclass,
													Get_function_name().c_str());
            }

            Base_execute_py_object(pythonfunction,args,executed,error);

            if(!*executed){
                return NULL;
            }

            PyObject *pythonreturnvalue = PyObject_CallObject(pythonfunction,
															  args);

			PyObject *pythonerrortype;
			PyObject *pythonerrorvalue;
			PyObject *pythonerrortraceback;

            PyErr_Fetch(&pythonerrortype, &pythonerrorvalue, 
						&pythonerrortraceback);

            bool returnvalue;

            if(pythonerrorvalue==nullptr){
                *executed = true;
                if(pythonreturnvalue == Py_True){
                    returnvalue = true;
                }else{
                    returnvalue = false;
                }
            }else{
                *executed = false;
                *error = Py_err_to_string(pythonerrortype,pythonerrorvalue,
										   pythonerrortraceback);
                return nullptr;
            }

            if(pythonclass==nullptr){
                Py_DECREF(pythonfile);
                Py_DECREF(pythonmodule);
            }
            Py_DECREF(pythonfunction);
            Py_DECREF(pythonreturnvalue);

            //Unlock_python_operations_mutex();

            return returnvalue;
        }

        long Python_module_loader::Execute_py_object_long(PyObject *args,
										bool *executed, std::string *error){
			// Sets up the Python objects, calls the function
			// (making sure to get a return type), gets any error, and 
			// if there were any, mark this function as not executed. 
			// Otherwise, mark it as executed.

            //Lock_python_operations_mutex();

            PyObject *pythonfile, *pythonmodule, *pythonfunction;
            if(!Using_classes()){
                pythonfile = PyUnicode_DecodeFSDefault(Get_file_name().c_str());
                pythonmodule = PyImport_Import(pythonfile);
                pythonfunction = PyObject_GetAttrString(pythonmodule,
												Get_function_name().c_str());
            }else{
                pythonfunction = PyObject_GetAttrString(pythonclass,
												Get_function_name().c_str());
            }


            Base_execute_py_object(pythonfunction,args,executed,error);

            if(!*executed){
                return NULL;
            }

            PyObject *pythonreturnvalue = PyObject_CallObject(pythonfunction,
															  args);

			PyObject *pythonerrortype;
			PyObject *pythonerrorvalue;
			PyObject *pythonerrortraceback;

            PyErr_Fetch(&pythonerrortype, &pythonerrorvalue, &pythonerrortraceback);

            long returnvalue;

            if(pythonerrorvalue==NULL){
                *executed = true;
                returnvalue = PyLong_AsLong(pythonreturnvalue);
            }else{
                *executed = false;
                *error = Py_err_to_string(pythonerrortype,pythonerrorvalue,
										   pythonerrortraceback);
                return NULL;
            }

            if(pythonclass==NULL){
                Py_DECREF(pythonfile);
                Py_DECREF(pythonmodule);
            }

            Py_DECREF(pythonfunction);
            Py_DECREF(pythonreturnvalue);

            //Unlock_python_operations_mutex();

            return returnvalue;
        }

        double Python_module_loader::Execute_py_object_double(PyObject *args,
											bool *executed, std::string *error){
			// Sets up the Python objects, calls the function
			// (making sure to get a return type), gets any error, and 
			// if there were any, mark this function as not executed. 
			// Otherwise, mark it as executed.

            //Lock_python_operations_mutex();

            PyObject *pythonfile, *pythonmodule, *pythonfunction;
            if(!Using_classes()){
                pythonfile = PyUnicode_DecodeFSDefault(Get_file_name().c_str());
                pythonmodule = PyImport_Import(pythonfile);
                pythonfunction = PyObject_GetAttrString(pythonmodule,
													Get_function_name().c_str());
            }else{
                pythonfunction = PyObject_GetAttrString(pythonclass,
													Get_function_name().c_str());
            }

            Base_execute_py_object(pythonfunction,args,executed,error);

            if(!*executed){
                return NULL;
            }

            PyObject *pythonreturnvalue = PyObject_CallObject(pythonfunction,
															  args);

			PyObject *pythonerrortype;
			PyObject *pythonerrorvalue;
			PyObject *pythonerrortraceback;

            PyErr_Fetch(&pythonerrortype, &pythonerrorvalue, 
						&pythonerrortraceback);

            double returnvalue;

            if(pythonerrorvalue==NULL){
                *executed = true;
                returnvalue = PyFloat_AsDouble(pythonreturnvalue);
            }else{
                *executed = false;
                *error = Py_err_to_string(pythonerrortype,pythonerrorvalue,
											pythonerrortraceback);
                return NULL;
            }

            if(pythonclass==NULL){
                Py_DECREF(pythonfile);
                Py_DECREF(pythonmodule);
            }

            Py_DECREF(pythonfunction);
            Py_DECREF(pythonreturnvalue);

            //Unlock_python_operations_mutex();

            return returnvalue;
        }

        char *Python_module_loader::Execute_py_object_cstring(PyObject *args,
											bool *executed, std::string *error){
			// Sets up the Python objects, calls the function
			// (making sure to get a return type), gets any error, and 
			// if there were any, mark this function as not executed. 
			// Otherwise, mark it as executed.s

            //Lock_python_operations_mutex();

            PyObject *pythonfile, *pythonmodule, *pythonfunction;
            if(!Using_classes()){
                pythonfile = PyUnicode_DecodeFSDefault(Get_file_name().c_str());
				pythonmodule = PyImport_Import(pythonfile);
				if (pythonmodule != nullptr) {
					pythonfunction = PyObject_GetAttrString(pythonmodule, 
													Get_function_name().c_str());
				}else{
					*error = "I was unable to import the python file. "+
						"Does it exist? Does it have no import errors?";
					*executed = false;
					return "";
				}
            }else{
                pythonfunction = PyObject_GetAttrString(pythonclass,
											Get_function_name().c_str());
            }

            Base_execute_py_object(pythonfunction,args,executed,error);

            if(!*executed){
                return "";
            }

            PyObject *pythonreturnvalue = PyObject_CallObject(pythonfunction,
															  args);

			PyObject *pythonerrortype;
			PyObject *pythonerrorvalue;
			PyObject *pythonerrortraceback;

            PyErr_Fetch(&pythonerrortype, &pythonerrorvalue, 
						&pythonerrortraceback);

            char *returnvalue;

            if(pythonerrorvalue==NULL){
                *executed = true;
                if (PyUnicode_Check(pythonreturnvalue)) {
                    PyObject * temp_bytes = PyUnicode_AsEncodedString(
													pythonreturnvalue, "ASCII",
													"strict");
                    if (temp_bytes != NULL) {
                        returnvalue = PyBytes_AS_STRING(temp_bytes);
                        returnvalue = strdup(returnvalue);
                        Py_DECREF(temp_bytes);
                    } else {
                        throw exceptions::
						Python_returnvalue_ASCII_encoding_exception(
										Get_file_name(), Get_function_name());
                    }
                }
            }else{
                *executed = false;
                *error = Py_err_to_string(pythonerrortype,
									pythonerrorvalue,pythonerrortraceback);
                return "";
            }

            if(pythonclass==nullptr){
                Py_DECREF(pythonfile);
                Py_DECREF(pythonmodule);
            }

            Py_DECREF(pythonfunction);
            Py_DECREF(pythonreturnvalue);

            //Unlock_python_operations_mutex();

            return returnvalue;
        }

        void Python_module_loader::Execute(bool *executed, std::string *error, 
										   PyObject *args){
			// Adds the directory of the Python files to the Python
			// path, executes the Python object, and then
			// (if successful), repeats the previous steps for the
			// files to replace.

            Add_to_py_path(Get_directory_of_file_name());

            Execute_py_object(args,executed,error);

            if(!*executed){
                return;
            }

            if(Get_file_to_replace()!=""){
                Add_to_py_path(Get_directory_of_file_to_replace());

                bool tempexecuted;
                std::string temperror;
                Execute_py_object(args,&tempexecuted,&temperror);
            }
        }

        bool Python_module_loader::Execute_bool(bool *executed, 
											std::string *error, PyObject *args){
			// Adds the directory of the Python files to the Python
			// path, executes the Python object(getting the return 
			/// value), and then (if successful), repeats the previous
			// steps for the files to replace.
			// The file to replace return value takes precendence over
			// the first file's return value.

            Add_to_py_path(Get_directory_of_file_name());

            bool returnvalue = Execute_py_object_bool(args,executed,error);

            if(!*executed){
                return NULL;
            }

            if(Get_file_to_replace()!=""){
                Add_to_py_path(Get_directory_of_file_to_replace());

                bool tempexecuted;
                std::string temperror;
                bool potentialreturnvalue = Execute_py_object_bool(args,
													&tempexecuted,&temperror);
                if(tempexecuted){
                    returnvalue=potentialreturnvalue;
                }
            }


            return returnvalue;
        }

        long Python_module_loader::Execute_long(bool *executed, 
										std::string *error, PyObject *args){
			// Adds the directory of the Python files to the Python
			// path, executes the Python object(getting the return 
			/// value), and then (if successful), repeats the previous
			// steps for the files to replace.
			// The file to replace return value takes precendence over
			// the first file's return value.

            Add_to_py_path(Get_directory_of_file_name());

            long returnvalue = Execute_py_object_long(args,executed,error);

            if(!*executed){
                return NULL;
            }

            if(Get_file_to_replace()!=""){
                Add_to_py_path(Get_directory_of_file_to_replace());

                bool tempexecuted;
                std::string temperror;
                long potentialreturnvalue = Execute_py_object_long(args,
													&tempexecuted,&temperror);
                if(tempexecuted){
                    returnvalue=potentialreturnvalue;
                }
            }

            return returnvalue;
        }

        double Python_module_loader::Execute_double(bool *executed, 
											std::string *error, PyObject *args){
			// Adds the directory of the Python files to the Python
			// path, executes the Python object(getting the return 
			/// value), and then (if successful), repeats the previous
			// steps for the files to replace.
			// The file to replace return value takes precendence over
			// the first file's return value.

            Add_to_py_path(Get_directory_of_file_name());

            double returnvalue = Execute_py_object_double(args,executed,error);

            if(!*executed){
                return NULL;
            }

            if(Get_file_to_replace()!=""){
                Add_to_py_path(Get_directory_of_file_to_replace());

                bool tempexecuted;
                std::string temperror;
                double potentialreturnvalue = Execute_py_object_double(args,
													&tempexecuted,&temperror);
                if(tempexecuted){
                    returnvalue=potentialreturnvalue;
                }
            }

            return returnvalue;
        }

        char* Python_module_loader::Execute_cstring(bool *executed, 
									std::string *error, PyObject *args){
			// Adds the directory of the Python files to the Python
			// path, executes the Python object(getting the return 
			/// value), and then (if successful), repeats the previous
			// steps for the files to replace.
			// The file to replace return value takes precendence over
			// the first file's return value.

            Add_to_py_path(Get_directory_of_file_name());

            char *returnvalue = Execute_py_object_cstring(args,executed,error);

            if(!*executed){
                return "";
            }

            if(Get_file_to_replace()!=""){
                Add_to_py_path(Get_directory_of_file_to_replace());

                bool tempexecuted;
                std::string temperror;
                char *potentialreturnvalue = Execute_py_object_cstring(args,
													&tempexecuted,&temperror);
                if(tempexecuted){
                    returnvalue=potentialreturnvalue;
                }
            }

            return returnvalue;
        }

    } /* namespace inspire */
} /* namespace jetfuel */
