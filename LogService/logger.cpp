#include "logger.h"
#include <QDebug>
#include <QFile>
#include <iostream>
#include <QThread>

Logger::Logger()
{

}

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
    std::cout << std::endl << s.toStdString() << std::endl;
}

Logger &Logger::getInstance()
{
    static Logger res; //Статик вызывается один раз
    return res;
}



