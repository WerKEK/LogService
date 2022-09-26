#include <QCoreApplication>
#include <logger.h>
#include <QThread>
#include <controller.h>
#include <QTextStream>


int main(int argc, char *argv[])
{  
    QTextStream cout(stdout);
    QTextStream cin(stdin);
    QCoreApplication a(argc, argv);
    Controller controller;

    cout<<"Enter the message for logs";
    controller.string = cin.readLine();
    cout<<"Do you wanna write logs in file? Y(Yes)/N(No)\n";
    QString res = cin.readLine();
    if(res == "Y")
        controller.isWrittenInFile = true;
    else if(res == "N")
        controller.isWrittenInFile = false;
    else{
        cout<<"Incorrect, try again";
        exit(0);
    }


    controller.thCreator();


    return a.exec();
}
