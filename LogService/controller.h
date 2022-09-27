#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT


public:
    Controller* controller;


    explicit Controller(QObject *parent = nullptr);

    void thCreator();

    QString getString();
    bool getIsWrittenFile();
    void setString(QString value);
    void setIsWrittenInFile(bool value);

    void doLogs();

private:
    QString string;
    bool isWrittenInFile;
};

#endif // CONTROLLER_H
