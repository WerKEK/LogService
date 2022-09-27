#ifndef LOGGER_H
#define LOGGER_H
#include <QObject>

class Logger
{

private:
    Logger();

public:
    void log(bool &isWriteFile, QString &str);
    static Logger &getInstance();


public slots:
    void start();

signals:
    void started();
};

#endif // LOGGER_H
