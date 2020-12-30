#include "animateur.h"

animateur::animateur()
{

}
animateur::animateur(int id_animateur,QString nom,QString adresse,QString description,int prix,QString contacts)
{
        this->nom=nom;
        this->adresse=adresse;
        this-> description=description;
        this->contacts=contacts;
        this->prix=prix;
        this->id_animateur=id_animateur;
}
bool animateur::ajouter()

    {
        QSqlQuery query;
        query.prepare("INSERT INTO ANIMATEUR(id_animateur,nom,adresse,description,prix,contacts) VALUES(:id_animateur,:nom,:adresse,:description,:prix,:contacts)");
        query.bindValue(":id_animateur",QString::number(id_animateur));
        query.bindValue(":nom",nom);
        query.bindValue(":prix",QString::number(prix));
        query.bindValue(":adresse",adresse);
        query.bindValue(":description",description);
        query.bindValue(":contacts",contacts);
        return query.exec();
    }

QSqlQueryModel * animateur::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from animateur");
    model->setHeaderData(0,Qt::Horizontal,"Identifiant");
    model->setHeaderData(1,Qt::Horizontal,"Nom");
    model->setHeaderData(2,Qt::Horizontal,"Adresse");
    model->setHeaderData(3,Qt::Horizontal,"Contacts");
    model->setHeaderData(4,Qt::Horizontal,"Prix");
    model->setHeaderData(5,Qt::Horizontal,"Description");
    return(model);
}
bool animateur::supprimer(int i)
{
    QSqlQuery query;
    query.prepare("delete from animateur where id_animateur=:id");
     QString res=QString::number(i);
    query.bindValue(":id",res);
    return query.exec();
}
QSqlQueryModel * animateur::recherche(int a)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString c=QString::number(a);
    model->setQuery("select * from animateur where id_animateur="+c);
    model->setHeaderData(0,Qt::Horizontal,"Identifiant");
    model->setHeaderData(1,Qt::Horizontal,"Nom");
    model->setHeaderData(2,Qt::Horizontal,"Adresse");
    model->setHeaderData(3,Qt::Horizontal,"Contacts");
    model->setHeaderData(4,Qt::Horizontal,"Prix");
    model->setHeaderData(5,Qt::Horizontal,"Description");
    return(model);
}
