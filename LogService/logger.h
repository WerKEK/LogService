#ifndef LOGGER_H
#define LOGGER_H


class Logger
{
private:
    Logger();

public:
    void log();
    static Logger &getInstance();
};

#endif // LOGGER_H
