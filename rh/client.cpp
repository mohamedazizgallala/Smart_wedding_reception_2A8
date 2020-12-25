#include "client.h"
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

client::client()
{
cin=0;
nom ="";
prenom="";
nom="";
prenom="";
offre="";
coiff="";
photo="";
local="";
voiture="";
music="";
trait="";
deco="";
cost="";
cerem="";

}
client::client(int cin,QString nom,QString prenom,QString offre,QString coiff,QString photo,QString local,QString voiture,QString music,QString trait,QString deco,QString cost,QString cerem)
{

    this->cin=cin;

    this->offre=offre;
    this->coiff=coiff;
    this->local=local;

    this->photo=photo;
    this->cerem=cerem;
    this->voiture=voiture;

    this->music=music;
    this->trait=trait;
    this->deco=deco;

    this->cost=cost;

    this->nom=nom;
    this->prenom=prenom;
}
//getter
QString client::get_nom(){return nom;}
int client::get_cin(){return cin;}
QString client::get_prenom(){return prenom;}

QString client::get_coiff(){return coiff;}
QString client::get_offre(){return offre;}
QString client::get_local(){return local;}


QString client::get_voiture(){return voiture;}
QString client::get_cost(){return cost;}
QString client::get_music(){return music;}


QString client::get_trait(){return trait;}
QString client::get_deco(){return deco;}
QString client::get_cerem(){return cerem;}


QString client::get_photo(){return photo;}



bool client::ajouter()
{
    //Add row to CLIENTS
    QSqlQuery query;
    QString res= QString::number(cin);
    query.prepare("INSERT INTO CLIENTS (cin,nom,prenom,offre,coiff,photo,local,voiture,music,trait,deco,cost,cerem) "
                        "VALUES (:cin, :nom, :prenom, :offre, :coiff, :photo, :local,:voiture,:music,:trait,:deco,:cost,:cerem)");

    /*query.prepare("INSERT INTO CLIENTS (cin,nom,prenom,offre,coiff,cost)"
                        "VALUES (:cin, :nom, :prenom, :offre, :coiff, :cost)");*/

    query.bindValue(":cin",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom", prenom);

    query.bindValue(":local", local);
    query.bindValue(":coiff", coiff);
    query.bindValue(":offre", offre);

    query.bindValue(":voiture", voiture);
    query.bindValue(":music", music);
    query.bindValue(":trait", trait);

    query.bindValue(":cerem", cerem);
    query.bindValue(":deco", deco);
    query.bindValue(":cost", cost);

    query.bindValue(":photo", photo);

    return query.exec();

}



bool client::supprimer(int idd)
{
//Delete from CLIENTS
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from CLIENTS where CIN = :CIN");
query.bindValue(":CIN", res);
return query.exec();
}



QSqlQueryModel * client::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from CLIENTS ORDER BY CIN ASC ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM "));

    model->setHeaderData(3, Qt::Horizontal, QObject::tr("offre"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("cerem"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("coiff"));

      model->setHeaderData(6, Qt::Horizontal, QObject::tr("cost"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("voiture"));
          model->setHeaderData(8, Qt::Horizontal, QObject::tr("local"));

                    model->setHeaderData(9, Qt::Horizontal, QObject::tr("music"));
                    model->setHeaderData(10, Qt::Horizontal, QObject::tr("deco"));
              model->setHeaderData(11, Qt::Horizontal, QObject::tr("trait"));

                    model->setHeaderData(12, Qt::Horizontal, QObject::tr("photo"));
    return model;
}

QSqlQueryModel * client::afficher2()
{

}

QSqlQueryModel * client::afficher3()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from CLIENTS ORDER BY PRENOM ASC ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM "));

    model->setHeaderData(3, Qt::Horizontal, QObject::tr("offre"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("cerem"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("coiff"));

      model->setHeaderData(6, Qt::Horizontal, QObject::tr("cost"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("voiture"));
          model->setHeaderData(8, Qt::Horizontal, QObject::tr("local"));

                    model->setHeaderData(9, Qt::Horizontal, QObject::tr("music"));
                    model->setHeaderData(10, Qt::Horizontal, QObject::tr("deco"));
              model->setHeaderData(11, Qt::Horizontal, QObject::tr("trait"));

                    model->setHeaderData(12, Qt::Horizontal, QObject::tr("photo"));
    return model;
}

QSqlQueryModel * client::afficher4()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from CLIENTS ORDER BY NOM ASC ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM "));

    model->setHeaderData(3, Qt::Horizontal, QObject::tr("offre"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("cerem"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("coiff"));

      model->setHeaderData(6, Qt::Horizontal, QObject::tr("cost"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("voiture"));
          model->setHeaderData(8, Qt::Horizontal, QObject::tr("local"));

                    model->setHeaderData(9, Qt::Horizontal, QObject::tr("music"));
                    model->setHeaderData(10, Qt::Horizontal, QObject::tr("deco"));
              model->setHeaderData(11, Qt::Horizontal, QObject::tr("trait"));

                    model->setHeaderData(12, Qt::Horizontal, QObject::tr("photo"));
    return model;
}






