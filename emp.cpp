#include "emp.h"

emp::emp()
{

    id =0;
    cin=0;
    role="";
    nom ="";
    prenom="";

    }
    emp::emp(int id,int cin,QString nom,QString prenom,QString role)
    {
        this->id=id;
        this->cin=cin;
        this->role=role;

        this->nom=nom;
        this->prenom=prenom;
    }
    //getter
    QString emp::get_nom(){return nom;}
    int emp::get_id(){return id;}
    QString emp::get_prenom(){return prenom;}
    int emp::get_cin(){return cin;}
    QString emp::get_role(){return role;}



    bool emp::ajouter()
    {
        //Add row to empS
        QSqlQuery query;
        QString res= QString::number(id);
        query.prepare("INSERT INTO employes (ID,CIN, NOM, PRENOM, ROLE) "
                            "VALUES (:id, :cin, :nom, :prenom,:role)");
        query.bindValue(":id",res);
        query.bindValue(":cin",cin);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":role", role);
        return query.exec();

    }



    bool emp::supprimer(int idd)
    {
    //Delete from empS
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from EMPLOYES where ID = :id");
    query.bindValue(":id", res);
    return query.exec();
    }



    QSqlQueryModel * emp::afficher()
    {
        QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("select * from employes ORDER BY ID ASC ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM "));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("ROLE"));
        return model;
    }

    QSqlQueryModel * emp::afficher2()
    {
        QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("select * from employes ORDER BY NOM ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM "));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("ROLE"));
        return model;
    }

    QSqlQueryModel * emp::afficher3()
    {
        QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("select * from employes ORDER BY ROLE ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM "));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("ROLE"));
        return model;
    }

