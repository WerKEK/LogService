#include "controller.h"
#include <logger.h>
#include <QThread>
#include <iostream>

Controller::Controller()
{

}

void Controller::doLogs()
{
    for(int i = 0;i < 10;i++){
        Logger::getInstance()->log(getIsWrittenFile(),getString()); //Вызов логов
        std::cout<<QThread::currentThreadId();
    }
}

//void Controller::thCreator()
//{
//    controller = new Controller();

//    controller->setIsWrittenInFile(isWrittenInFile);
//    controller->setString(string);
//    controller->moveToThread(controller);

//    connect(controller, &Controller::started, controller, &Controller::doLogs);
//    controller->start();
//}

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

