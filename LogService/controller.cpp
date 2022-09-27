#include "controller.h"
#include <logger.h>
#include <QThread>

Controller::Controller(QObject *parent) : QObject(parent)
{

}

void Controller::doLogs()
{
    //bool w = true;
    //QString s = "123";
    bool w = getIsWrittenFile();
    QString s = getString();
    for(int i = 0;i < 10;i++){
        Logger::getInstance().log(w, s); //Вызов логов
    }
}

void Controller::thCreator()
{
    controller = new Controller();
    QThread* thread = new QThread();
    controller->moveToThread(thread);
    connect(thread, &QThread::started, controller, &Controller::doLogs);
    thread->start();
}

QString Controller::getString()
{
    return string;
}

bool Controller::getIsWrittenFile()
{
    return isWrittenInFile;
}

void Controller::setString(QString value)
{
    string = value;
}

void Controller::setIsWrittenInFile(bool value)
{
    isWrittenInFile = value;
}

