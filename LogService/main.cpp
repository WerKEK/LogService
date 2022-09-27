#include <QCoreApplication>
#include <logger.h>
#include <QThread>
#include <controller.h>
//#include <QTextStream>
#include <iostream>


int main(int argc, char *argv[])
{  
//    QTextStream cout(stdout);
//    QTextStream cin(stdin);
    QCoreApplication a(argc, argv);
    Controller controller;
    std::string res, str;

    std::cout<<"Enter the message for logs"<<std::endl;
    std::cin>>str;
    QString qString(str.c_str());
    controller.string = qString;

    std::cout<<std::endl<<"Do you wanna write logs in file? Y(Yes)/N(No)"<<std::endl;
    std::cin>>res;
    if(res == "Y")
        controller.isWrittenInFile = true;
    else if(res == "N")
        controller.isWrittenInFile = false;
    else{
        std::cout<<"Incorrect, try again"<<std::endl;
        exit(0);
    }

    controller.thCreator();

    std::cout<<std::endl<<"Logging is done"<<std::endl;
    return a.exec();
}
