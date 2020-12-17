#ifndef ADRESSEEMAIL_H
#define ADRESSEEMAIL_H

#include <QString>

/**
 * @brief The AdresseEmail class est utilisé pour le stockage de l'addresse electronique et du mots de passe
 * si il est nessecaire. pour rappel la constructeur par defaut ne fera rien.
 */

class AdresseEmail
{
public:
    AdresseEmail();
    AdresseEmail(QString add, QString passwd = "");

    QString get_addresse();
    QString get_passwd();

    void setAddresse(const QString addresse);
    void setPasswd(const QString passwd);

private:
    QString add;
    QString password;
};

#endif // ADRESSEEMAIL_H
