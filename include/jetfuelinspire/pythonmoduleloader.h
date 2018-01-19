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

#ifndef JETFUELINSPIRE_PYTHONMODULELOADER_H_
#define JETFUELINSPIRE_PYTHONMODULELOADER_H_

#include <stdio.h>  /* defines FILENAME_MAX */
#ifdef _WIN32
    #include <direct.h>
    #include <Python.h>
    #define GetCurrentDir _getcwd
    #define strdup _strdup
#else
    #include <unistd.h>
    #include <python3.6/Python.h>
    #define GetCurrentDir getcwd
#endif

#include <cstring>
#include <stdexcept>

#include <mutex>

namespace jetfuel {
    namespace inspire {
        namespace exceptions{
            class Python_returnvalue_ASCII_encoding_exception : 
			public std::runtime_error {
            public:
                Python_returnvalue_ASCII_encoding_exception(
									const std::string filename,
									const std::string functionname)
                                    : std::runtime_error("Error encoding return "
									 + "value ASCII in python module "+ filename+
									   " in function "+ functionname){}
            };
			/// \class jetfuel::inspire::exceptions::
			/// Python_returnvalue_ASCII_encoding_exception
			///
			/// An exception thrown by Python_module_loader if the 
			/// return value from a Python function is not ASCII 
			/// encoded. Jetfuel does not currently support non-ASCII 
			/// Python function return values.
			///
			/// \see jetfuel::inspire::Python_module_loader
        }

        class Python_class_loader;

        class Python_module_loader {
        public:
            /// \brief Constructs a Python_module_loader using 
            /// a file-name, a functionname, the directory, and, 
			/// optionally a file to replace the former.
            ///
            /// Constructs a Python_module_loader using a file-name, a
			/// functionname, the directory(set to "." by default),
            /// and, optionally a file to replace the former.
            /// If you chose to use the file to replace functionality,
            /// the default file will be run first, and then the file
			/// to replace will be run second, overriding the first
            /// file return value and any Python variables or 
			/// assignments.
            ///
            /// This is handy as a failsafe for a mod system, because 
			/// if the mod file fails, the game can continue normally,
            /// using the internal one function as a failsafe.
            ///
            /// \param std::string filename
            /// \param std::string functionname
            /// \param std::string directoryoffilename
            /// \param std::string filetoreplace
            /// \param std::string directoryoffiletoreplace
            Python_module_loader(const std::string filename, 
								 const std::string functionname,
                                 const std::string directoryoffilename = ".",
                                 const std::string filetoreplace = "",
                            const std::string directoryoffiletoreplace = ".");

            /// \brief Constructs a Python_module_loader that will load
			///  a function from a class.
            ///
            /// Constructs a Python_module_loader that will load a 
			/// function from a class. This acts like any other 
			/// Python_module_loader, despite the function being from a
			/// class.
            ///
            /// \param jetfuel::inspire::Python_class_loader 
			///  *pythonclasstouse
            /// \param std::string functionname
            Python_module_loader(
			  jetfuel::inspire::Python_class_loader *pythonclasstouse, 
			  const std::string functionname);

            /// \brief Virtual destructor
            ///
            /// Destroys this Python_module_loader.
			virtual ~Python_module_loader();

			/// \brief Executes this Python module without any return
			/// type.
			///
			/// Executes this Python module without any return
			/// type. If there are no Python arguments, you can just
			/// pass NULL/nullptr to the last argument of this 
			/// function.
			///
			/// \param bool *executed
			/// \param std::string *error
			/// \param PyObject *args
            void Execute(bool *executed, std::string *error, 
						PyObject *args);

			/// \brief Executes this Python module with a boolean 
			/// return type.
			///
			/// Executes this Python module with a boolean return 
			/// type. If there are no Python arguments, you can just
			/// pass NULL/nullptr to the last argument of this 
			/// function.
			///
			/// \param bool *executed
			/// \param std::string *error
			/// \param PyObject *args
            bool Execute_bool(bool *executed, std::string *error, 
				              PyObject *args);
			
