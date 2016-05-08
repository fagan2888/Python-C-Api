#include <QCoreApplication>
#include <boost/python.hpp>
#include <Python.h>
#include <string>
#include <Plugin.h>
#include <QDebug>

void simpleFun() {
    PyObject* myModuleString = PyString_FromString((char*)"configuration");
    PyObject* myModule = PyImport_Import(myModuleString);

    PyObject* myFunction = PyObject_GetAttrString(myModule,(char*)"extract_server");
    PyObject* myResult = PyObject_CallFunction(myFunction, NULL);

    std::string server = PyString_AsString(myResult);

    qDebug()<<QString::fromStdString(server);
}

int main(int argc, char *argv[])
{
    namespace python = boost::python;

    QCoreApplication a(argc, argv);

    Py_Initialize();
    PyRun_SimpleString("import sys; sys.path.append('.')");

    simpleFun();

    Py_Finalize();

    return a.exec();
}
