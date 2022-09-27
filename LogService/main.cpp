#include <QCoreApplication>
#include <logger.h>
#include <QThread>
#include <controller.h>
#include <iostream>


int main(int argc, char *argv[])
{  
    QCoreApplication a(argc, argv);
    Controller *controller = new Controller();
    std::string res, str;

    std::cout<<"Enter the message for logs"<<std::endl;
    std::cin>>str;
    QString qString(str.c_str());
    controller->setString(qString);

    std::cout<<std::endl<<"Do you wanna write logs in file? Y(Yes)/N(No)"<<std::endl;
    std::cin>>res;
    if(res == "Y")
        controller->setIsWrittenInFile(true);
    else if(res == "N")
        controller->setIsWrittenInFile(false);
    else{
        std::cout<<"Incorrect, try again"<<std::endl;
        exit(0);
    }

    controller->thCreator();

    std::cout<<std::endl<<"Logging is done"<<std::endl;
    return a.exec();
}
