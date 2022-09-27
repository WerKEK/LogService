#ifndef LOGGER_H
#define LOGGER_H
#include <QObject>

class Logger
{

private:
    Logger();

public:
    void log(bool w, QString s);
    static Logger &getInstance();

};

#endif // LOGGER_H
