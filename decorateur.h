#ifndef DECORATEUR_H
#define DECORATEUR_H
#include <QSqlQuery>
#include <QSqlQueryModel>

class decorateur
{   QString nom,adresse,description,contacts;
    int prix,id_decorateur;
      public :
      decorateur();
    decorateur(int,QString,QString,QString,int,QString);

    //getters
    QString getNom(){return(nom);}
    QString getAdresse(){return(adresse);}
    QString getDescription(){return(description);}
    QString getContacts(){return(contacts);}
    int getPrix(){return(prix);}
    int getId_decorateur(){return(id_decorateur);}

    //setters
    void setNom(QString n){nom=n;}
    void setAdresse(QString a){adresse=a;}
    void setDescription(QString d){description=d;}
    void setContacts(QString c){contacts=c;}
    void setPrix(int p){prix=p;}
    void setId_decorateur(int i){id_decorateur=i;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);

};
#endif // DECORATEUR_H
