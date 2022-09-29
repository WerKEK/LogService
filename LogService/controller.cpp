#include "controller.h"
#include <logger.h>
#include <QThread>
#include <iostream>

Controller::Controller(QObject *parent) : QObject(parent)
{

}

void Controller::doLogs()
{
    bool w = getIsWrittenFile();
    QString s = getString();
    for(int i = 0;i < 10;i++){
        Logger::getInstance().log(w,s); //Вызов логов
        std::cout<<QThread::currentThreadId();
    }
}

void Controller::thCreator()
{
    controller = new Controller();
    controller->setIsWrittenInFile(isWrittenInFile);
    controller->setString(string);
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

