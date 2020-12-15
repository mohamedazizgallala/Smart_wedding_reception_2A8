#ifndef COIFFEURS_H
#define COIFFEURS_H
#include <qstring.h>
#include <QtSql/qsqlquerymodel.h>
#include <qstring.h>
#include <QtSql/qsqlquery.h>
#include <QtSql/qsqldatabase.h>
#include <qvariant.h>
#include <QTableView>
#include <QMessageBox>

class coiffeurs
{
public:
    coiffeurs();
    coiffeurs(QString,QString,QString,int,int);
    //getters
    QString getnom(){return nom;};
    QString getadr(){return adr;};
    QString getoperateur(){return operateur;};
    int getnum(){return num;}
    int getprix(){return prix;}

   //setters
    void setnom(QString nm){ nom=nm;}
    void setadr(QString adr){this->adr=adr;}
    void setoperateur(QString operateur){this->operateur=operateur;}
    void setnum(int nm){num=nm;}
    void setprix(int prx){this->prix=prx;}

    //methods
     //fonctions CRUD
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString);
    QSqlQueryModel * combo_box();
     //fonctions avancées
    QSqlQueryModel * recherche(const QString &);
    QSqlQueryModel * recherche_nom(const QString &);
    QSqlQueryModel * recherche_prix(const QString &);
    QSqlQueryModel * afficherdown_nom();
    QSqlQueryModel * afficherup_nom();
    QSqlQueryModel * afficherdown_prix();
    QSqlQueryModel * afficherup_prix();

    QSqlQueryModel * trier_nom_a();
    QSqlQueryModel * trier_nom_d();
    int calculer(QString );


private:
    QString nom;
    QString adr;
    QString operateur;
    int num;
    int prix;
};

#endif // COIFFEURS_H
