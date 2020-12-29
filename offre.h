#ifndef OFFRE_H
#define OFFRE_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"QString"
#include <QVariant>
class offre
{
    int id;
    QString nom;
    QString dateDebut;
    QString dateFin;
public:
    offre();
    offre(int,QString,QString,QString);

    int getID(){return id;}
    QString getnom(){return nom;}
    QString getdateD(){return dateDebut;}
    QString getdateF(){return dateFin;}

    void setID(int idd){id=idd;}
    void setnom(QString nomm){nom=nomm;}
    void setdateD(QString dated){dateDebut=dated;}
    void setdateF(QString datef){dateFin=datef;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier();
    QSqlQueryModel * rechercher2(const QString);
    QSqlQueryModel * trie();
     QSqlQueryModel * trie2();
     QSqlQueryModel *chercher_offre_id(const QString &aux);
     QSqlQueryModel *chercher_offre_nom(const QString &aux);
     QSqlQueryModel *chercher_offre_datedebut(const QString &aux);


};

#endif // OFFRE_H
