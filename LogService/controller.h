#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT


public:
    Controller* controller;
    QString string;
    bool isWrittenInFile;
    explicit Controller(QObject *parent = nullptr);
    void doLogs();
    void thCreator();

signals:

};

#endif // CONTROLLER_H
