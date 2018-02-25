#ifndef USERLOGIN_H
#define USERLOGIN_H

#include<QString>
#include<QDir>
#include<iostream>
#include<QFile>

class UserLogin
{
public:
    UserLogin();
    bool checkUsernameAndPassword(QString username, QString password)const;
private:
    QString username;
    QString password;
};

#endif // USERLOGIN_H
