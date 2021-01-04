#include "connexion.h"

Connexion::Connexion()
{

}
bool Connexion::create_cnx() {

    bool test=false;
    db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet");
    db.setUserName("wissal");
    db.setPassword("wissal19");
    if (db.open()) test=true;
    return test;
}
void Connexion::close_cnx() {
    db.close();
}
