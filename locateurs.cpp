#include "locateurs.h"
#include <qstring.h>
locateurs::locateurs()
{

}
locateurs::locateurs(QString noml,QString adressel,int numl,int prl){
    this->setnom(noml);
    this->setadr(adressel);
    this->setnum(numl);
    this->setprix(prl);
}

    bool locateurs::ajouter(){
        QSqlQuery query;
        query.prepare("INSERT INTO LOCATEURS(NOMl,ADRESSEl,NUMEROl,PRIXl) values(:noml,:adrl,:numl,:prxl)");
        QString nl = QString::number(numl);
        QString prxl = QString::number(prixl);

        query.addBindValue(noml);
        query.addBindValue(adrl);
        query.addBindValue(nl);
        query.addBindValue(prxl);
        return query.exec();
    }

    QSqlQueryModel * locateurs::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel;
    model->setQuery("SELECT * FROM LOCATEURS");
    model->setHeaderData(0,Qt::Horizontal,"noml");
    model->setHeaderData(1,Qt::Horizontal,"adressel");
    model->setHeaderData(2,Qt::Horizontal,"numerol");
    model->setHeaderData(3,Qt::Horizontal,"prixl");
    return model;
    }


    bool locateurs::supprimer(QString nl){
        QSqlQuery query;
        query.prepare("DELETE FROM LOCATEURS WHERE NOMl=:noml");
        //QString r=QString::number(nl);
        query.bindValue(":noml",nl);
        return query.exec();

    }

    bool locateurs::modifier(QString noml){
        QSqlQuery query;
           QString numl= QString::number(this->numl);
           QString prxl=QString::number(this->prixl);
          // QString noml= this->noml;
           QString adressel= this->adrl;
           query.prepare("UPDATE LOCATEURS SET NOML=:noml,ADRESSEL=:adressel,NUMEROL=:numl,PRIXl=:prixl  WHERE NOML=:noml");
           query.bindValue(":noml", noml);
           query.bindValue(":numl", numl);
           query.bindValue(":prixl", prxl);
           query.bindValue("adressel:", this->adrl);
           return query.exec();

    }
    QSqlQueryModel * locateurs::combo_box(){
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("SELECT NOML FROM LOCATEURS");
        return model;
    }

 QSqlQueryModel * locateurs::recherche_prix(const QString &prxl){
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM LOCATEURS WHERE (PRIXL LIKE '"+prxl+"%') ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("noml"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("adressel "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("numerol"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("prixl"));
 return model;
 }

/* QSqlQueryModel * locateurs::recherche_nom(const QString &noml)
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM LOCATEURS WHERE (NOML LIKE '"+noml+"%') ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("noml"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("adressel "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("numerol"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prixl"));
return model;
}
*/

QSqlQueryModel * locateurs::recherche(const QString &rech)
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from LOCATEURS where (NOML LIKE '"+rech+"%' OR ADRESSEL LIKE '"+rech+"%' OR NUMEROL LIKE '"+rech+"%' OR PRIXL LIKE '"+rech+"%') ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("noml"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("adressel "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("numerol"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prixl "));


return model;
}




 QSqlQueryModel * locateurs::afficherup_nom()
 {QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("SELECT * FROM LOCATEURS ORDER BY NOML ASC");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("noml"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("adressel"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("numerol"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("prixl"));
 return model;
}
  QSqlQueryModel * locateurs::afficherdown_nom()
  {QSqlQueryModel * model= new QSqlQueryModel();
  model->setQuery("SELECT * FROM LOCATEURS ORDER BY NOML DESC");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("noml"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("adressel"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("numerol"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("prixl"));
  return model;
 }

 QSqlQueryModel * locateurs::afficherup_prix()
 {QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("SELECT * FROM LOCATEURS ORDER BY PRIXL ASC");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("noml"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("adressel"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("numerol"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("prixl"));
 return model;
}

 QSqlQueryModel * locateurs::afficherdown_prix()
 {QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("SELECT * FROM LOCATEURS ORDER BY PRIXL DESC");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("noml"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("adressel"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("numerol"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("prixl"));
 return model;}

    QSqlQueryModel * locateurs::trier_nom_a()//asc
    {
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM LOCATEUR ORDER BY NOML ASC");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("noml"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("adressel"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("numerol"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("prixl"));

        return model;
    }
    QSqlQueryModel * locateurs::trier_nom_d()//desc
    {
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM LOCATEURS ORDER BY NOML DESC");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("noml"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("adressel"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("numerol"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("prixl"));

        return model;
    }
