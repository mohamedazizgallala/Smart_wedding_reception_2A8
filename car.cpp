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

bool car::modifier_car()
{


    QSqlQuery query;
       query.prepare ("update car" "SET matricule = :matricule, couleur = :couleur, prix = :prix, marque = :marque,entreprise = :entreprise" );
   return query.exec();

}
QSqlQueryModel * car::rechercher_combinaison_all(QString marque,QString couleur,QString entreprise)
{
    QSqlQuery *qry=new QSqlQuery();
    qry->prepare("select * from car where marque=:marque and couleur=:couleur and entreprise=:entreprise");
    qry->bindValue(":marque",marque);
    qry->bindValue(":couleur",couleur);
    qry->bindValue(":entreprise",entreprise);
    qry->exec();

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(*qry);
    return model;
}
QSqlQueryModel * car::rechercher_combinaison_marque_couleur(QString marque, QString couleur)
{
    QSqlQuery *qry=new QSqlQuery();
    qry->prepare("select * from car where marque=:marque and couleur=:couleur");
    qry->bindValue(":marque",marque);
    qry->bindValue(":couleur",couleur);
    qry->exec();

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(*qry);
    return model;
}
QSqlQueryModel * car::rechercher_combinaison_marque_entreprise(QString marque, QString entreprise)
{
    QSqlQuery *qry=new QSqlQuery();
    qry->prepare("select * from car where marque=:marque and entreprise=:entreprise");
    qry->bindValue(":marque",marque);
    qry->bindValue(":entreprise",entreprise);
    qry->exec();

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(*qry);
    return model;

}
QSqlQueryModel * car::rechercher_combinaison_couleur_entreprise(QString couleur, QString entreprise)
{
    QSqlQuery *qry=new QSqlQuery();
    qry->prepare("select * from car where couleur=:couleur and entreprise=:entreprise");
    qry->bindValue(":couleur",couleur);
    qry->bindValue(":entreprise",entreprise);
    qry->exec();

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(*qry);
    return model;
}
 QSqlQueryModel * car::rechercher_marque(QString marque)
 {
     QSqlQuery *qry=new QSqlQuery();
     qry->prepare("select * from car where marque=:marque ");
     qry->bindValue(":marque",marque);
     qry->exec();

     QSqlQueryModel *model = new QSqlQueryModel();
     model->setQuery(*qry);
     return model;
 }
 QSqlQueryModel * car::rechercher_entreprise(QString entreprise)
 {
     QSqlQuery *qry=new QSqlQuery();
     qry->prepare("select * from car where entreprise=:entreprise ");
     qry->bindValue(":entreprise",entreprise);
     qry->exec();

     QSqlQueryModel *model = new QSqlQueryModel();
     model->setQuery(*qry);
     return model;
 }
 QSqlQueryModel * car::rechercher_couleur(QString couleur)
 {
     QSqlQuery *qry=new QSqlQuery();
     qry->prepare("select * from car where couleur=:couleur ");
     qry->bindValue(":couleur",couleur);
     qry->exec();

     QSqlQueryModel *model = new QSqlQueryModel();
     model->setQuery(*qry);
     return model;
 }
 int car::count_couleur(QString couleur)
 {
   QSqlQuery qry;
   qry.prepare("select * from car where couleur=:couleur");
   qry.bindValue(":couleur",couleur);

   qry.exec();
   int total=0;
   while (qry.next()) total++;
   return total;

 }