			/// \brief Executes this Python module with a long return 
			/// type. 
			///
			/// Executes this Python module with a long return 
			/// type. If there are no Python arguments, you can just
			/// pass NULL/nullptr to the last argument of this 
			/// function. This serves as the way to also get an int 
			/// return type. After you get the long, just convert it to
			/// an int.
			///
			/// \param bool *executed
			/// \param std::string *error
			/// \param PyObject *args
            long Execute_long(bool *executed, std::string *error, 
							  PyObject *args);

			/// \brief Executes this Python module with a double return 
			/// type. 
			///
			/// Executes this Python module with a double return 
			/// type. If there are no Python arguments, you can just
			/// pass NULL/nullptr to the last argument of this 
			/// function. This serves as the way to also get an float
			/// return type. After you get the double, just convert it
			/// to a float.
			///
			/// \param bool *executed
			/// \param std::string *error
			/// \param PyObject *args
            double Execute_double(bool *executed, std::string *error, 
								  PyObject *args);

			/// \brief Executes this Python module with a cstring return 
			/// type. 
			///
			/// Executes this Python module with a cstring return 
			/// type. If there are no Python arguments, you can just
			/// pass NULL/nullptr to the last argument of this 
			/// function. This serves as the way to also get an 
			/// std::string return type. After you get the long, just
			/// convert it to a std::string.
			///
			/// \param bool *executed
			/// \param std::string *error
			/// \param PyObject *args
			char *Execute_cstring(bool *executed, std::string *error, 
								 PyObject *args);

			/// \brief Converts a Python error message to a 
			/// std::string.
			///
			/// Converts a Python error message to a 
			/// std::string.
			///
			/// \param PyObject *pythonerrortype
			/// \param PyObject *pythonerrorvalue
			/// \param PyObject *pythonerrortraceback
            static std::string Py_err_to_string(PyObject *pythonerrortype, 
				PyObject *pythonerrorvalue, PyObject *pythonerrortraceback);


			/// \brief Adds a given directory path to the python path.
			///
			/// Adds a given directory path to the python path.
			///
			/// \param std::string pathlocationtoadd
            static void Add_to_py_path(const std::string pathlocationtoadd);
        protected:
            PyObject *pythonclass; ///< A Python class object used to 
								   ///< call Python class methods.

			/// \brief Sets up Python function objects for execution.
			///
			/// Sets up Python function objects for execution.
			///
			/// \param PyObject *pythonfunction
			/// \param PyObject *args
			/// \param bool *executed
			/// \param std::string *error
            void Base_execute_py_object(PyObject *pythonfunction, 
				                        PyObject *args, bool *executed,
										std::string *error);

			/// \brief Executes a python function without a return
			/// type.
			///
			/// Executes a python function without a return type.
			///
			/// \param PyObject *args
			/// \param bool *executed
			/// \param std::string *error
            void Execute_py_object(PyObject *args,bool *executed, 
									std::string *error);

			/// \brief Executes a python function with a boolean return
			/// type.
			///
			/// Executes a python function with a boolean return type.
			///
			/// \param PyObject *args
			/// \param bool *executed
			/// \param std::string *error
            bool Execute_py_object_bool(PyObject *args, bool *executed, 
										std::string *error);

			/// \brief Executes a python function with a long return
			/// type.
			///
			/// Executes a python function with a long return type.
			///
			/// \param PyObject *args
			/// \param bool *executed
			/// \param std::string *error
            long Execute_py_object_long(PyObject *args, bool *executed, 
										std::string *error);

			/// \brief Executes a python function with a double return
			/// type.
			///
			/// Executes a python function with a double return type.
			///
			/// \param PyObject *args
			/// \param bool *executed
			/// \param std::string *error
            double Execute_py_object_double(PyObject *args,bool *executed, 
											std::string *error);

			/// \brief Executes a python function with a cstring return
			/// type.
			///
			/// Executes a python function with a cstring return type.
			///
			/// \param PyObject *args
			/// \param bool *executed
			/// \param std::string *error
            char* Execute_py_object_cstring(PyObject *args, bool *executed, 
											std::string *error);

            /*static void Lock_python_operations_mutex(){
                m_pythonoperationsmutex.lock();
            }

            static void Unlock_python_operations_mutex(){
                m_pythonoperationsmutex.unlock();
            }*/

