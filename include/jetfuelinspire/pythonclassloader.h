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


#ifndef JETFUELINSPIRE_PYTHONCLASSLOADER_H_
#define JETFUELINSPIRE_PYTHONCLASSLOADER_H_

#ifdef _WIN32
    #include <Python.h>
#else
    #include <python3.6/Python.h>
#endif

#include <jetfuelinspire/pythonmoduleloader.h>

namespace jetfuel {
    namespace inspire {
        struct Python_class{
            PyObject *constructorargs;
            std::string filename;
            std::string classname;
            std::string directoryoffilename;
        };
		/// \struct jetfuel::inspire::Python_class
		///
		/// A simple struct representing a Python class.
		///
		/// \see jetfuel::inspire::Python_class_loader

        class Python_class_loader {
        public:
			/// \brief Constructs a simple Python class by constructing
			/// a Python object given to this function(without using 
			/// the Python_class struct.
			///
			/// Constructs a simple Python class by constructing
			/// a Python object given to this function(without using 
			/// the Python_class struct).
			///
			/// \param PyObject *constructorargs
			/// \param std::string *filename
			/// \param std::string *classname
			/// \param bool *executed
			/// \param std::string *error
			/// \param std::string *directoryoffilename
            Python_class_loader(PyObject *constructorargs, std::string *filename,
                                std::string *classname, bool *executed,
								std::string *error,
                                std::string *directoryoffilename);

			/// \brief Constructs a simple Python class by constructing
			/// a Python object given to this function(using the 
			/// Python_class struct).
			///
			/// Constructs a simple Python class by constructing
			/// a Python object given to this function(using 
			/// Python_class struct).
			///
			/// \param Python_class pythonclass
			/// \param bool *executed
			/// \param std::string *error
            Python_class_loader(Python_class pythonclass, bool *executed,
                                std::string *error);

			/// \brief Virtual Destructor.
			///
			/// Destroys this Python_class_loader object.
            virtual ~Python_class_loader();

            PyObject *pythonclass; ///< The object representing the 
								   ///< Python class.
        private:
			/// \brief Executes a Python function using 
			/// jetfuel::inspire::Python_module_loader.
			///
			/// Executes a Python function using 
			/// jetfuel::inspire::Python_module_loader.
			///
			/// \param PyObject *pythonfunction
			/// \param PyObject *args
			/// \param bool *executed
			/// \param std::string *error
            void Base_execute_py_function(PyObject *pythonfunction, 
										  PyObject *args, bool *executed,
										  std::string *error);
			/// \brief Converts a const char * to a const wchar_t *.
			///
			/// Converts a const char * to a const wchar_t *.
			///
			/// \param const char *chartouse
            const wchar_t *Get_wchar(const char *chartouse)
            {
                const size_t charsize = strlen(chartouse)+1;
                wchar_t* widechar = new wchar_t[charsize];
                mbstowcs (widechar, chartouse, charsize);

                return widechar;
            }
        };
		/// \class jetfuel::inspire::Python_class_loader
		///
		/// A Python class loader that allows you to
		/// mainuplate Python class from C++.
		///
		/// Code Example:
		///
		/// Python(classexample.py):
		///
		/// \code
		///	class classexample:
		///		def __init__(self) :
		///			print("classexample inited!");
		///		def sayhello(self, name) :
		///			print("Hello" + name);
		///	\endcode
		///
		/// C++:
		///	\code
		///  	bool executedstatus;
		///     std::string fileandclassname = "classexample";
		///		std::string directory = "./Scripts";    
		///
		///
		///		jetfuel::inspire::Python_class_loader classloader(nullptr, 
		///								&fileandclassname,&fileandclassname,
		///								&executedstatus, &error, &directory);
		///  
		///	    if(!executedstatus){
		///			std::cout << "Python Interpreter ERROR! Error is:" << error
		///         << std::endl;
		///		}
		///
		///     jetfuel::inspire::Python_module_loader classfunction(
		///                             &classloader,std::string("sayhello"));
		///	    executedstatus = bool();
		///
		///		bool returnvalue = classfunctiontester.Execute_bool(
		///											&executedstatus, &error, 
		///						PyTuple_Pack(1, PyUnicode_FromString("G'day")));
		///		if (!executedstatus) {
		///			std::cout << "Python Interpreter ERROR! Error is:" << 
		///			error << std::endl;
		///		}
		/// \endcode
    } /* namespace inspire */
} /* namespace jetfuel */

#endif /* JETFUELINSPIRE_PYTHONCLASSLOADER_H_ */
