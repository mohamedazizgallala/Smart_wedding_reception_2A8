#define CLIENT_H
#define CLIENT_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class client
{
public:
    client();
    client(int,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);
    QString get_nom();
    QString get_prenom();
    QString get_offre();
    QString get_cerem();
    QString get_photo();
    QString get_coiff();
    QString get_cost();
    QString get_voiture();
    QString get_local();
    QString get_music();
    QString get_deco();
    QString get_trait();


    int get_cin();



    bool supprimer(int);
    bool ajouter();

    bool actualiser();
    bool modifier(int);
    //
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher2();
    QSqlQueryModel * afficher3();
    QSqlQueryModel * afficher4();
    QSqlQueryModel * afficher5();
    //
    private:
    int cin;
    QString nom,prenom,offre,coiff,photo,local,voiture,music,trait,deco,cost,cerem;

};
