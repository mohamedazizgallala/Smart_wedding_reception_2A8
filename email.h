#ifndef EMAIL_H
#define EMAIL_H


#include "adresseemail.h"

/**
 * @brief The Email class permet la creation d'un email cest a dire le compte google utiliser, qui envoie,
 * qui recoit, le sujet et en fin le contenu du mail.
 */

class Email
{
public:
    Email();
    Email(AdresseEmail comptegoogle,
          AdresseEmail from,
          AdresseEmail to,
          QString subject,
          QString contenu);

    AdresseEmail getComptegoogle();
    AdresseEmail getFrom();
    AdresseEmail getTo();
    QString getSubject();
    QString getContenu();

    void setComptegoogle(const AdresseEmail cgoogle);
    void setFrom(const AdresseEmail from);
    void setTo(const AdresseEmail to);
    void setSubject(QString subject);
    void setContenu(QString contenu);

private:
    AdresseEmail Comptegoogle;
    AdresseEmail From;
    AdresseEmail To;
    QString Subject;
    QString Contenu;
};

#endif // EMAIL_H
