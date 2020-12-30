#include "local.h"

local::local()
{

}
local::local(QString id,QString endroit,QString type ,int nb_personne,QString entreprise,int prix)
{
    this->endroit=endroit;
    this->type=type;
    this->nb_personne=nb_personne;
    this->entreprise=entreprise;
    this->prix=prix;
    this->id=id;

}
bool local::ajouter_local()
{
    QSqlQuery query;
    query.prepare("INSERT INTO local(id,entreprise,type,prix,endroit,nb_personne) VALUES(:id,:entreprise,:type,:prix,:endroit,:nb_personne)");
    query.bindValue(":id",id);
    query.bindValue(":endroit",endroit);
    query.bindValue(":prix",QString::number(prix));
    query.bindValue(":type",type);
    query.bindValue(":entreprise",entreprise);
    query.bindValue(":nb_personne",QString::number(nb_personne));
    return query.exec(); }
QSqlQueryModel * local::afficher_local()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from local");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(2,Qt::Horizontal,"type");
    model->setHeaderData(3,Qt::Horizontal,"marque");
    model->setHeaderData(4,Qt::Horizontal,"prix");
    model->setHeaderData(1,Qt::Horizontal,"entreprise");
    model->setHeaderData(5,Qt::Horizontal,"nb_personne");
   return model;

}
bool local::supprimer_local(QString i)
{
    QSqlQuery query;
    query.prepare("delete from local where id=:id");
    query.bindValue(":id",i);
    return query.exec();
}
bool local::modifier_local()
{


    QSqlQuery query;
       query.prepare ("update local" "SET id = :id, endroit = :endroit, prix = :prix, nb_personne = :nb_personne,entreprise = :entreprise,type=:type" );
   return query.exec();

}
QSqlQueryModel * local::rechercher_combinaison_all(QString type,QString endroit,QString entreprise)
{
    QSqlQuery *qry=new QSqlQuery();
    qry->prepare("select * from local where type=:type and endroit=:endroit and entreprise=:entreprise");
    qry->bindValue(":type",type);
    qry->bindValue(":endroit",endroit);
    qry->bindValue(":entreprise",entreprise);
    qry->exec();

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(*qry);
    return model;
}
QSqlQueryModel * local::rechercher_combinaison_entreprise_endroit(QString entreprise, QString endroit)
{
    QSqlQuery *qry=new QSqlQuery();
    qry->prepare("select * from local where entreprise=:entreprise and endroit=:endroit");
    qry->bindValue(":entreprise",entreprise);
    qry->bindValue(":endroit",endroit);
    qry->exec();

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(*qry);
    return model;
}
QSqlQueryModel * local::rechercher_combinaison_type_entreprise(QString type, QString entreprise)
{
    QSqlQuery *qry=new QSqlQuery();
    qry->prepare("select * from local where type=:type and entreprise=:entreprise");
    qry->bindValue(":type",type);
    qry->bindValue(":entreprise",entreprise);
    qry->exec();

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(*qry);
    return model;

}
QSqlQueryModel * local::rechercher_combinaison_type_endroit(QString type, QString endroit)
{
    QSqlQuery *qry=new QSqlQuery();
    qry->prepare("select * from local where type=:type and endroit=:endroit");
    qry->bindValue(":type",type);
    qry->bindValue(":endroit",endroit);
    qry->exec();

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(*qry);
    return model;
}
 QSqlQueryModel * local::rechercher_type(QString type)
 {
     QSqlQuery *qry=new QSqlQuery();
     qry->prepare("select * from local where type=:type ");
     qry->bindValue(":type",type);
     qry->exec();

     QSqlQueryModel *model = new QSqlQueryModel();
     model->setQuery(*qry);
     return model;
 }
 QSqlQueryModel * local::rechercher_entreprise(QString entreprise)
 {
     QSqlQuery *qry=new QSqlQuery();
     qry->prepare("select * from local where entreprise=:entreprise ");
     qry->bindValue(":entreprise",entreprise);
     qry->exec();

     QSqlQueryModel *model = new QSqlQueryModel();
     model->setQuery(*qry);
     return model;
 }
 QSqlQueryModel * local::rechercher_endroit(QString endroit)
 {
     QSqlQuery *qry=new QSqlQuery();
     qry->prepare("select * from local where endroit=:endroit ");
     qry->bindValue(":endroit",endroit);
     qry->exec();

     QSqlQueryModel *model = new QSqlQueryModel();
     model->setQuery(*qry);
     return model;
 }
