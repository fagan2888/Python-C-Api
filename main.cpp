#include <QCoreApplication>
#include <QDebug>
#include <string>
#include <Python.h>
#include <Plugin.h>
#include <pyWrapper.h>

void debug(std::string info) {
    qDebug()<<QString::fromStdString(info);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    pyWrapper wrapper("configuration");

    PyObject* server = wrapper.function("extract_server");
    std::string result = wrapper.attribute(server, "ip");

    debug(result);

    PyObject* plugins = wrapper.function("extract_plugins");
    int list = wrapper.isList(plugins);

    qDebug()<<list;

    return a.exec();
}
