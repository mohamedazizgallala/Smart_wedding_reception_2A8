#ifndef ANIMATEUR_H
#define ANIMATEUR_H
#include <QVariant>
#include <QSqlQuery>
#include <QSqlQueryModel>

class animateur
{   QString nom,adresse,description,contacts;
    int prix,id_animateur;
      public :
      animateur();
    animateur(int,QString,QString,QString,int,QString);

    //getters
    QString getNom(){return(nom);}
    QString getAdresse(){return(adresse);}
    QString getDescription(){return(description);}
    QString getContacts(){return(contacts);}
    int getPrix(){return(prix);}
    int getId_animateur(){return(id_animateur);}

    //setters
    void setNom(QString n){nom=n;}
    void setAdresse(QString a){adresse=a;}
    void setDescription(QString d){description=d;}
    void setContacts(QString c){contacts=c;}
    void setPrix(int p){prix=p;}
    void setId_animateur(int i){id_animateur=i;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * recherche(int);

};

#endif // ANIMATEUR_H
