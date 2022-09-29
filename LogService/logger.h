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
    void run(bool, QString);

private:
    Logger();

};

#endif // LOGGER_H
