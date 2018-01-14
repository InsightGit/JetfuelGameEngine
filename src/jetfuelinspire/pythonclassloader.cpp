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

#include "pythonclassloader.h"

namespace jetfuel {
    namespace inspire {
        void Python_class_loader::Base_execute_py_function(
													PyObject *pythonfunction, 
														   PyObject *args, 
														   bool *executed,
                                                           std::string *error){
			// Checks that the function does not equal nullptr,
			// tries to find the function, then marks this function as 
			// executed if no error. Otherwise, marks it as not
			// executed.

			PyObject *pythonerrortype;
			PyObject *pythonerrorvalue;
			PyObject *pythonerrortraceback;

            if(pythonfunction==nullptr){
                PyErr_Fetch(&pythonerrortype, &pythonerrorvalue, 
							&pythonerrortraceback);

                *error = Python_module_loader::Py_err_to_cstring(pythonerrortype,
										pythonerrorvalue,pythonerrortraceback);
                *executed = false;
                return;
            }
            if(!PyCallable_Check(pythonfunction)){
                PyErr_Fetch(&pythonerrortype, &pythonerrorvalue, 
							&pythonerrortraceback);

                *executed = false;
				*error = Python_module_loader::Py_err_to_cstring(pythonerrortype,
					pythonerrorvalue, pythonerrortraceback);
                return;
            }
            *executed=true;
        }

        Python_class_loader::Python_class_loader(PyObject *constructorargs,
												std::string *filename, 
												std::string *classname, 
												bool *executed, 
												std::string *error,
                                              std::string *directoryoffilename) {
			// Initialize Python, Add the python file directory to the
			// python path, runs the function through some error 
			// checking, then tries to call the constuctor, and checks 
			// for any errors.

            Py_Initialize();

            Python_module_loader::Add_to_py_path(*directoryoffilename);

			PyObject *pythonfile = PyUnicode_DecodeFSDefault(filename->c_str());
			PyObject *pythonmodule = PyImport_Import(pythonfile);
			PyObject *pythonfunction = PyObject_GetAttrString(pythonmodule,
															classname->c_str());

            Base_execute_py_function(pythonfunction,constructorargs,executed,
									 error);

            if(!*executed){
                return;
            }

            pythonclass = PyObject_CallObject(pythonfunction,constructorargs);

            PyObject *pythonerrortype, *pythonerrorvalue, *pythonerrortraceback;
            PyErr_Fetch(&pythonerrortype, &pythonerrorvalue, 
						&pythonerrortraceback);

            if(pythonerrortype==NULL){
                *executed = true;
            }else{
                *error = Python_module_loader::Py_err_to_cstring(pythonerrortype,
										pythonerrorvalue,pythonerrortraceback);
                *executed = false;
            }
        }

        Python_class_loader::Python_class_loader(Python_class pythonclasstouse,
                                                 bool *executed,
                                                 std::string *error){
			// Initialize Python, Add the python file directory to the
			// python path, runs the function through some error 
			// checking, then tries to call the constuctor, and checks 
			// for any errors.

            Py_Initialize();

            Python_module_loader::Add_to_py_path(
								pythonclasstouse.directoryoffilename);

			PyObject *pythonfile = PyUnicode_DecodeFSDefault(
								pythonclasstouse.filename.c_str());
			PyObject *pythonmodule = PyImport_Import(pythonfile);
			PyObject *pythonfunction = PyObject_GetAttrString(pythonmodule,
											pythonclasstouse.classname.c_str());

            Base_execute_py_function(pythonfunction,
									 pythonclasstouse.constructorargs,
                                     executed,error);

            if(!*executed){
                return;
            }

            pythonclass = PyObject_CallObject(pythonfunction,
                                              pythonclasstouse.constructorargs);

			PyObject *pythonerrortype;
			PyObject *pythonerrorvalue;
			PyObject *pythonerrortraceback;

            PyErr_Fetch(&pythonerrortype, &pythonerrorvalue,
                       &pythonerrortraceback);

            if(pythonerrortype==NULL){
                *executed = true;
            }else{
                *error = Python_module_loader::Py_err_to_cstring(
													pythonerrortype,
                                                    pythonerrorvalue,
                                                    pythonerrortraceback);
                *executed = false;
            }
        }

        Python_class_loader::~Python_class_loader() {
            Py_Finalize();
        }
    } /* namespace inspire */
} /* namespace jetfuel */
