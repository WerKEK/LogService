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
    for(int i = 0;i < 10;i++){
        Logger::getInstance()->run(getIsWrittenFile(),getString()); //Вызов логов
    }
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

