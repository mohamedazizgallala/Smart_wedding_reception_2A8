#ifndef LOCATEURS_H
#define LOCATEURS_H
#include <qstring.h>
#include <QtSql/qsqlquerymodel.h>
#include <qstring.h>
#include <QtSql/qsqlquery.h>
#include <QtSql/qsqldatabase.h>
#include <qvariant.h>
#include <QTableView>
#include <QMessageBox>

class locateurs
{
public:
    locateurs();
    locateurs(QString,QString,int,int);
    //getters
    QString getnom(){return noml;};
    QString getadr(){return adrl;};
    int getnum(){return numl;}
    int getprix(){return prixl;}
   //setters
    void setnom(QString nml){ noml=nml;}
    void setadr(QString adrl){this->adrl=adrl;}
    void setnum(int nml){numl=nml;}
    void setprix(int prxl){this->prixl=prxl;}
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
private:
    QString noml;
    QString adrl;
    int numl;
    int prixl;
};

#endif // LOCATEURS_H

