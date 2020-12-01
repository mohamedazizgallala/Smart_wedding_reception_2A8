#ifndef CONNECTION_H
#define CONNECTION_H
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSql>
#include <QSqlQueryModel>
#include <QDebug>


class Connection
{
public:
    Connection();
    bool createconnect();
    bool loginconnection(QString,QString);
};



#endif // CONNECTION_H
