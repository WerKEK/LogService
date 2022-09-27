#include "logger.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
QTextStream cout(stdout);
QTextStream cin(stdin);

Logger::Logger()
{

}

void Logger::log(bool &writeFile, QString &str)
{
    QByteArray ba = str.toLocal8Bit();
    const char *c_str = ba.data(); //Преобразование для записи в файл


    if(writeFile){
        QFile file("E:/Projects/logFile.txt");
        file.open(QIODevice::WriteOnly | QIODevice::Append);
        file.write(c_str);
        file.close();
    }

    cout << str + "\n";
}

Logger &Logger::getInstance()
{
    static Logger res; //Статик вызывается один раз
    return res;
}


