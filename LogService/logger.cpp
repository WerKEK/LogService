#include "logger.h"
#include <iostream>
#include <QFile>
#include <QThread>


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
    std::cout<<"Name of log's thread: "<<QThread::currentThreadId()<<std::endl<<std::endl;
    std::cout << std::endl << s.toStdString() << std::endl;
}

void Logger::run(bool w, QString s)
{
    log(w,s);
}

Logger *Logger::getInstance()
{
    static Logger res; //Статик вызывается один раз
    return &res;
}

Logger::Logger()
{
   // std::cout<<"Name of Logger's thread: "<<QThread::currentThreadId()<<std::endl<<std::endl;
}






