#include "decorateur.h"


decorateur::decorateur()
{

}
decorateur::decorateur(int id_decorateur,QString nom,QString adresse,QString description,int prix,QString contacts)
{
        this->nom=nom;
        this->adresse=adresse;
        this-> description=description;
        this->contacts=contacts;
        this->prix=prix;
        this->id_decorateur=id_decorateur;
}
bool decorateur::ajouter()
{

}
QSqlQueryModel * decorateur::afficher()
{

}
bool decorateur::supprimer(int id)
{

}
