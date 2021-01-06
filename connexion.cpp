#include "connexion.h"

Connexion::Connexion()
{

}
bool Connexion::create_cnx() {

    bool test=false;
    db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("source_projet2A");
    db.setUserName("aziz");
    db.setPassword("aziz");
    if (db.open()) test=true;
    return test;
}
void Connexion::close_cnx() {
    db.close();
}
