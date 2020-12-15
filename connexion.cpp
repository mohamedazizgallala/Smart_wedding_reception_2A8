#include "connexion.h"

Connexion::Connexion()
{

}
bool Connexion::create_cnx() {

    bool test=false;
    db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("2A8");
    db.setUserName("hackerwoman");
    db.setPassword("esprit");
    if (db.open()) test=true;
    return test;
}
void Connexion::close_cnx() {
    db.close();
}
