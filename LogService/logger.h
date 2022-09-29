#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>

class Logger
{

private:
    Logger();

public:

    static Logger* getInstance();

public slots:
    void log(bool, QString);

};

#endif // LOGGER_H
