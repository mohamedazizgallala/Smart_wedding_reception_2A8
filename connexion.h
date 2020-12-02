#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connexion
{
    QSqlDatabase db;
public:
    Connexion();
    bool create_cnx();
    void close_cnx();
};

#endif // CONNEXION_H




