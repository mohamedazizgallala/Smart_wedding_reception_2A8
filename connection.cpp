#include "connection.h"

//test gittt

Connection::Connection()
{

}

bool Connection::createconnect()
{ bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet");//inserer le nom de la source de données ODBC
db.setUserName("wissal");//inserer nom de l'utilisateur
db.setPassword("wissal19");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
   return  test;
}

bool Connection::loginconnection(QString username, QString password){
    bool connected = false;
    QSqlQuery query(QSqlDatabase::database("projet"));
    query.prepare(QString("SELECT * FROM EMPLOYEES_LOGIN WHERE ID =:username AND PASSWORD =:password"));
    query.bindValue(":username",username);
    query.bindValue(":password",password);
    query.first();
    if(!query.exec()){qDebug() <<"failed exec";}
    else{
        while(query.next()){
            QString usernameFromDB=query.value(0).toString();
            QString passwordFromDB=query.value(1).toString();
            if ((usernameFromDB == username )&& (passwordFromDB == password))connected = true;
            }
    }
    return connected;
}
