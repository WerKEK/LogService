#include <QCoreApplication>
#include <logger.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Logger::getInstance().log();

    return a.exec();
}
