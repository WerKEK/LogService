#include <QCoreApplication>
#include <logger.h>
#include <QTextStream>
#include <QTextStream>
#include <QThread>
#include <controller.h>
QTextStream cout(stdout);
QTextStream cin(stdin);



int main(int argc, char *argv[])
{  
    QCoreApplication a(argc, argv);


    Controller controller;
    controller.thCreator();





//    QString res;

//    cout<<"Do you wanna write logs in file? Y(Yes)/N(No)\n";
//    res = cin.readLine();

//    if(res == "Y")
//        writeFile = true;
//    else if(res == "N")
//        writeFile = false;
//    else
//        cout<<"Incorrect, try again";



    return a.exec();
}
