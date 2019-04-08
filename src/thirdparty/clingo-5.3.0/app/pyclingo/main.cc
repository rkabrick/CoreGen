// {{{ MIT License

// Copyright 2017 Roland Kaminski

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

// }}}

// NOTE: the python header has a linker pragma to link with python_d.lib
//       when _DEBUG is set which is not part of official python releases
#if defined(_MSC_VER) && defined(_DEBUG) && !defined(CLINGO_UNDEF__DEBUG)
#undef _DEBUG
#include <Python.h>
#define _DEBUG
#else
#include <Python.h>
#endif

#include <pyclingo.h>

#if defined  _WIN32 || defined __CYGWIN__
#    define VISIBILITY_DEFAULT __declspec (dllexport)
#else
#    if __GNUC__ >= 4
#        define VISIBILITY_DEFAULT  __attribute__ ((visibility ("default")))
#    else
#        define VISIBILITY_DEFAULT
#    endif
#endif

#if PY_MAJOR_VERSION >= 3
extern "C" VISIBILITY_DEFAULT PyObject *PyInit_clingo() {
    clingo_register_python_();
    return (PyObject*)clingo_init_python_();
}
#else
extern "C" VISIBILITY_DEFAULT void initclingo() {
    clingo_register_python_();
    clingo_init_python_();
}
#endif

