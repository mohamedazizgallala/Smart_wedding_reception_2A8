#ifndef CAR_H
#define CAR_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
//test


class car
{ QString marque, couleur,entreprise,matricule;
    int  prix;
public:
    car();
    car(QString,QString,QString,QString,int);
    //getters if needed
    //setters if needed
    bool ajouter_car();
    QSqlQueryModel * afficher_car();
    bool supprimer_car(QString);
    bool modifier_car(QString);

};

#endif // CAR_H
