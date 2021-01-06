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
        QSqlQuery query;
        query.prepare("INSERT INTO decorateur(id_decorateur,nom,adresse,description,prix,contacts) VALUES(:id_decorateur,:nom,:adresse,:description,:prix,:contacts)");
        query.bindValue(":id_decorateur",QString::number(id_decorateur));
        query.bindValue(":nom",nom);
        query.bindValue(":prix",QString::number(prix));
        query.bindValue(":adresse",adresse);
        query.bindValue(":description",description);
        query.bindValue(":contacts",contacts);
        return query.exec();
    }

QSqlQueryModel * decorateur::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from decorateur");
    model->setHeaderData(0,Qt::Horizontal,"Identifiant");
    model->setHeaderData(1,Qt::Horizontal,"Nom");
    model->setHeaderData(2,Qt::Horizontal,"Adresse");
    model->setHeaderData(3,Qt::Horizontal,"Contacts");
    model->setHeaderData(4,Qt::Horizontal,"Prix");
    model->setHeaderData(5,Qt::Horizontal,"Description");
    return(model);
}
bool decorateur::supprimer(int i)
{
    QSqlQuery query;
    query.prepare("delete from decorateur where id_decorateur=:id");
     QString res=QString::number(i);
    query.bindValue(":id",res);
    return query.exec();
}
QSqlQueryModel * decorateur::recherche(int a)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString c=QString::number(a);
    model->setQuery("select * from decorateur where id_decorateur="+c);
    model->setHeaderData(0,Qt::Horizontal,"Identifiant");
    model->setHeaderData(1,Qt::Horizontal,"Nom");
    model->setHeaderData(2,Qt::Horizontal,"Adresse");
    model->setHeaderData(3,Qt::Horizontal,"Contacts");
    model->setHeaderData(4,Qt::Horizontal,"Prix");
    model->setHeaderData(5,Qt::Horizontal,"Description");
    return(model);
}
