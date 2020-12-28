#include "photographe.h"
#include <QMediaPlayer>

Photographe::Photographe()
{

}

Photographe::Photographe(int i,QString n,QString p,int t,QString a)
{
  id = i;
  nom = n ;
  prenom = p;
  tel = t;
  adresse = a;
}


bool Photographe::ajouter()
{
  QSqlQuery query;
  query.prepare("insert into PHOTO (id,nom,prenom,tel,adresse) " "values (:id,:nom,:prenom,:tel,:adresse)");
  QString res= QString::number(id);
  QString ress= QString::number(tel);

  query.bindValue(":id",res);
  query.bindValue(":nom",nom);
  query.bindValue(":prenom",prenom);
  query.bindValue(":tel",ress);
  query.bindValue(":adresse",adresse);
  return query.exec();

}



bool Photographe::supprimer(int i)
{
    QSqlQuery query;
    query.prepare("Delete from PHOTO where id=:id");
    QString res= QString::number(i);
    query.bindValue(":id",res);
    return query.exec();

}


QSqlQueryModel * Photographe::afficher()
{
  QSqlQueryModel * model = new QSqlQueryModel();
  model->setQuery("select * from PHOTO");
  model->setHeaderData(0,Qt::Horizontal,"id");
  model->setHeaderData(1,Qt::Horizontal,"nom");
  model->setHeaderData(2,Qt::Horizontal,"prenom");
  model->setHeaderData(3,Qt::Horizontal,"tel");
   return model;
}


bool Photographe::modifier()
{
    QSqlQuery q;
    q.prepare ("update PHOTO" "SET id = :id, nom = :nom, prenom = :prenom, tel = :tel, adresse = :adresse" );
    return q.exec();

}

QSqlQueryModel* Photographe::trie()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *from PHOTO ORDER BY id asc");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr(" prenom"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));


    return model;
}


QSqlQueryModel* Photographe::trie2()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("select *from PHOTO ORDER BY id desc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr(" prenom"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));


    return model;
}


QSqlQueryModel * Photographe::chercher_photo_id(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from PHOTO where ((id ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("id"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("tel"));
    model->setHeaderData(4,Qt::Vertical,QObject::tr("adresse"));

    return model;
}


QSqlQueryModel * Photographe::chercher_photo_nom(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from PHOTO where ((nom ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("id"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("tel"));
    model->setHeaderData(4,Qt::Vertical,QObject::tr("adresse"));

    return model;
}

QSqlQueryModel * Photographe::chercher_photo_prenom(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from PHOTO where ((prenom ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("id"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("tel"));
    model->setHeaderData(4,Qt::Vertical,QObject::tr("adresse"));

    return model;
}










