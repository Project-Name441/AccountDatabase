
/*
 * Name: Alexander Shershnov
 * File type: Implementation file
 * Last modified: 2/24/2018
 * Notes: Functions save(), createNewAccount() and takeLoginInfo() are a future subject to change upon the integration with UI. This is a prototype to test out future functions.
 * Private variables, such as QVector <Account> accounts, may also be a subject to change in the future.
 * */

#include "accountdatabase.h"

QDir directory;

AccountDatabase::AccountDatabase()
{

}
void AccountDatabase::save()
{
    //Probably something like this
    //Account *c_account = new Account();
    //c_account -> setBudget(int budget);
    //c_account -> setSavings(int savings);
    //c_account -> setSpendings(int spendings);
}

//Function: If a user wants to create new Account, we create a new directory for the name
//and a new file for password
//Parameters: None
bool AccountDatabase::createNewAccount()
{
    QString username = "TestUser";
    directory.cdUp();
    directory.cd("Users");
    if(directory.exists(username))
    {
        //std::cout<<"ERROR.DIRECTORY ALREADY EXISTS"<<std::endl;
        return false;
    }
    else
    {
        if(directory.mkdir(username))
        {
            directory.cd(username);
            //Take in user's password and store it in QString of appropriate account pwd
            QString filename = "/password.txt";
            QFile file(directory.path() + filename);
            if(file.open(QIODevice::WriteOnly))
            {
                QString userEnteredString;
                QTextStream out(&file);
                out << userEnteredString;
                file.close();
            }
            return true;
        }
        return false;
    }

}


//Function: Return the directory of the user
//Parameters: QString username
QString AccountDatabase::currentAccount(QString username)
{
    directory.setPath(directory.currentPath());
    directory.cdUp();
    directory.cd("Users");
    directory.cd(username);
    return directory.path();
}

//Functions: Loads all the attributes from a userData file and disburses them accordingly
//Parameters: QString username is the only parameter to find out which user file we need to access
bool AccountDatabase::load(QString username)
{
    QString path = currentAccount(username); //Access username's folder
    QFile file(directory.filePath("userData.txt")); //Open the file containing username information

    if(!file.open(QIODevice::ReadOnly))//Make sure the data read from a file is read only
    {
        std::cout<<"Error. File not found."<<std::endl;
        return false;
    }

    QTextStream in(&file);
    QString tempLine;
    while(!in.atEnd())
    {//Read in all information from user
        //Account.setBudget(in.readLine());
        tempLine = in.readLine();
        std::cout<<tempLine.toStdString()<<std::endl;
    }
    file.close();
    return true;
}

//Function: Takes in login information that users enters.
//Parameters: So far, none. Possibly a subject to change in future
void AccountDatabase::takeLoginInfo()
{
    QString username = "JonDoe", password = "blahblahblah";
    if(checkLogin(username, password))
        load(username);//Load the directory and create an account object
    createNewAccount();
}

//Function: Checks whether the user entered username and password exist and returns to the caller
//Parameters: QString username and QString password
bool AccountDatabase::checkLogin(QString username, QString password)
{
    //Get access to Users directory that contains names of all users
    directory.cdUp();
    directory.cd("Users");
    //Check if the username already exists, if so proceed as per protocol
    if(directory.exists(username))
    {
        //Find the file containing the password
        QString userPath = currentAccount(username);
        QFile file(userPath + "/password.txt");
        //Open the file, make sure it's ready only
        if(!file.open(QIODevice::ReadOnly))
        {
            return false;
        }
        //Read in the information from that file, store in temp QString
        QTextStream in(&file);
        QString tempPassword = in.readLine();
        //Check if the user-entered password matches
        if(tempPassword == password)
        {
            file.close();
            return true;
        }
    }
    return false;

}
