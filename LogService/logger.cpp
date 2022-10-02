#include "logger.h"
#include <iostream>
#include <QFile>
#include <QThread>


void Logger::log(bool w, QString s)
{
    QByteArray ba = s.toLocal8Bit();
    const char *c_str = ba.data(); //Преобразование для записи в файл
    for(int i = 0; i< 10; i++){
        if(w){
            QFile file("E:/Projects/logFile.txt");
            file.open(QIODevice::WriteOnly | QIODevice::Append);
            file.write(c_str);
            file.close();
        }
        std::cout<<"Name of log's thread: "<<QThread::currentThreadId()<<std::endl<<std::endl;
        std::cout << std::endl << s.toStdString() << std::endl;
    }
}

void Logger::run()
{
    log(getIsWrittenFile(), getString());
}


void Logger::sentData(bool w, QString s)
{
    setIsWrittenInFile(w);
    setString(s);
    start();
}

void Logger::startLogs()
{
    if(!getInstance()->isRunning()){
        getInstance()->exec();
        std::cout<<"Name of started thread: "<<QThread::currentThreadId()<<std::endl<<std::endl;
        log(getIsWrittenFile(),getString());
    }
}

Logger *Logger::getInstance()
{

    static Logger res; //Статик вызывается один раз
    return &res;
}

Logger::Logger()
{

}


QString Logger::getString()
{
    return string;
}

bool Logger::getIsWrittenFile()
{
    return isWrittenInFile;
}

void Logger::setString(QString value)
{
    string = value;
}

void Logger::setIsWrittenInFile(bool value)
{
    isWrittenInFile = value;
}