			/// \brief Gets this Python file name.
			///
			/// Gets this Python file name.
            std::string Get_file_name() const {
                return m_filename;
            }

			/// \brief Gets this Python file name of the file to 
			/// replace.
			///
			/// Gets this Python file name of the file to 
			/// replace.
            std::string Get_file_to_replace() const {
                return m_filetoreplace;
            }

			/// \brief Gets this Python function name.
			///
			/// Gets this Python function name.
            std::string Get_function_name() const {
                return m_functionname;
            }

			/// \brief Converts a const char * to a wchar_t *.
			///
			/// Converts a const char * to a wchar_t *.
			///
			/// \param const char *chartouse
            static wchar_t *Get_wchar(const char *chartouse)
            {
                const size_t charsize = strlen(chartouse)+1;
                wchar_t* widechar = new wchar_t[charsize];
                mbstowcs (widechar, chartouse, charsize);

                return widechar;
            }

			/// \brief Gets this directory name of the Python files.
			///
			/// Gets this directory name of the Python files.
            std::string Get_directory_of_file_name() const {
                return m_directoryoffilename;
            }

			/// \brief Gets this directory name of the Python files
			/// to replace.
			///
			/// Gets this directory name of the Python files to 
			/// replace.
            std::string Get_directory_of_file_to_replace() const {
                return m_directoryoffiletoreplace;
            }

			/// \brief Returns a boolean whether this 
			/// Python_module_loader is invoking class methods.
			///
			/// Returns a boolean whether this 
			/// Python_module_loader is invoking class methods.
            bool Using_classes() const {
                return m_usingclasses;
            }

			/// \brief Converts an ASCII wchar_t * to an ASCII 
			/// std::string.
			///
			/// Converts an ASCII wchar_t * to an ASCII 
			/// std::string.
			///
			/// \param wchar_t* widechar
            static const std::string Get_string(const wchar_t *widechar){
                std::wstring widestring = widechar;
                return std::string(widestring.begin(),widestring.end());
            }

			static std::string Get_py_error(PyObject *errorobject);
        private:
            //static std::mutex m_pythonoperationsmutex;

            static bool m_pythoninited; ///< Whether Python has been 
										///< initialized.

            bool m_usingclasses; ///< Whether this 
								 ///< Python_module_loader is invoking
								 ///< class methods.

            std::string m_filename; ///< Python file name.
            std::string m_functionname; ///< Python function name.
            std::string m_filetoreplace; ///< Python file to replace 
										 ///< name.
            std::string m_directoryoffilename; ///< Directory name of 
											   ///< Python files.
            std::string m_directoryoffiletoreplace; ///< Directory name
													///< of Python 
													///< files to 
													///< replace.
        };

        /// \class sjetfuel::inspire::Python_module_loader
        ///
        /// Loads a Python 3.6 function(Not a class) to be executed.
        /// This function can be executed, and can have
        /// arguments passed through it via a tuple in a PyObject*.
        ///
        /// The python function can return nothing, a bool,
        /// a int(to be converted to a long),
        /// a float(to be converted to double),
        /// or a String (to be converted to a Cstring(or a char*),
        /// which can be implicitly be converted to a std::string).
        ///
        /// Note that the filename cannot have a .py extension, it can only
        /// have it's own name.
        ///
        /// Code Example:
        ///     jetfuel::inspire::Python_module_loader sumof1plus1loader = jetfuel::inspire::Python_module_loader(
        ///     "adder","whatdoes1+1equal",
        ///     "./Scripts");
        ///
        ///     bool executionstatus;
        ///     std::string error;
        ///
        ///     long sumof1plus1 = sumof1plus1loader.Execute_long(&executionstatus,&error,NULL);
        ///     // NULL = No arguments to pass
        ///
        ///     if(!executionstatus){
        ///         // Not executed... See what's wrong.
        ///         std::cout << "Python execution error! Error was:" << error << std::endl;
        ///     }else{
        ///         std::cout << "Sum was:" << std::to_string(sumof1plus1) << std::endl;
        ///     }

    } /* namespace inspire */
} /* namespace jetfuel */

#endif /* JETFUELINSPIRE_PYTHONMODULELOADER_H_ */
