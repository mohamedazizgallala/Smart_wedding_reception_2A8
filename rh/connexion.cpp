#include "connexion.h"

connexion::connexion()
{

}
bool connexion::create_cnx(){
bool test=false;
QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("nb");
db.setUserName("moslm");
db.setPassword("b");
if(db.open())
test=true;
return test;
}
