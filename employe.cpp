#include "employe.h"
#include <QMessageBox>
#include "ui_employe.h"
#include <QMessageBox>
#include <QComboBox>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include "cll.h"

Employe::Employe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Employe)
{
    ui->setupUi(this);
    Employe::on_pb_actualiser_5_clicked();

}

Employe::~Employe()
{
    delete ui;
}

void Employe::on_pb_ok_clicked()
{
    int id = ui->idtxt->text().toInt();
    int cin= ui->cintxt->text().toInt();

    QString nom= ui->nomtxt->text();
    QString prenom= ui->prenomtxt->text();

    QString role= ui->roletxt->currentText();

  emp t(id,cin,nom,prenom,role);
  bool test=t.ajouter();
  if(test)
{
      Employe::on_pb_actualiser_5_clicked();
QMessageBox::information(nullptr, QObject::tr("Ajouter un employe"),
                  QObject::tr("employe ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un employe"),
                  QObject::tr("Erreur ! Check your data !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Employe::on_pb_actualiser_5_clicked()
{

    QString ha = ui->tri->currentText();

    if(ha == "ID")
    {
        ui->tab->setModel(t.afficher());
        ui->supptxt->setModel(t.afficher());
    }
    if(ha == "PRENOM")
    {
        ui->tab->setModel(t.afficher2());
        ui->supptxt->setModel(t.afficher2());
    }
    if(ha == "ROLE")
    {
        ui->tab->setModel(t.afficher3());
        ui->supptxt->setModel(t.afficher3());
    }
}

void Employe::on_pb_supprimer_clicked()
{
    int id = ui->supptxt->currentText().toInt();

    bool test=t.supprimer(id);
    if(test)
    {Employe::on_pb_actualiser_5_clicked();//refresh

        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab->setModel(t.afficher());


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Employe::on_pb_modifierp_5_clicked()
{
    int id = ui->idtxt->text().toInt();
    QString res= QString::number(id);
    int cin = ui->cintxt->text().toInt();
    QString res1= QString::number(cin);
    QString nom = ui->nomtxt->text();
    QString prenom = ui->prenomtxt->text();

    QString role = ui->roletxt->currentText();

    QSqlQuery query;
    query.prepare ("update employes set cin='"+res1+"',nom = '"+nom+"',prenom = '"+prenom+"',role='"+role+"' where id = '"+res+"'");

    if(query.exec())
    {
        Employe::on_pb_actualiser_5_clicked();
        QMessageBox::information(this,tr("Edit"),tr("Updated Successfully, Press 'Actualiser' to Apply changes !"));
    }
    else QMessageBox::critical(this,tr("Edit"),tr("Update Failed !"));
}











void Employe::on_pb_modifierp_6_clicked() //recherche
{
    QString nom = ui->Snomtxt->text();
    QString prenom = ui->Sprenomtxt->text();
    QString CIN = ui->SCIN->text();

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from EMPLOYES where nom = '"+nom+"' OR prenom = '"+prenom+"' OR CIN = '"+CIN+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ROLE"));


    ui->Stab->setModel(model);

}



void Employe::on_emchiclient_clicked()
{
 this->  close();
    cll n;
    n.exec();
}
