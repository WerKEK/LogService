#include "controller.h"
#include <logger.h>
#include <QThread>
#include <iostream>

Controller::Controller()
{

}

void Controller::doLogs()
{
    std::cout<<"Name of Controller's thread: "<<QThread::currentThreadId()<<std::endl;
    Logger::getInstance()->sentData(getIsWrittenFile(),getString()); //Вызов логов
}

void Controller::run(){
    doLogs();
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

