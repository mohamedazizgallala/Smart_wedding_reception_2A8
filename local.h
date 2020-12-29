#ifndef LOCAL_H
#define LOCAL_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>

class local
{ QString id, endroit, type, entreprise;
    int nb_personne, prix;
public:
    local();
    local(QString,QString,QString,int,QString,int);
    //getters if needed
    //setters if needed
    bool ajouter_local();
    QSqlQueryModel * afficher_local();
    bool supprimer_local(QString);
    bool modifier_local();
    QSqlQueryModel *rechercher_combinaison_all(QString,QString,QString);
    QSqlQueryModel *rechercher_combinaison_type_entreprise(QString,QString );
    QSqlQueryModel *rechercher_combinaison_type_endroit(QString,QString);
    QSqlQueryModel *rechercher_combinaison_entreprise_endroit(QString,QString);
    QSqlQueryModel *rechercher_entreprise(QString);
    QSqlQueryModel *rechercher_endroit(QString);
    QSqlQueryModel *rechercher_type(QString);

};

#endif // LOCAL_H
