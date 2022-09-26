#include "logger.h"
#include <QDebug>
#include <QFile>

Logger::Logger()
{

}

void Logger::log(bool writeFile)
{
    if(writeFile){
        QFile file("E:/Projects/logFile.txt");
        file.open(QIODevice::WriteOnly | QIODevice::Append);
        file.write("Logs was used\n");
        file.close();
    }

    qDebug() << "Logs was used\n";
}

Logger &Logger::getInstance()
{
    static Logger res; //Статик вызывается один раз
    return res;
}

