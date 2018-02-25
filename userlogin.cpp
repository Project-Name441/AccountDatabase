
/*
Name: Alexander Shershnov
Type: Login cpp file
Last modified: 2/24/2018
*/


#include "userlogin.h"
#include<QTextStream>

//Default constructor
UserLogin::UserLogin()
{
    username = "";
    password = "";
}

bool UserLogin::checkUsernameAndPassword(QString username, QString password)const
{
    //Get to the Users directory
    QDir directory;
    directory.setPath(directory.currentPath());
    directory.cdUp();
    directory.cd("Users");

    //Check if path exists in users
    if(directory.exists(username))
    {
        directory.cd(username);
        QFile file(directory.filePath("password.txt"));

        if(!file.open(QIODevice::ReadOnly))
        {
            return false;
        }
        QTextStream in(&file);
        QString userPassword;
        userPassword = in.readLine();
        //Invoke the password file and check for match
        if(password == userPassword)
        {//If user and password matches, return true
            file.close();
            return true;
        }
    }
    return false;
}
