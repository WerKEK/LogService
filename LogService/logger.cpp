#include "logger.h"
#include <iostream>
#include <QFile>
#include <QThread>
#include <QEventLoop>


void Logger::log(bool w, QString s)
{
    QByteArray ba = s.toLocal8Bit();
    const char *c_str = ba.data(); //Преобразование для записи в файл
    if(w){
        QFile file("E:/Projects/logFile.txt");
        file.open(QIODevice::WriteOnly | QIODevice::Append);
        file.write(c_str);
        file.close();
    }
    std::cout<<std::endl<<std::endl<<"Name of log's thread: "<<QThread::currentThreadId()<<std::endl;
    std::cout<< s.toStdString() << std::endl;
}

void Logger::run()
{
    infinityQueue();
}


void Logger::sentData(bool w, QString s)
{
    setIsWrittenInFile(w);
    setString(s);
    if(!getInstance()->isRunning())
        start();
}

void Logger::infinityQueue()
{
    while(true){
        log(isWrittenInFile, string);
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




