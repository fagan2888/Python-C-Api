#ifndef PLUGIN_H
#define PLUGIN_H

#include <QObject>
#include <QProcess>
#include <QStringList>

class Plugin : public QObject
{
    Q_OBJECT
    constexpr static auto SCRIPT_PATH = "../";
    constexpr static auto BINARY = "bin";


public:
    Plugin(QString i, QString p, QString d)
        : interpreter(i)
        , program(p)
        , description(d)
    {
    }

    void run() {
        QProcess runner;
        QString program_path = SCRIPT_PATH + program;

        if(QString::compare(interpreter, BINARY, Qt::CaseInsensitive) == 0) {
            runner.start(program_path);
        }
        else {
            runner.start(interpreter, QStringList() << program_path);
        }

        runner.waitForFinished();
        lastStatus = runner.exitCode();
    }


    QString getDescription()    const { return description;}
    QString getIterpreter()     const { return interpreter;}

    quint8 getLastStatus() const {return lastStatus;}

    static enum TYPE {
        UPDATER     = 0,
        PROCESSING  = 1,
        STORING     = 2,
        INSTALLER   = 3,
        CHECKER     = 4,
        TEST        = 5
    } type;

protected:
    QString interpreter;
    QString program;
    QString description;
    quint8 lastStatus;

};

#endif // PLUGIN_H
