#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QThread>

class Logger : public QThread
{

public:
    static Logger* getInstance();
    void log(bool, QString);
    QThread *th = new QThread();
    void run();


    QString getString();
    bool getIsWrittenFile();
    void setString(QString value);
    void setIsWrittenInFile(bool value);
    void sentData(bool, QString);
    void infinityQueue();

private:
    Logger();
    QString string;
    bool isWrittenInFile;

};

#endif // LOGGER_H
