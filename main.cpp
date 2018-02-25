#include <QCoreApplication>

#include"accountdatabase.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    AccountDatabase Database;
    Database.takeLoginInfo();
    return a.exec();
}
