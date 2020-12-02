#include "traiteur.h"

traiteur::traiteur()
{

}
traiteur::traiteur(int id_traiteur,QString nom,QString adresse,QString description,int prix,QString contacts)
{
        this->nom=nom;
        this->adresse=adresse;
        this-> description=description;
        this->contacts=contacts;
        this->prix=prix;
        this->id_traiteur=id_traiteur;
}
bool traiteur::ajouter()

    {
        QSqlQuery query;
        query.prepare("INSERT INTO traiteur(id_traiteur,nom,adresse,description,prix,contacts) VALUES(:id_traiteur,:nom,:adresse,:description,:prix,:contacts)");
        query.bindValue(":id_traiteur",QString::number(id_traiteur));
        query.bindValue(":nom",nom);
        query.bindValue(":prix",QString::number(prix));
        query.bindValue(":adresse",adresse);
        query.bindValue(":description",description);
        query.bindValue(":contacts",contacts);
        return query.exec();
    }

QSqlQueryModel * traiteur::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from traiteur");
    model->setHeaderData(0,Qt::Horizontal,"Identifiant");
    model->setHeaderData(1,Qt::Horizontal,"Nom");
    model->setHeaderData(2,Qt::Horizontal,"Adresse");
    model->setHeaderData(3,Qt::Horizontal,"Contacts");
    model->setHeaderData(4,Qt::Horizontal,"Prix");
    model->setHeaderData(5,Qt::Horizontal,"Description");
    return(model);
}
bool traiteur::supprimer(int i)
{
    QSqlQuery query;
    query.prepare("delete from traiteur where id_traiteur=:id");
     QString res=QString::number(i);
    query.bindValue(":id",res);
    return query.exec();
}
QSqlQueryModel * traiteur::recherche(int a)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString c=QString::number(a);
    model->setQuery("select * from traiteur where id_traiteur="+c);
    model->setHeaderData(0,Qt::Horizontal,"Identifiant");
    model->setHeaderData(1,Qt::Horizontal,"Nom");
    model->setHeaderData(2,Qt::Horizontal,"Adresse");
    model->setHeaderData(3,Qt::Horizontal,"Contacts");
    model->setHeaderData(4,Qt::Horizontal,"Prix");
    model->setHeaderData(5,Qt::Horizontal,"Description");
    return(model);
}
