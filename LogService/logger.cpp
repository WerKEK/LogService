#include "logger.h"
#include <QDebug>
#include <QFile>
#include <iostream>


Logger::Logger()
{

}

void Logger::log(bool &isWriteFile, QString &str)
{
    QByteArray ba = str.toLocal8Bit();
    const char *c_str = ba.data(); //Преобразование для записи в файл


    if(isWriteFile){
        QFile file("E:/Projects/logFile.txt");
        file.open(QIODevice::WriteOnly | QIODevice::Append);
        file.write(c_str);
        file.close();
    }

    std::cout << std::endl << str.toStdString() << std::endl;
}

Logger &Logger::getInstance()
{
    static Logger res; //Статик вызывается один раз
    return res;
}


