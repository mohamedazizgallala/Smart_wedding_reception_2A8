#include "adresseemail.h"

AdresseEmail::AdresseEmail()
{

}

AdresseEmail::AdresseEmail(QString add, QString passwd){
    this->add = add;
    this->password = passwd;
}

QString AdresseEmail::get_addresse()
{
    return add;
}

QString AdresseEmail::get_passwd()
{
    return password;
}

void AdresseEmail::setAddresse(const QString addresse)
{
    add = addresse;
}

void AdresseEmail::setPasswd(const QString passwd)
{
    password = passwd;
}
