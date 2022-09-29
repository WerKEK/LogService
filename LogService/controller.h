#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QThread>

class Controller : public QThread
{
    Q_OBJECT


public:
    Controller* controller;

    explicit Controller();


    QString getString();
    bool getIsWrittenFile();
    void setString(QString value);
    void setIsWrittenInFile(bool value);

    void doLogs();
    void run();

private:
    QString string;
    bool isWrittenInFile;
};

#endif // CONTROLLER_H
