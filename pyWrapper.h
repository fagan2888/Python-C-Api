#ifndef CONFIG_WRAPPER_H
#define CONFIG_WRAPPER_H
#include <Python.h>
#include <string>

class pyWrapper
{
public:
    pyWrapper(std::string module);
    ~pyWrapper();
    PyObject* function(std::string fun);
    std::string attribute(PyObject* o, std::string attr);
    int isList(PyObject* o);

private:
    PyObject* myModule;
};

#endif // CONFIG_WRAPPER_H
