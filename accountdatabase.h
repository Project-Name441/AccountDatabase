/*
 * Name: Alexander Shershnov
 * File type: Header file/Abstract
 * Last modified: 2/24/2018
 * Notes: Possibly future functionalities -- deleteUser() --- ?
 * See AccountDatabase.cpp for other details
 * */

#ifndef ACCOUNTDATABASE_H
#define ACCOUNTDATABASE_H

#include<QString>
#include<QDir>
#include<iostream>
#include<QDebug>
#include<QVector>
class AccountDatabase
{
public:
    AccountDatabase();
    QString currentAccount(QString username);
    void save();
    bool createNewAccount();
    QString setUserPath(QString username);
    bool load(QString username);
    void takeLoginInfo();
private:
    bool checkLogin(QString username, QString password);
    //QVector <Account>accounts;
};

#endif // ACCOUNTDATABASE_H
