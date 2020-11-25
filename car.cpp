#include "car.h"

car::car()
{

}
car::car(QString marque,QString couleur,QString entreprise,QString matricule,int prix)
{
    this->marque=marque;
    this->couleur=couleur;
    this->entreprise=entreprise;
    this->matricule=matricule;
    this->prix=prix;
}
bool car::ajouter_car()
{
    QSqlQuery query;
    query.prepare("INSERT INTO car(matricule,couleur,prix,marque,entreprise) VALUES(:matricule,:couleur,:prix,:marque,:entreprise)");
    query.bindValue(":matricule",matricule);
    query.bindValue(":couleur",couleur);
    query.bindValue(":prix",QString::number(prix));
    query.bindValue(":marque",marque);
    query.bindValue(":entreprise",entreprise);
    return query.exec();
}
QSqlQueryModel * car::afficher_car()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from car");
    model->setHeaderData(0,Qt::Horizontal,"matricule");
    model->setHeaderData(2,Qt::Horizontal,"prix");
    model->setHeaderData(3,Qt::Horizontal,"marque");
    model->setHeaderData(4,Qt::Horizontal,"entreprise");
    model->setHeaderData(1,Qt::Horizontal,"couleur");
   return model;

}
bool car::supprimer_car(QString m)
{
    QSqlQuery query;
    query.prepare("delete from car where matricule=:matricule");
    query.bindValue(":matricule",m);
    return query.exec();
}

bool car::modifier_car(QString m)
{
    /* QSqlQuery query;
     query.prepare("update car " " entreprise=:entreprise,couleur=:couleur,prix=:prix,marque=:marque" "where matricule=:matricule");
     query.bindValue(":matricule",m);
     query.bindValue(":couleur",couleur);
     query.bindValue(":prix",QString::number(prix));
     query.bindValue(":marque",marque);
     query.bindValue(":entreprise",entreprise);
     return query.exec(); */

}
