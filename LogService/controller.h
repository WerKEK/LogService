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
    //explicit Controller(QObject *parent = nullptr);

    void thCreator();

    QString getString();
    bool getIsWrittenFile();
    void setString(QString value);
    void setIsWrittenInFile(bool value);

    void doLogs();
    void run();
signals:
    void startLogs(bool, QString);

private:
    QString string;
    bool isWrittenInFile;
};

#endif // CONTROLLER_H
