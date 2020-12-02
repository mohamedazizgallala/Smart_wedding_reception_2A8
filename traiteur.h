#ifndef TRAITEUR_H
#define TRAITEUR_H
#include <QSqlQuery>
#include <QSqlQueryModel>


class traiteur
{   QString nom,adresse,description,contacts;
    int prix,id_traiteur;
      public :
      traiteur();
    traiteur(int,QString,QString,QString,int,QString);

    //getters
    QString getNom(){return(nom);}
    QString getAdresse(){return(adresse);}
    QString getDescription(){return(description);}
    QString getContacts(){return(contacts);}
    int getPrix(){return(prix);}
    int getId_traiteur(){return(id_traiteur);}

    //setters
    void setNom(QString n){nom=n;}
    void setAdresse(QString a){adresse=a;}
    void setDescription(QString d){description=d;}
    void setContacts(QString c){contacts=c;}
    void setPrix(int p){prix=p;}
    void setId_traiteur(int i){id_traiteur=i;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * recherche(int);
};

#endif // TRAITEUR_H
