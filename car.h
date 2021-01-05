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
    bool modifier_car();
    QSqlQueryModel *rechercher_combinaison_all(QString,QString,QString);
    QSqlQueryModel *rechercher_combinaison_marque_couleur(QString,QString);
    QSqlQueryModel *rechercher_combinaison_marque_entreprise(QString,QString);
    QSqlQueryModel *rechercher_combinaison_couleur_entreprise(QString,QString);
    QSqlQueryModel *rechercher_marque(QString);
    QSqlQueryModel *rechercher_couleur(QString);
    QSqlQueryModel *rechercher_entreprise(QString);
    int count_couleur(QString);
    QSqlQueryModel * trie_dsc();
         QSqlQueryModel * trie_asc();

};

#endif // CAR_H
