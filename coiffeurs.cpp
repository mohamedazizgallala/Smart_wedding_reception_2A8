#include "coiffeurs.h"
#include <qstring.h>
coiffeurs::coiffeurs()
{

}

coiffeurs::coiffeurs(QString nom,QString adresse,QString operateur,int num,int pr){
    this->setnom(nom);
    this->setadr(adresse);
    this->setnum(num);
    this->setprix(pr);
    this->setoperateur(operateur);
}



/* QString coiffeurs::get_nom(){return nom;}
 int coiffeurs::get_adresse(){return adr;}
 int coiffeurs::get_numero(){return num;}
 float coiffeurs::get_prix(){return pr;}*/


    bool coiffeurs::ajouter(){
        QSqlQuery query;
        query.prepare("INSERT INTO COIFFEURS(NOM,ADRESSE,NUMERO,PRIX,OPERATEUR) values(:nom,:adr,:num,:prx,:operateur)");
        QString n = QString::number(num);
        QString prx = QString::number(prix);

        query.bindValue(":nom",nom);
        query.bindValue(":adr",adr);
        query.bindValue(":num",n);
        query.bindValue(":prx",prx);
        query.bindValue(":operateur",operateur);
        return query.exec();
    }


    QSqlQueryModel * coiffeurs::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel;
    model->setQuery("SELECT * FROM COIFFEURS");
    model->setHeaderData(0,Qt::Horizontal,"nom");
    model->setHeaderData(1,Qt::Horizontal,"adresse");
    model->setHeaderData(2,Qt::Horizontal,"numero");
    model->setHeaderData(3,Qt::Horizontal,"prix");
    model->setHeaderData(4,Qt::Horizontal,"operateur");
    return model;
    }


    bool coiffeurs::supprimer(QString n){
        QSqlQuery query;
        query.prepare("DELETE FROM COIFFEURS WHERE NOM=:nom");
        //QString r=QString::number(n);
        query.bindValue(":nom",n);
        return query.exec();

    }

    bool coiffeurs::modifier(QString nom){
        QSqlQuery query;
           QString tmp= QString::number(num);
           QString tmp1=QString::number(prix);

           QString adresse;
           query.prepare("UPDATE  COIFFEURS SET NOM=:nom,ADRESSE=:adresse,NUMERO=:num,PRIX=:prix  WHERE NOM=:nom");
           query.bindValue(":nom", nom);
           query.bindValue(":num", tmp);
           query.bindValue(":prix", tmp1);
           query.bindValue(":adresse", adr);
           return query.exec();

    }
    QSqlQueryModel * coiffeurs::combo_box(){
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select nom from coiffeurs");
        return model;
    }
   /* QSqlQueryModel * coiffeurs::recherche_nom(QString nom){
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("Select * From coiffeurs WHERE nom ='" +nom+"'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));

        return model;
    }*/

   /* QSqlQueryModel * coiffeurs::recherche_prix(int prix){
        QSqlQueryModel * model = new QSqlQueryModel();
        QString res = QString::number(prix);
        model->setQuery("Select * From coiffeurs WHERE prix = " + res);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));

        return model;
    }*/
    QSqlQueryModel * coiffeurs::recherche(const QString &rech)
    {
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from COIFFEURS where (NOM LIKE '"+rech+"%' OR ADRESSE LIKE '"+rech+"%' OR NUMERO LIKE '"+rech+"%' OR PRIX LIKE '"+rech+"%') ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix "));


    return model;
    }


/* QSqlQueryModel * coiffeurs::recherche_prix(const QString &prx){
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM COIFFEURS WHERE (PRIX LIKE '"+prx+"%') ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
 return model;
 }

 QSqlQueryModel * coiffeurs::recherche_nom(const QString &nom)
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM COIFFEURS WHERE (NOM LIKE '"+nom+"%') ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));


return model;
}*/
 QSqlQueryModel * coiffeurs::afficherup_nom()
 {QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("SELECT * FROM COIFFEURS  ORDER BY NOM ASC");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
 return model;
}
  QSqlQueryModel * coiffeurs::afficherdown_nom()
  {QSqlQueryModel * model= new QSqlQueryModel();
  model->setQuery("SELECT * FROM COIFFEURS ORDER BY NOM DESC");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
  return model;
 }

 QSqlQueryModel * coiffeurs::afficherup_prix()
 {QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("SELECT * FROM COIFFEURS ORDER BY PRIX ASC");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
 return model;
}

 QSqlQueryModel * coiffeurs::afficherdown_prix()
 {QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("SELECT * FROM COIFFEURS ORDER BY PRIX DESC");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
 return model;}


    QSqlQueryModel * coiffeurs::trier_nom_a()//asc
    {
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM COIFFEURS\
                             ORDER BY NOM ASC");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));

        return model;
    }
    QSqlQueryModel * coiffeurs::trier_nom_d()//desc
    {
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM COIFFEURS\
                             ORDER BY NOM DESC");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));

        return model;
    }

    int coiffeurs::calculer(QString operateur) {
      QSqlQuery query;
      query.prepare("select * from coiffeurs where operateur = :operateur");
      query.bindValue(":operateur", operateur);

      query.exec();
      int total = 0;
      while (query.next()) {
        total++;
      }

      return total;
    }

