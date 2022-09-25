#include "logger.h"
#include <QDebug>
#include <QFile>

Logger::Logger()
{

}

void Logger::log()
{
    QFile file("E:/Projects/logFile.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    file.write("Logs was used");
    file.close();

    qDebug() << "Logs was used";
}

Logger &Logger::getInstance()
{
    static Logger res; //Статик вызывается один раз
    return res;
}

