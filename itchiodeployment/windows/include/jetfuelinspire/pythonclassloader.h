/*
* Jetfuel Game Engine- A SDL-based 2D game-engine
* Copyright (C) 2017 InfernoStudios
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

        class Python_class_loader {
        public:
            Python_class_loader(PyObject *constructorargs, std::string *filename,
                                std::string *classname, bool *executed, std::string *error,
                                std::string *directoryoffilename);

            Python_class_loader(Python_class pythonclass, bool *executed,
                                std::string *error);

            virtual ~Python_class_loader();

            PyObject *pythonclass;

        private:
            void Base_execute_py_function(PyObject *pythonfunction, PyObject *args, bool *executed,
                                          std::string *error);

            const wchar_t *Get_wchar(const char *chartouse)
            {
                const size_t charsize = strlen(chartouse)+1;
                wchar_t* widechar = new wchar_t[charsize];
                mbstowcs (widechar, chartouse, charsize);

                return widechar;
            }
        };
    } /* namespace inspire */
} /* namespace jetfuel */

#endif /* JETFUELINSPIRE_PYTHONCLASSLOADER_H_ */
