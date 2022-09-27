#include <QCoreApplication>
#include <logger.h>
#include <QThread>
#include <controller.h>
#include <iostream>
#include <windows.h>


int main(int argc, char *argv[])
{  
    QCoreApplication a(argc, argv);
    Controller *controller = new Controller();
    std::string res;

    std::string str;
    bool wif;

    std::cout<<"Enter the message for logs"<<std::endl;
    std::cin>>str;
    QString qString(str.c_str()); //Считываю строку для логов и перевожу её в кстринг


    std::cout<<std::endl<<"Do you wanna write logs in file? Y(Yes)/N(No)"<<std::endl;
    std::cin>>res; //Считываю строку, записывать в файл или нет
    if(res == "Y"){
        //controller->setIsWrittenInFile(true); //Перевод в бул
        wif = true;
    }
    else if(res == "N"){
        //controller->setIsWrittenInFile(false);
        wif = false;
    }
    else{
        std::cout<<"Incorrect, try again"<<std::endl;
        exit(0);
    }

    controller->setString(qString);
    controller->setIsWrittenInFile(wif);
    controller->thCreator();
    std::cout<<std::endl<<"Logging is done"<<std::endl;
    return a.exec();
}
