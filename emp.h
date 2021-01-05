#ifndef EMP_H
#define EMP_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class emp
{
public:  
    emp();
    emp(int,int,QString,QString,QString);
    QString get_nom();
    QString get_prenom();
    QString get_role();
    int get_id();
    int get_cin();


    bool supprimer(int);
    bool ajouter();
    void nettoyer();
    bool actualiser();
    bool modifier(int);
    //
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher2();
    QSqlQueryModel * afficher3();

    //
    private:
    int id,cin;
    QString nom,prenom,role;


};

#endif // emp_H
