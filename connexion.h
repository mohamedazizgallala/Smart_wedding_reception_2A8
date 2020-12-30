#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>

class Connexion
{ QSqlDatabase db;
public:
    Connexion();
    bool create_cnx();
    void close_cnx();
};

#endif // CONNEXION_H
