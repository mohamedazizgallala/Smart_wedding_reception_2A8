#include "cll.h"
#include "ui_cll.h"
#include <QMessageBox>

cll::cll(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cll)
{
    ui->setupUi(this);
    cll::on_pb_actualiser_2_clicked();
}

cll::~cll()
{
    delete ui;
}

void cll::on_pb_ok_2_clicked()
{

    int cin= ui->cintxt->text().toInt();

    QString nom= ui->nomtxt->text();
    QString prenom= ui->prenomtxt->text();
    QString coiff= ui->coi->currentText();

    QString voiture= ui->voit->currentText();
    QString offre= ui->off->currentText();
    QString trait= ui->trait->currentText();

    QString deco= ui->deco->currentText();
    QString cerem= ui->certxt->currentText();
    QString cost= ui->cost->currentText();

    QString local= ui->loc->currentText();
    QString music= ui->mus->currentText();
    QString photo= ui->pho->currentText();


  client c(cin,nom,prenom,offre,cerem,photo,local,voiture,music,trait,deco,cost,coiff);
  bool test=c.ajouter();
  if(test)
{
      cll::on_pb_actualiser_2_clicked();
QMessageBox::information(nullptr, QObject::tr("Ajouter un employe"),
                  QObject::tr("employe ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un employe"),
                  QObject::tr("Erreur ! Check your data !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}



void cll::on_pb_actualiser_2_clicked()
{
    QString ha = ui->tri->currentText();

    if(ha == "CIN")
    {
        ui->tab->setModel(c.afficher());
        ui->supptxt->setModel(c.afficher());
    }
    if(ha == "PRENOM")
    {
        ui->tab->setModel(c.afficher3());
        ui->supptxt->setModel(c.afficher3());
    }
    if(ha == "NOM")
    {
        ui->tab->setModel(c.afficher4());
        ui->supptxt->setModel(c.afficher4());
    }
}

void cll::on_pb_supprimer_clicked()
{
    int cin = ui->supptxt->currentText().toInt();

    bool test=c.supprimer(cin);
    if(test)
    {cll::on_pb_actualiser_2_clicked();//refresh

        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab->setModel(c.afficher());

}
}

void cll::on_pb_modifierp_2_clicked()
{
    int cin= ui->cintxt->text().toInt();
    QString res= QString::number(cin);

    QString nom= ui->nomtxt->text();
    QString prenom= ui->prenomtxt->text();
    QString coiff= ui->coi->currentText();

    QString voiture= ui->voit->currentText();
    QString offre= ui->off->currentText();
    QString trait= ui->trait->currentText();

    QString deco= ui->deco->currentText();
    QString cerem= ui->certxt->currentText();
    QString cost= ui->cost->currentText();

    QString local= ui->loc->currentText();
    QString music= ui->mus->currentText();
    QString photo= ui->pho->currentText();

    QSqlQuery query;
    query.prepare ("update CLIENTS set nom = '"+nom+"',prenom = '"+prenom+"',coiff = '"+coiff+"', voiture = '"+voiture+"' , offre = '"+offre+"', trait = '"+trait+"', deco = '"+deco+"', cerem = '"+cerem+"', cost = '"+cost+"', local = '"+local+"' , music = '"+music+"', photo = '"+photo+"' where CIN = '"+res+"'");

    if(query.exec())
    {
        cll::on_pb_actualiser_2_clicked();
        QMessageBox::information(this,tr("Edit"),tr("Updated Successfully, Press 'Actualiser' to Apply changes !"));
    }
    else QMessageBox::critical(this,tr("Edit"),tr("Update Failed !"));
}

void cll::on_pb_ok_3_clicked()
{
    QString nom = ui->Snomtxt->text();
    QString prenom = ui->Sprenomtxt->text();
    QString CIN = ui->SCIN->text();

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from clients where nom = '"+nom+"' OR prenom = '"+prenom+"' OR CIN = '"+CIN+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("offre"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("cerem"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("coiff"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("cost"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("voiture"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("local"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("music"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("deco"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("trait"));
    model->setHeaderData(12, Qt::Horizontal, QObject::tr("photo"));

        ui->Stab->setModel(model);

}
