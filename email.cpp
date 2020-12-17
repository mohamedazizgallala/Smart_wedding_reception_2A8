#include "email.h"

Email::Email()
{

}

Email::Email(AdresseEmail comptegoogle, AdresseEmail from, AdresseEmail to, QString subject, QString contenu)
{
    this->Comptegoogle =comptegoogle;
    this->From = from;
    this->To = to;
    this->Subject = subject;
    this->Contenu = contenu;
}

AdresseEmail Email::getComptegoogle()
{
    return Comptegoogle;
}

AdresseEmail Email::getFrom()
{
    return From;
}

AdresseEmail Email::getTo()
{
    return To;
}

QString Email::getSubject()
{
    return Subject;
}

QString Email::getContenu()
{
    return Contenu;
}

void Email::setComptegoogle(const AdresseEmail cgoogle)
{
    this->Comptegoogle = cgoogle;
}

void Email::setFrom(const AdresseEmail from)
{
    this->From = from;
}

void Email::setTo(const AdresseEmail to)
{
    this->To = to;
}

void Email::setSubject(QString subject)
{
    this->Subject = subject;
}

void Email::setContenu(QString contenu)
{
 this->Contenu = contenu;
}
