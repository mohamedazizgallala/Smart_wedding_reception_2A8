#ifndef PHOTOGRAPHE_H
#define PHOTOGRAPHE_H
#include <QDialog>
#include <QString>
#include <QVariant>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Photographe
{
    int id;
    QString nom;
     QString prenom;
     int tel;
     QString adresse;

  public:

     Photographe();
     Photographe(int,QString,QString,int,QString);
     int get_id(){return id;}
     QString get_nom(){return nom;}
     QString get_prenom(){return prenom;}
     int get_tel(){return tel;}
     QString get_adresse(){return adresse;}
     bool ajouter();
     bool supprimer(int);
     QSqlQueryModel * afficher();
     bool modifier();
     QSqlQueryModel * trie();
      QSqlQueryModel * trie2();
          QSqlQueryModel *chercher_photo_id(const QString &aux);
          QSqlQueryModel *chercher_photo_nom(const QString &aux);
          QSqlQueryModel *chercher_photo_prenom(const QString &aux);

};


#endif // PHOTOGRAPHE_H

