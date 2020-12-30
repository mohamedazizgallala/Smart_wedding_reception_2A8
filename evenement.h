#ifndef EVENEMENT_H
#define EVENEMENT_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"QString"
#include <QVariant>

class evenement
{
    int id ;
    QString nom;
    QString date;
public:
    evenement();
    evenement(int,QString,QString);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier();
    QSqlQueryModel * rechercher2(const QString);
    QSqlQueryModel * trie();
     QSqlQueryModel * trie2();
     QSqlQueryModel *chercher_evenement_id(const QString &aux);
     QSqlQueryModel *chercher_evenement_nom(const QString &aux);
     QSqlQueryModel *chercher_evenement_dates(const QString &aux);

};

#endif // EVENEMENT_H
