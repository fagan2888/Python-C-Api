#include "pyWrapper.h"

pyWrapper::pyWrapper(std::string module)
{
    Py_Initialize();
    PyRun_SimpleString("import sys; sys.path.append('.')");

    PyObject* myModuleString = PyString_FromString((char*)module.c_str());
    myModule = PyImport_Import(myModuleString);
}

pyWrapper::~pyWrapper()
{
    Py_Finalize();
}

PyObject* pyWrapper::function(std::string fun)
{
    PyObject* myFunction = PyObject_GetAttrString(myModule,(char*)fun.c_str());
    PyObject* object = PyObject_CallFunction(myFunction, NULL);

    return object;
}

std::string pyWrapper::attribute(PyObject *o, std::string attr)
{
    PyObject* pyattr = PyObject_GetAttrString(o, (char*)attr.c_str());
    std::string stringAttr = PyString_AsString(pyattr);

    return stringAttr;
}

int pyWrapper::isList(PyObject *o)
{
    return PyList_Check(o);
}
