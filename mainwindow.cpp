#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "send_email_location.h"
#include "pie_location.h"
#include <QMediaPlayer>
#include <QUrl>
#include "offre.h"
#include <QSystemTrayIcon>
#include "evenement.h"
#include<QPrinter>
#include<QPrintDialog>
#include<QTextDocument>
#include<QTextStream>
#include <QDate>
#include "graphiste.h"
#include "smtp_location.h"
#include <QTimer>
#include <QTime>
#include <QDateTime>
#include "arduino.h"
#include <QSerialPort>
#include "smtp_graphisme.h"
#include "coiffeurs.h"
#include "locateurs.h"
#include <qtableview.h>
#include "statbeaute.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);
    //*****************************************************
       //*************************************************
       //Dont allow resize
       //********************************************
       //****************************************************
      setFixedSize(621,421);  //fixe la taille de la fenêtre

           setWindowFlags(Qt::CustomizeWindowHint); //supprime les paramétrages de fenêtre par défaut. Oblige donc de préciser les réglagess autorisés
         setWindowFlags(Qt::WindowTitleHint); //Autorise le titre de la fenêtre
          setWindowFlags(Qt::WindowSystemMenuHint);
           setWindowFlags(Qt::WindowMinimizeButtonHint);//autorise le bouton de réduction de fenêtre
           setWindowFlags(Qt::WindowCloseButtonHint); //autorise le bouton de fermeture

           //***********************************************
           //***************************************
    int ret=Ard.connect_arduino();
    switch(ret){
    case(0):qDebug()<<"arduino is available and connected to: "<< Ard.getarduino_port_name();
    break;
    case(1):qDebug()<<"arduino is available but not connected to "<< Ard.getarduino_port_name();
    break;
    case(-1):qDebug()<<"arduino is not available ";
    }
    QObject::connect(Ard.getserial(),SIGNAL(readyRead()),this,SLOT(detect()));



   //controle de saisie id_photographe
     ui->lineedit_id->setValidator(new QIntValidator(0,99999999,this));
   //controle de saisie id_graphiste
      ui->_lineedit_id_2->setValidator(new QIntValidator(0,99999999,this));

     //Timer
          QTimer *timer_p=new QTimer(this);
          connect(timer_p, SIGNAL(timeout()), this,SLOT(showTime()));
          timer_p->start(1000);

      //DAate systeme
          QDateTime Date_p=QDateTime::currentDateTime();
          QString Date_txt=Date_p.toString("dddd dd MMMM yyyy");
          ui->Date->setText(Date_txt);

    //***********************
    //***********************


          //***************************

    //table view module location
    ui->table_car->setModel(cartemp.afficher_car()); //actualiser la table
    ui->table_car->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_car->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->table_local->setModel(localtemp.afficher_local());
    ui->table_local->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_local->setSelectionMode(QAbstractItemView::SingleSelection);
    // mail_regex=QRegExp("^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");

   //*****************************
    //***************************

    //table view module organisation
    ui->tableView_4_org->setModel(tempanimateur.afficher());
       ui->tableView_4_org->setSelectionBehavior(QAbstractItemView::SelectRows);
       ui->tableView_4_org->setSelectionMode(QAbstractItemView::SingleSelection);
       ui->tableView_5_org->setModel(temptraiteur.afficher());
       ui->tableView_5_org->setSelectionBehavior(QAbstractItemView::SelectRows);
       ui->tableView_5_org->setSelectionMode(QAbstractItemView::SingleSelection);

       //*****************************
        //***************************

        //table view module marketing
       ui->tableView_2_mar->setModel(tmpev.afficher());
          evenement e;
          ui->tableView_2_mar->setModel(e.afficher());

          //*****************************
           //***************************

           //table view module graphisme
          ui->tablephotographes->setModel(tempphoto.afficher());
          ui->tablephotographes->setSelectionBehavior(QAbstractItemView::SelectRows);
          ui->tablephotographes->setSelectionMode(QAbstractItemView::SingleSelection);

          ui->tablegraphistes->setModel(tempgraph.afficher());
          ui->tablegraphistes->setSelectionBehavior(QAbstractItemView::SelectRows);
          ui->tablegraphistes->setSelectionMode(QAbstractItemView::SingleSelection);

          QItemSelectionModel *select = ui->tablephotographes->selectionModel();
          email_recipient =select->selectedRows(4).value(0).data().toString();

          QItemSelectionModel *selectt = ui->tablegraphistes->selectionModel();
          email_recipient =selectt->selectedRows(4).value(0).data().toString();

          //*****************************
           //***************************
          //table view module beauté
                   //coiff
                   ui->tableView_coiff->setModel(coiff.afficher());
                   //locat
                   ui->tableView_locat->setModel(locat.afficher());
                 //  connect(this->ui->pushButton_send, SIGNAL(clicked(bool)), this, SLOT(send_mail()));


          //*****************************
           //***************************
          //arduino weswes
          //Ard.connect_arduino();
          //Ard.read_from_arduino();


          //*********************

}

MainWindow::~MainWindow()
{
    delete ui;
}

//**************************************************

void MainWindow::detect(){
    data1=Ard.read_from_arduino();
    if (data1=="2"){
        QMessageBox::information(nullptr, QObject::tr("Mouvement"),
                                 QObject::tr("employe graphisme Arrivé."), QMessageBox::Ok);

    }
}

//*****************************
/****************/

     //general LOGIN
void MainWindow::on_login_button_clicked()
{
  QSqlQuery query;
    QMessageBox msgBox;
        QString id =ui->id->text(), pw=ui->password->text(),type="";
        query.prepare("SELECT ROLE FROM EMPLOYE WHERE ID =:id AND PASSWORD =:password");
        query.bindValue(":id", id);
        query.bindValue(":password",pw);
        query.exec();

        while(query.next())
      {

       type=query.value(0).toString();
       }
        if (type=="") {  QMessageBox::critical(nullptr, QObject::tr("Echec d'authentification"),
       QObject::tr("Mot de passe ou nom d'utilisateur non-valide"), QMessageBox::Cancel); }
        else {
       msgBox.setText("Identifié comme employé  " +type);
       msgBox.exec();
       if (type== "location")
        ui->stackedWidget->setCurrentIndex(1);
       else if (type== "organisation")
           ui->stackedWidget->setCurrentIndex(10);
       else if (type=="marketing")
           ui->stackedWidget->setCurrentIndex(18);
       else if (type=="graphisme")
          ui->stackedWidget->setCurrentIndex(21);
       else if (type=="beaute")
          ui->stackedWidget->setCurrentIndex(24);
       else if (type=="RH")
          ui->stackedWidget->setCurrentIndex(27);
       }


}

 //********************************************
//***********************************
//*****************************/
//arduino


//module location
void MainWindow::on_add_car_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_add_carButton_clicked()
{
    bool control=true;
    QString marque=ui->marqueEdit->text();

    QString matricule=ui->matriculeEdit->text();
    QString entreprise=ui->entreprise_carEdit->text();
    QString couleur=ui->couleurEdit->text();
    int prix = ui->prix_jourEdit->text().toInt();
    if (matricule=="" or entreprise=="" or couleur=="" or marque=="" or prix<=0)
       { QMessageBox::critical(nullptr, QObject::tr("Ajouter d'une voiture"),
                           QObject::tr("Invalid entry!\n"
                                       "Click Ok to close."), QMessageBox::Ok); }

    car c(marque,couleur,entreprise,matricule,prix);
    bool test=c.ajouter_car();
    if (test==true)
    {  ui->table_car->setModel(cartemp.afficher_car()); //actualiser la table
        QMessageBox::information(nullptr, QObject::tr("Ajout d'une voiture"),
                                 QObject::tr("une voiture a été ajoutée."), QMessageBox::Ok); }
    else {  QMessageBox::critical(nullptr, QObject::tr("Ajout d'une voiture"),
                                     QObject::tr("l'ajout a échoué."), QMessageBox::Cancel); }

     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_search_car_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
     /*ui->critere_1_car->addItem("Marque");
     ui->critere_1_car->addItem("Couleur");
     ui->critere_1_car->addItem("Matricule");
     ui->critere_1_car->addItem("Entreprise");
     ui->critere_1_car->addItem("Prix minimal");
     ui->critere_1_car->addItem("Prix maximal");
     ui->critere_1_car->addItem("Modèle");

     ui->critere_2_car->addItem("Marque");
     ui->critere_2_car->addItem("Couleur");
     ui->critere_2_car->addItem("Matricule");
     ui->critere_2_car->addItem("Entreprise");
     ui->critere_2_car->addItem("Prix minimal");
     ui->critere_2_car->addItem("Prix maximal");
     ui->critere_2_car->addItem("Modèle");

     ui->critere_3_car->addItem("Marque");
     ui->critere_3_car->addItem("Couleur");
     ui->critere_3_car->addItem("Matricule");
     ui->critere_3_car->addItem("Entreprise");
     ui->critere_3_car->addItem("Prix minimal");
     ui->critere_3_car->addItem("Prix maximal");
     ui->critere_3_car->addItem("Modèle");*/
}


void MainWindow::on_return_search_carButton_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_return_add_carButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_showlist_car_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_return_car_listButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_send_email_car_clicked()
{


      // QString email_recipient ="malek.labidi@esprit.tn";
      // QString nom_recipient ="someone";
     //  QString sexe_recipient ="femme";


       QDialog *d=new Dialog(this);
       d->show();

       d->exec();
}

void MainWindow::on_return_send_emailButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_add_local_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_return_add_localButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_add_localButton_clicked()
{
    //remove old values from ui
    //ui->endroitEdit->setText("");
    //ui->idEdit->setText("");
    //ui->entreprise_localEdit->setText("");
    //ui->prix_heureEdit->setText("");
   // ui->nbpmaxEdit->setText("");
    //get values from ui
    QString endroit=ui->endroitEdit->text();
    QString id=ui->idEdit->text();
    QString entreprise=ui->entreprise_localEdit->text();
    QString type;

         //assign string to type based on which radiobutton is selected
    if (ui->terrain_couvertButton->isChecked()) type="terrain couvert";
    else if (ui->terrain_non_couvertButton->isChecked()) type="terrain non couvert";
    else if (ui->salle_de_feteButton->isChecked()) type="salle de fete";
    else if (ui->hotelButton->isChecked()) type="hotel";
    else type="";
    int prix = ui->prix_heureEdit->text().toInt();
    int nb_personne = ui->nbpmaxEdit->text().toInt();
    if (id=="" or entreprise=="" or type=="" or endroit=="" or prix<=0 or nb_personne<=0)
       { QMessageBox::critical(nullptr, QObject::tr("Ajouter d'une voiture"),
                           QObject::tr("Invalid entry!\n"
                                       "Click Ok to close."), QMessageBox::Ok); }
    local l(id,endroit,type,nb_personne,entreprise,prix);
    bool test=l.ajouter_local();
    if (test==true)
    {  ui->table_local->setModel(localtemp.afficher_local()); //actualiser la table
        QMessageBox::information(nullptr, QObject::tr("Ajout d'un local"),
                                 QObject::tr("un local a été ajoutée."), QMessageBox::Ok); }
    else {  QMessageBox::critical(nullptr, QObject::tr("Ajout d'un local"),
                                     QObject::tr("l'ajout a échoué."), QMessageBox::Cancel); }


    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_search_local_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    /* ui->critere_1_local->addItem("Endroit");
     ui->critere_1_local->addItem("Nombre de personnes");
     ui->critere_1_local->addItem("Entreprise");
     ui->critere_1_local->addItem("Prix minimal");
     ui->critere_1_local->addItem("Prix maximal");
     ui->critere_1_local->addItem("Type:Hôtel");
     ui->critere_1_local->addItem("Type:Terrain couvert");
     ui->critere_1_local->addItem("Type:Terrain-non-couvert");
     ui->critere_1_local->addItem("Type:Salle de fêtes");

     ui->critere_2_local->addItem("Endroit");
     ui->critere_2_local->addItem("Nombre de personnes");
     ui->critere_2_local->addItem("Entreprise");
     ui->critere_2_local->addItem("Prix minimal");
     ui->critere_2_local->addItem("Prix maximal");
     ui->critere_2_local->addItem("Type:Hôtel");
     ui->critere_2_local->addItem("Type:Terrain couvert");
     ui->critere_2_local->addItem("Type:Terrain-non-couvert");
     ui->critere_2_local->addItem("Type:Salle de fêtes");

     ui->critere_3_local->addItem("Endroit");
     ui->critere_3_local->addItem("Nombre de personnes");
     ui->critere_3_local->addItem("Entreprise");
     ui->critere_3_local->addItem("Prix minimal");
     ui->critere_3_local->addItem("Prix maximal");
     ui->critere_3_local->addItem("Type:Hôtel");
     ui->critere_3_local->addItem("Type:Terrain couvert");
     ui->critere_3_local->addItem("Type:Terrain-non-couvert");
     ui->critere_3_local->addItem("Type:Salle de fêtes");*/

}

void MainWindow::on_return_search_localButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_showlist_local_clicked()
{
     ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_return_local_listButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_email_local_clicked()
{
    QDialog *d=new Dialog(this);
    d->show();
    d->exec();
}

void MainWindow::on_deconnexion_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_quit_clicked()
{
    close();
}

void MainWindow::on_supprimer_car_listButton_clicked()
{
    QString matricule=ui->car_listEdit->text();
    bool test=cartemp.supprimer_car(matricule);
    if (test) {  ui->table_car->setModel(cartemp.afficher_car()); //actualiser la table
        QMessageBox::information(nullptr, QObject::tr("Suppression d'une voiture"),
                                 QObject::tr("une voiture a été supprimée."), QMessageBox::Ok); }
    else {  QMessageBox::critical(nullptr, QObject::tr("Suppression d'une voiture"),
                                     QObject::tr("la suppression a échoué."), QMessageBox::Cancel); }

}

void MainWindow::on_modifier_car_listButton_clicked()
{
    if (ui->modifier_car_listButton->isChecked())
           {
               //ui->modifier_car_listButton->setDisabled(true);
               ui->modifier_car_listButton->setText("Modifiable");
               QSqlTableModel *tableModel= new QSqlTableModel();
               tableModel->setTable("CAR");
               tableModel->select();
               ui->table_car->setModel(tableModel);
           }
           else
           {
               ui->modifier_car_listButton->setText("Modifier");
               ui->table_car->setModel(cartemp.afficher_car());

           }

}

void MainWindow::on_imprimer_car_listButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);



        QSqlQuery q;
        q.prepare("SELECT * FROM CAR ");
        q.exec();
        QString pdf="<br> <img src='C:/Users/malek/Desktop/Module_location/image/thebigdaylogo.png' height='42' width='120'/> < img src='C:/Users/malek/Desktop/Module_location/image/vanguardslogo.png' height='42' width='100'/> <h1  style='color:red'>LISTE DES VOITURES  <br></h1>\n <br> <table>  <tr>  <th>Matricule </th>  <th>couleur </th> <th> entreprise </th>  <th>marque </th> <th>prix </th>   </tr>" ;


        while ( q.next()) {

            pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"</td>     <td>" + q.value(1).toString() +"</td>   <td>" +q.value(4).toString() +"  "" " "</td>   <td>"+q.value(3).toString()+"</td>   <td>"+q.value(2).toString()+" "   " " "</td> " ;

        }
        QTextDocument doc;
        doc.setHtml(pdf);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);

}

void MainWindow::on_search_carButton_clicked()
{
    QString marque=ui->critere_marqueEdit->text();
    QString couleur=ui->critere_couleurEdit->text();
    QString entreprise=ui->critere_entrepriseEdit->text();
    if (ui->checkBox_marque->isChecked() && ui->checkBox_couleur->isChecked() && ui->checkBox_entreprise->isChecked())
       {

           QSqlQueryModel *verif_combinaison=cartemp.rechercher_combinaison_all(marque,couleur,entreprise);
           if (verif_combinaison!=nullptr)
           {
               ui->table_car->setModel(verif_combinaison);
           }

       }
    else if (!ui->checkBox_marque->isChecked() && ui->checkBox_couleur->isChecked() && !ui->checkBox_entreprise->isChecked())
       {
           QSqlQueryModel *verif_couleur=cartemp.rechercher_couleur(couleur);
           if (verif_couleur!=nullptr)
           {
               ui->table_car->setModel(verif_couleur);
           }
       }
    else if (ui->checkBox_marque->isChecked() && !ui->checkBox_couleur->isChecked() && !ui->checkBox_entreprise->isChecked())
       {
           QSqlQueryModel *verif_marque=cartemp.rechercher_marque(marque);
           if (verif_marque!=nullptr)
           {
               ui->table_car->setModel(verif_marque);
           }
       }
    else if (!ui->checkBox_marque->isChecked() && !ui->checkBox_couleur->isChecked() && ui->checkBox_entreprise->isChecked())
       {
           QSqlQueryModel *verif_entreprise=cartemp.rechercher_entreprise(entreprise);
           if (verif_entreprise!=nullptr)
           {
               ui->tableView->setModel(verif_entreprise);
           }
       }
    else if (ui->checkBox_marque->isChecked() && ui->checkBox_couleur->isChecked() && !ui->checkBox_entreprise->isChecked())
       {
           QSqlQueryModel *verif_marque_couleur=cartemp.rechercher_combinaison_marque_couleur(marque,couleur);
           if (verif_marque_couleur!=nullptr)
           {
               ui->tableView->setModel(verif_marque_couleur);
           }
       }
    else if (ui->checkBox_marque->isChecked() && !ui->checkBox_couleur->isChecked() && ui->checkBox_entreprise->isChecked())
       {
           QSqlQueryModel *verif_marque_entreprise=cartemp.rechercher_combinaison_marque_entreprise(marque,entreprise);
           if (verif_marque_entreprise!=nullptr)
           {
               ui->tableView->setModel(verif_marque_entreprise);
           }
       }
    else if (!ui->checkBox_marque->isChecked() && ui->checkBox_couleur->isChecked() && ui->checkBox_entreprise->isChecked())
       {
           QSqlQueryModel *verif_couleur_entreprise=cartemp.rechercher_combinaison_couleur_entreprise(couleur,entreprise);
           if (verif_couleur_entreprise!=nullptr)
           {
               ui->tableView->setModel(verif_couleur_entreprise);
           }
       }
    ui->critere_marqueEdit->setText("");
    ui->critere_entrepriseEdit->setText("");
    ui->critere_couleurEdit->setText("");
}

void MainWindow::on_imprimer_car_listButton_2_clicked()
{
    pie *d=new pie(this);
    d->show();
    d->exec();
}

void MainWindow::on_supprimer_local_listButton_clicked()
{
    QString id=ui->local_listEdit->text();
    bool test=localtemp.supprimer_local(id);
    if (test) {  ui->table_local->setModel(localtemp.afficher_local()); //actualiser la table
        QMessageBox::information(nullptr, QObject::tr("Suppression d'un local"),
                                 QObject::tr("un local a été supprimé."), QMessageBox::Ok); }
    else {  QMessageBox::critical(nullptr, QObject::tr("Suppression d'un local"),
                                     QObject::tr("la suppression a échoué."), QMessageBox::Cancel); }

}

void MainWindow::on_modifier_local_listButton_clicked()
{
    if (ui->modifier_local_listButton->isChecked())
           {

               ui->modifier_local_listButton->setText("Modifiable");
               QSqlTableModel *tableModel= new QSqlTableModel();
               tableModel->setTable("local");
               tableModel->select();
               ui->table_local->setModel(tableModel);
           }
           else
           {
               ui->modifier_local_listButton->setText("Modifier");
               ui->table_local->setModel(localtemp.afficher_local());

           }

}

void MainWindow::on_search_localButton_clicked()
{
    QString endroit=ui->critere_endroitEdit->text();
    QString entreprise=ui->critere_entrepriseEdit_2->text();
    QString type;
         //assign string to type based on which radiobutton is selected
    if (ui->critere_terraincouvert->isChecked()) type="terrain couvert";
    else if (ui->critere_terrainnoncouvert->isChecked()) type="terrain non couvert";
    else if (ui->critere_salledefete->isChecked()) type="salle de fete";
    else if (ui->critere_hotel->isChecked()) type="hotel";
    else type="";
    if (ui->checkBox_type->isChecked() && ui->checkBox_endroit->isChecked() && ui->checkBox_entreprise_2->isChecked())
       {

           QSqlQueryModel *verif_combinaison=localtemp.rechercher_combinaison_all(type,endroit,entreprise);
           if (verif_combinaison!=nullptr)
           {
               ui->tableView_2->setModel(verif_combinaison);
           }

       }
    else if (!ui->checkBox_type->isChecked() && ui->checkBox_endroit->isChecked() && !ui->checkBox_entreprise_2->isChecked())
       {
           QSqlQueryModel *verif_endroit=localtemp.rechercher_endroit(endroit);
           if (verif_endroit!=nullptr)
           {
               ui->tableView_2->setModel(verif_endroit);
           }
       }
    else if (ui->checkBox_type->isChecked() && !ui->checkBox_endroit->isChecked() && !ui->checkBox_entreprise_2->isChecked())
       {
           QSqlQueryModel *verif_type=localtemp.rechercher_type(type);
           if (verif_type!=nullptr)
           {
               ui->tableView_2->setModel(verif_type);
           }
       }
    else if (!ui->checkBox_type->isChecked() && !ui->checkBox_endroit->isChecked() && ui->checkBox_entreprise_2->isChecked())
       {
           QSqlQueryModel *verif_entreprise=localtemp.rechercher_entreprise(entreprise);
           if (verif_entreprise!=nullptr)
           {
               ui->tableView_2->setModel(verif_entreprise);
           }
       }
    else if (ui->checkBox_type->isChecked() && ui->checkBox_endroit->isChecked() && !ui->checkBox_entreprise_2->isChecked())
       {
           QSqlQueryModel *verif_type_endroit=localtemp.rechercher_combinaison_type_endroit(type,endroit);
           if (verif_type_endroit!=nullptr)
           {
               ui->tableView_2->setModel(verif_type_endroit);
           }
       }
    else if (ui->checkBox_type->isChecked() && !ui->checkBox_endroit->isChecked() && ui->checkBox_entreprise_2->isChecked())
       {
           QSqlQueryModel *verif_type_entreprise=localtemp.rechercher_combinaison_type_entreprise(type,entreprise);
           if (verif_type_entreprise!=nullptr)
           {
               ui->tableView_2->setModel(verif_type_entreprise);
           }
       }
    else if (!ui->checkBox_type->isChecked() && ui->checkBox_endroit->isChecked() && ui->checkBox_entreprise_2->isChecked())
       {
           QSqlQueryModel *verif_endroit_entreprise=localtemp.rechercher_combinaison_entreprise_endroit(entreprise,endroit);
           if (verif_endroit_entreprise!=nullptr)
           {
               ui->tableView_2->setModel(verif_endroit_entreprise);
           }
       }
    ui->critere_endroitEdit->setText("");
    ui->critere_entrepriseEdit_2->setText("");

}

void MainWindow::on_imprimer_local_listButton_clicked()

{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);



        QSqlQuery q;
        q.prepare("SELECT * FROM LOCAL ");
        q.exec();
        QString pdf="<br> <img src='C:/Users/malek/Desktop/Module_location/image/thebigdaylogo.png' height='42' width='120'/> < img src='C:/Users/malek/Desktop/Module_location/image/vanguardslogo.png' height='42' width='100'/> <h1  style='color:red'>LISTE DES LOCAUX  <br></h1>\n <br> <table>  <tr>  <th>id </th>  <th>endroit </th> <th> entreprise </th>  <th>type </th> <th>prix </th> <th>nb_personne </th>  </tr>" ;


        while ( q.next()) {

            pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"</td>     <td>" + q.value(4).toString() +"</td>   <td>" +q.value(1).toString() +"  "" " "</td>   <td>"+q.value(2).toString()+"</td>   <td>"+q.value(3).toString()+" "   " " "</td> <td> "+q.value(5).toString()+" "   " " "</td> " ;

        }
        QTextDocument doc;
        doc.setHtml(pdf);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);

}
//*******************************************************************
//***************************************************************
//*****************************************************************
/*************************************************************/

//MODULE ORGANISATION
void MainWindow::on_buttonajouter_org_clicked()
    {

        bool test_saisie=true;
        int id_animateur=ui->lineEdit_id_org->text().toInt();
        if(id_animateur<1111 || id_animateur>9999)
        { //test_saisie de saisie
            test_saisie = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajout id "),
                        QObject::tr("ID invalide!\n"
                                    "OK pour quitter."), QMessageBox::Ok);
        }
        QString nom=ui->lineEdit_nom_org->text();
        if(nom==""||nom.size()>20)
        {
            test_saisie = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajout un nom"),
                        QObject::tr("nom vide/limite atteinte!\n"
                                    "OK pour quitter."), QMessageBox::Ok);
        }
        QString adresse=ui->lineEdit_adresse_org->text();
        if(adresse==""||adresse.size()>100)
        {
            test_saisie = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajout adresse "),
                        QObject::tr("adresse vide!/limite atteinte\n"
                                    "OK pour quitter."), QMessageBox::Ok);
        }
        QString description=ui->lineEdit_description_org->text();
        if(description==""||description.size()>500)
        {
            test_saisie = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajout description "),
                        QObject::tr("description vide ou trop longue!\n"
                                    "OK pour quitter."), QMessageBox::Ok);
        }
        QString contacts=ui->lineEdit_contacts_org->text();
        if(contacts==""||contacts.size()>200)
        {
            test_saisie = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajouter contacts "),
                        QObject::tr("contacts trop long ou vide!\n"
                                    "OK pour quitter."), QMessageBox::Ok);
        }
        int prix=ui->lineEdit_prix_org->text().toInt();
        if(prix<0)
        { //test_saisie de saisie
            test_saisie = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajout prix"),
                        QObject::tr("prix negatif\n"
                                    "OK pour quitter."), QMessageBox::Ok);
        }
        if (test_saisie==true)
        {

        animateur a(id_animateur,nom,adresse,description,prix,contacts);
        bool test=a.ajouter();
        if (test)
            {
            ui->tableView_4_org->setModel(tempanimateur.afficher());
           QMessageBox::information(nullptr,QObject::tr("Ajout animateur"),
                                    QObject::tr("animateur ajouté.\n"
                                                "Click to exit"), QMessageBox::Cancel);
            }
        }else
            QMessageBox::critical(nullptr, QObject::tr("Ajout animateur"),
                        QObject::tr("Erreur !.\n"
                                    "OK pour quitter."), QMessageBox::Ok);
    }


void MainWindow::on_pushButton_3_org_clicked()
{
    int id=ui->lineEdit_supprimer_org->text().toInt();
    bool test=tempanimateur.supprimer(id);
    if (test)
    {   ui->tableView_4_org->setModel(tempanimateur.afficher());
        QMessageBox::information(nullptr,"Suppression Animateur","Supprimé avec succés");
    }
    else
{
        QMessageBox::warning(nullptr,"Suppression Animateur","Echec de supression");

}

}

void MainWindow::on_pushButton_4_org_clicked()//imprimer pdf
{
    QPrinter printer;
    printer.setPrinterName("desirer printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog::Rejected) return;
    ui->tableView_4_org->render(&printer);


}

void MainWindow::on_search_carButton_8_org_clicked()//search animateur
{

    int i=ui->lineEdit_org->text().toInt();
    ui->tableView_4_org->setModel(tempanimateur.recherche(i));
}

void MainWindow::on_pushButton_6_org_clicked() //refresh animateur
{
    ui->tableView_4_org->setModel(tempanimateur.afficher());
}

void MainWindow::on_pushButton_7_org_clicked() //modifier animateur
{
    if (ui->pushButton_7_org->isChecked())
           {
               //ui->pushButton_7->setDisabled(true);
               ui->pushButton_7_org->setText("Modifiable");
               QSqlTableModel *tableModel= new QSqlTableModel();
               tableModel->setTable("ANIMATEUR");
               tableModel->select();
               ui->tableView_4_org->setModel(tableModel);
           }
           else
           {
               ui->pushButton_7_org->setText("Modifier");
               ui->tableView_4_org->setModel(tempanimateur.afficher());

           }

}

void MainWindow::on_buttonajouter_2_org_clicked() //ajouter traiteur
{
    {

        bool test_saisie=true;
        int id_traiteur=ui->lineEdit_id_2_org->text().toInt();
        if(id_traiteur<1111 || id_traiteur>9999)
        { //test_saisie de saisie
            test_saisie = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajout id "),
                        QObject::tr("ID invalide!\n"
                                    "OK pour quitter."), QMessageBox::Ok);
        }
        QString nom=ui->lineEdit_nom_2_org->text();
        if(nom==""||nom.size()>20)
        {
            test_saisie = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajout un nom"),
                        QObject::tr("nom vide/limite atteinte!\n"
                                    "OK pour quitter."), QMessageBox::Ok);
        }
        QString adresse=ui->lineEdit_adresse_2_org->text();
        if(adresse==""||adresse.size()>100)
        {
            test_saisie = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajout adresse "),
                        QObject::tr("adresse vide!/limite atteinte\n"
                                    "OK pour quitter."), QMessageBox::Ok);
        }
        QString description=ui->lineEdit_description_2_org->text();
        if(description==""||description.size()>500)
        {
            test_saisie = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajout description "),
                        QObject::tr("description vide ou trop longue!\n"
                                    "OK pour quitter."), QMessageBox::Ok);
        }
        QString contacts=ui->lineEdit_contacts_2_org->text();
        if(contacts==""||contacts.size()>200)
        {
            test_saisie = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajouter contacts "),
                        QObject::tr("contacts trop long ou vide!\n"
                                    "OK pour quitter."), QMessageBox::Ok);
        }
        int prix=ui->lineEdit_prix_2_org->text().toInt();
        if(prix<0)
        { //test_saisie de saisie
            test_saisie = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajout prix"),
                        QObject::tr("prix negatif\n"
                                    "OK pour quitter."), QMessageBox::Ok);
        }
        if (test_saisie==true)
        {

        traiteur a(id_traiteur,nom,adresse,description,prix,contacts);
        bool test=a.ajouter();
        if (test)
            {
            ui->tableView_5_org->setModel(temptraiteur.afficher());
           QMessageBox::information(nullptr,QObject::tr("Ajout traiteur"),
                                    QObject::tr("traiteur ajouté.\n"
                                                "Click to exit"), QMessageBox::Cancel);
            }
        }else
            QMessageBox::critical(nullptr, QObject::tr("Ajout traiteur"),
                        QObject::tr("Erreur !.\n"
                                    "OK pour quitter."), QMessageBox::Ok);
    }

}

void MainWindow::on_search_carButton_9_org_clicked() //recherche traiteur
{
    int i=ui->lineEdit_8_org->text().toInt();
    ui->tableView_5_org->setModel(temptraiteur.recherche(i));
}

void MainWindow::on_pushButton_11_org_clicked() //modifier traiteur
{
    if (ui->pushButton_11_org->isChecked())
           {
               //ui->pushButton_11_org->setDisabled(true);
               ui->pushButton_11_org->setText("Modifiable");
               QSqlTableModel *tableModel= new QSqlTableModel();
               tableModel->setTable("traiteur");
               tableModel->select();
               ui->tableView_5_org->setModel(tableModel);
           }
           else
           {
               ui->pushButton_11_org->setText("Modifier");
               ui->tableView_5_org->setModel(temptraiteur.afficher());

           }
}

void MainWindow::on_pushButton_8_org_clicked() //excel
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                        tr("Fichiers d'extension Excel (*.xls)"));
        if (fileName.isEmpty())
            return;

        ExportExcelObject obj(fileName, "mydata", ui->tableView_5_org);

        // you can change the column order and
        // choose which colum to export
        obj.addField(0, "Identifiant", "char(20)");
        obj.addField(1, "Nom", "char(20)");
        obj.addField(2, "Adresse", "char(20)");
        obj.addField(3, "Description", "char(20)");
        obj.addField(4, "Prix", "char(20)");
        obj.addField(5, "Contacts", "char(20)");


        int retVal = obj.export2Excel();

        if( retVal > 0)
        {
            QMessageBox::information(this, tr("FAIS!"),
                                     QString(tr("%1 enregistrements exportés!")).arg(retVal)
                                     );
        }
}

void MainWindow::on_pushButton_9_org_clicked() //pdf
{
    QPrinter printer;
    printer.setPrinterName("desirer printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog::Rejected) return;
    ui->tableView_5_org->render(&printer);
}

void MainWindow::on_pushButton_12_org_clicked() //supprimer traiteur
{
    int id=ui->lineEdit_supprimer_2_org->text().toInt();
    bool test=temptraiteur.supprimer(id);
    if (test)
    {   ui->tableView_5_org->setModel(temptraiteur.afficher());
        QMessageBox::information(nullptr,"Suppression traiteur","Supprimé avec succés");
    }
    else
{
        QMessageBox::warning(nullptr,"Suppression traiteur","Echec de supression");

}
}

void MainWindow::on_pushButton_5_org_clicked()//excel
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                        tr("Fichiers d'extension Excel (*.xls)"));
        if (fileName.isEmpty())
            return;

        ExportExcelObject obj(fileName, "mydata", ui->tableView_4_org);

        // you can change the column order and
        // choose which colum to export
        obj.addField(0, "ID", "char(20)");
        obj.addField(1, "Nom", "char(20)");
        obj.addField(2, "Adresse", "char(20)");
        obj.addField(3, "Description", "char(20)");
        obj.addField(4, "Prix", "char(20)");
        obj.addField(5, "Contacts", "char(20)");


        int retVal = obj.export2Excel();

        if( retVal > 0)
        {
            QMessageBox::information(this, tr("FAIS!"),
                                     QString(tr("%1 enregistrements exportés!")).arg(retVal)
                                     );
        }
}

void MainWindow::on_pushButton_10_org_clicked()
{
    ui->tableView_5_org->setModel(temptraiteur.afficher());
}

//void MainWindow::on_buttonquitter_6_org_clicked()
//{
 //   close();
//}

void MainWindow::on_buttonquitter_org_clicked()
{
   close();
}

void MainWindow::on_buttonsedeconn_org_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_buttonquitter_2_org_clicked()
{
    close();
}

void MainWindow::on_buttonsedeconn_2_org_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_back_4_org_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_buttonquitter_3_org_clicked()
{
    close();
}

void MainWindow::on_buttonsedeconn_3_org_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_back_3_org_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_buttonquitter_4_org_clicked()
{
    close();
}

void MainWindow::on_buttonsedeconn_4_org_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_back_2_org_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_buttonquitter_5_org_clicked()
{
    close();
}

void MainWindow::on_buttonsedeconn_5_org_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_button_traiteur_org_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_button_decorateur_org_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_buttonanimateur_org_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_buttonprofil_org_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}

void MainWindow::on_back_org_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}
void MainWindow::on_buttonajouter_3_org_clicked()
{

}
void MainWindow::on_login_button_org_clicked()
{

}

//*****************************************************
//******************************************************
/*******************************************************/

  //MODULE MARKETING

void MainWindow::on_buton_ajouter_mar_clicked()
{
this->ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_4_mar_clicked()
{

    offre o;
    this->ui->tableView_mar->setModel(o.afficher());
    this->ui->stackedWidget->setCurrentIndex(2) ;
}

void MainWindow::on_boutonsupprimer_mar_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(3) ;
}

void MainWindow::on_bouton_modifier_mar_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(4) ;
}

void MainWindow::on_retour4_mar_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_2_mar_clicked()
{
close();
        }

void MainWindow::on_RETOUR1_mar_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_3_mar_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_lineEdit_mar_textChanged(const QString &arg1)
{
    offre o;
    if (arg1=="")
    this->ui->tableView_mar->setModel(o.afficher());
    else
    this->ui->tableView_mar->setModel(o.rechercher2(arg1));


}

void MainWindow::on_pushButton_5_mar_clicked()
{
     int id=ui->id_ajout_mar->text().toInt();
    offre o(id,this->ui->nom_ajout_mar->text(),this->ui->dated_ajout_mar->text(),this->ui->datef_ajout_mar->text());
    if(o.ajouter())
    {
      ui->tableView_mar->setModel(o.afficher());
      MainWindow::notif("Ajout reussi","Ajout reussi");
}}

void MainWindow::on_SUPPRIMER_mar_clicked()
{ offre o;
    QString id=ui->id_supp_mar->text();
    if(o.supprimer(id))
    {this->ui->tableView_mar->setModel(o.afficher());
        this->ui->stackedWidget->setCurrentIndex(1) ;
     MainWindow::notif("supression reussite","supression reussite");}
}

void MainWindow::on_MODIF_mar_clicked()
{
    int id=ui->id_Modif_mar->text().toInt();
   offre o(id,this->ui->nom_Modif_mar->text(),this->ui->dated_Modif_mar->text(),this->ui->datef_Modif_mar->text());
   if(o.modifier())
   {this->ui->stackedWidget->setCurrentIndex(15);
     ui->tableView_mar->setModel(o.afficher());
     MainWindow::notif("Modification reussie","Modification reussie");

   }

}
void MainWindow::notif(QString t,QString m)
{
    QPixmap p(32,32);
    p.load("\\chemin mte3ek");
    QIcon icon(p);
    QSystemTrayIcon n(icon);
    n.setVisible(true);
    n.showMessage(t,m,QSystemTrayIcon::Information,1000);

}



void MainWindow::on_pushButton_8_mar_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_eventsupprimer_2_mar_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_retour4_2_mar_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(18);
}

void MainWindow::on_pushButton_11_mar_clicked()
{
   this->ui->stackedWidget->setCurrentIndex(18);
}

void MainWindow::on_pushButton_12_mar_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_RETOUR1_3_mar_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(19);
}

void MainWindow::on_retour4_5_mar_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(19);
}

void MainWindow::on_event_ajouter_2_mar_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_event_afficher_mar_clicked()
{
    evenement e;
    this->ui->stackedWidget->setCurrentIndex(9);
     ui->tableView_2_mar->setModel(e.afficher());
}

void MainWindow::on_event_modifier_2_mar_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_9_mar_clicked()
{

    int id=ui->id_ajout_2_mar->text().toInt();
   evenement e(id,this->ui->nom_ajout_2_mar->text(),this->ui->date_ajout_2_mar->text());
   if(e.ajouter())
   {
     ui->tableView_2_mar->setModel(e.afficher());
     MainWindow::notif("Ajout reussi","Ajout reussi");
}

}

void MainWindow::on_lineEdit_2_mar_textChanged(const QString &arg1)
{
    evenement e;
    if (arg1=="")
    this->ui->tableView_2_mar->setModel(e.afficher());
    else
    this->ui->tableView_2_mar->setModel(e.rechercher2(arg1));
}

void MainWindow::on_SUPPRIMER_3_mar_clicked()
{

    evenement e;
        QString id=ui->id_supp_3_mar->text();
        if(e.supprimer(id))
        {this->ui->tableView_2_mar->setModel(e.afficher());
            this->ui->stackedWidget->setCurrentIndex(8) ;
         MainWindow::notif("supression reussite","supression reussite");}

}

void MainWindow::on_pushButton_24_mar_clicked()
{
    int id=ui->id_ajout_5_mar->text().toInt();
  evenement e(id,this->ui->nom_ajout_5_mar->text(),this->ui->date_ajout_4_mar->text());
   if(e.modifier())
   {
     ui->tableView_2_mar->setModel(e.afficher());}
this->ui->stackedWidget->setCurrentIndex(19);
MainWindow::notif("Modification reussie","Modification reussie");

}

void MainWindow::on_pushButton_7_mar_clicked()
{
     this->ui->stackedWidget->setCurrentIndex(19);
}



void MainWindow::on_pushButton_13_mar_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(15);
}



/*void MainWindow::on_pushButton_6_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

        // We need to set the username (your email address) and the password
        // for smtp authentification.

        smtp.setUser("zied.soukni@esprit.tn");
        smtp.setPassword("181JMT0077");

        // Now we create a MimeMessage object. This will be the email.

        MimeMessage message;

        message.setSender(new EmailAddress("zied.soukni@esprit.tn", "Zied Soukni"));
        message.addRecipient(new EmailAddress(ui->lineEdit_adresse->text(), "client"));
        message.setSubject(ui->lineEdit_sujet->text());

        // Now add some text to the email.
        // First we create a MimeText object.

        MimeText text;

        text.setText(ui->lineEdit_contenu->text());

        // Now add it to the mail

        message.addPart(&text);

        // Now we can send the mail

        smtp.connectToHost();
        smtp.login();
        smtp.sendMail(message);
        smtp.quit();
}*/



void MainWindow::on_pushButton_65_mar_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(17);

}

void MainWindow::on_pushButton_14_mar_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(15);

}

void MainWindow::on_retour4_3_mar_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(18);

}



void MainWindow::on_pushButton_mar_clicked()
{
    QString strStream;
                QTextStream out(&strStream);

                const int rowCount = ui->tableView_2_mar->model()->rowCount();
                const int columnCount = ui->tableView_2_mar->model()->columnCount();
                QString TT = QDate::currentDate().toString("dd/mm/yyyy");
                out <<"<html>\n"
                      "<head>\n"
                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    << "<title>ERP - COMmANDE LIST<title>\n "
                    << "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<h1 style=\"text-align: center;\"><strong> ******LISTE DES SESSIONS ****** "+TT+"</strong></h1>"
                    "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                      "</br> </br>";
                // headers
                out << "<thead><tr bgcolor=#d6e5ff>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tableView_2_mar->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tableView_2_mar->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tableView_2_mar->isColumnHidden(column)) {
                            QString data =ui->tableView_2_mar->model()->data(ui->tableView_2_mar->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table>\n"
                    "</body>\n"
                    "</html>\n";

                QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);

                QPrinter printer;

                QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                if (dialog->exec() == QDialog::Accepted)
                {
                    document->print(&printer);
                }

                delete document;

}



void MainWindow::on_pushButton_10_mar_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(7);

}

void MainWindow::on_pushButton_15_mar_clicked()
{
    close();
}


void MainWindow::on_SUPPRIMER_2_mar_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(16);

}

void MainWindow::on_SUPPRIMER_4_mar_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(20);

}



void MainWindow::on_tri_mar_clicked()
{
    offre o;
       /*QString critere=ui->cb_historique->currentText();*/
           QString mode;
            if (ui->rb_asc_historique_mar->isChecked()==true)
       {
                ui->tableView_mar->setModel(o.trie());


       }
            else if(ui->rb_desc_historique_mar->isChecked()==true)

                ui->tableView_mar->setModel(o.trie2());
}

void MainWindow::on_recherche_mar_clicked()
{
    offre P;
       QString text;

       if (ui->rid_mar->isChecked()==true)
      {
      text=ui->rech_mar->text();
        if(text == "")
        {
            ui->tableView_mar->setModel(P.afficher());
        }

        else
        {
            ui->tableView_mar->setModel(P.chercher_offre_id(text));
        }
       }


      if(ui->rnom_mar->isChecked()==true)
       {
           text=ui->rech_mar->text();
                if(text == "")

                {
                    ui->tableView_mar->setModel(P.afficher());

                }

                else

                {
                    ui->tableView_mar->setModel(P.chercher_offre_nom(text));
                }

       }

        else if     (ui->rdate_mar->isChecked()==true)
        {

            text=ui->rech_mar->text();
                 if(text == "")

                 {
                     ui->tableView_mar->setModel(P.afficher());
                 }

                 else

                 {
                     ui->tableView_mar->setModel(P.chercher_offre_datedebut(text));
                 }
        }
}




void MainWindow::on_trii_mar_clicked()
{

    evenement o;
       /*QString critere=ui->cb_historique->currentText();*/
           QString mode;
            if (ui->radioButton_mar->isChecked()==true)
       {
                ui->tableView_2_mar->setModel(o.trie());


       }
            else if(ui->radioButton_2_mar->isChecked()==true)

                ui->tableView_2_mar->setModel(o.trie2());
}



void MainWindow::on_recherchee_mar_clicked()
{
    evenement P;
           QString text;

           if (ui->ridd_mar->isChecked()==true)
          {
          text=ui->ra_mar->text();
            if(text == "")
            {
                ui->tableView_2_mar->setModel(P.afficher());
            }

            else
            {
                ui->tableView_2_mar->setModel(P.chercher_evenement_id(text));
            }
           }


          if(ui->nomm_mar->isChecked()==true)
           {
               text=ui->ra_mar->text();
                    if(text == "")

                    {
                        ui->tableView_2_mar->setModel(P.afficher());

                    }

                    else

                    {
                        ui->tableView_2_mar->setModel(P.chercher_evenement_nom(text));
                    }

           }

            else if     (ui->datess_mar->isChecked()==true)
            {

                text=ui->ra_mar->text();
                     if(text == "")

                     {
                         ui->tableView_2_mar->setModel(P.afficher());
                     }

                     else

                     {
                         ui->tableView_2_mar->setModel(P.chercher_evenement_dates(text));
                     }
            }
}

//********************************************
//***********************************
//*****************************/

//module graphisme

/*void MainWindow::on_Login_graphisme_clicked()
{

   if (cn.loginconnection( ui->id->text(), ui->password->text()))
   {
          ui->stackedWidget->setCurrentIndex(2);
    } else
        { qDebug()<< "non";

}
}*/

void MainWindow::on_Button_espacegraphistes_clicked()
{
  ui->stackedWidget->setCurrentIndex(23);


}

void MainWindow::on_button_espace_photographes_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);


}

void MainWindow::on_ajouter_photographe_clicked()
{
  int id = ui->lineedit_id->text().toInt();
    QString nom = ui->lineedit_nom->text();
    QString prenom = ui->lineedit_prenom->text();
    int tel = ui->lineeedit_tel->text().toInt();
    QString adresse = ui->lineedit_adresse->text();
    Photographe P(id,nom,prenom,tel,adresse);
    bool test =P.ajouter();
      if (test)

     {
        ui->tablephotographes->setModel(tempphoto.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout photographe"),
                                 QObject::tr("photographe ajouté :"), QMessageBox::Cancel);

       Ard.write_to_arduino("1");
      }
      else {  Ard.write_to_arduino("0"); }

      QPropertyAnimation *animation;
      animation = new QPropertyAnimation(ui->ajouter_photographe,"geometry");
      animation->setDuration(1000);
      animation->setStartValue(QRect(300,260,75,23));
      animation->setEndValue(QRect(300,260,150,23));
      animation->setEasingCurve(QEasingCurve::InOutQuint);
      animation->start();

}

void MainWindow::on_ajouter_graphiste_clicked()
{
    int id = ui->_lineedit_id_2->text().toInt();
    QString nom = ui->_lineedit_nom_2->text();
    QString prenom = ui->_lineedit_prenom_2->text();
    int tel = ui->_lineeedit_tel_2->text().toInt();
    QString adresse = ui->_lineedit_adresse_2->text();
    Graphiste g(id,nom,prenom,tel,adresse);
    bool test =g.ajouter();
      if (test)

     {
          ui->tablegraphistes->setModel(tempgraph.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout graphiste"),
                                 QObject::tr("graphiste ajouté :"), QMessageBox::Cancel);

        Ard.write_to_arduino("1");
     }
      else {  Ard.write_to_arduino("0"); }

      QPropertyAnimation *animation;
      animation = new QPropertyAnimation(ui->ajouter_graphiste,"geometry");
      animation->setDuration(1000);
      animation->setStartValue(QRect(300,260,75,23));
      animation->setEndValue(QRect(300,260,150,23));
      animation->setEasingCurve(QEasingCurve::InOutQuint);
      animation->start();
}



void MainWindow::on_supprimer_graphiste_clicked()
{
    int id = ui->lineEdit_3->text().toInt();
     bool test = tempgraph.supprimer(id);
     if (test)
      {
         ui->tablegraphistes->setModel(tempgraph.afficher());
       QMessageBox::information(nullptr, QObject::tr(" suppression graphiste "),
                              QObject::tr("graphiste supprimé :"), QMessageBox::Cancel);
      }
     QPropertyAnimation *animation;
     animation = new QPropertyAnimation(ui->supprimer_graphiste,"geometry");
     animation->setDuration(1000);
     animation->setStartValue(QRect(350,170,121,31));
     animation->setEndValue(QRect(350,170,150,31));
     animation->setEasingCurve(QEasingCurve::InOutQuint);
     animation->start();
}


void MainWindow::on_supprimer_photographe_clicked()
{
    int id = ui->lineEdit_2->text().toInt();
     bool test = tempphoto.supprimer(id);
     if (test)
      {
         ui->tablephotographes->setModel(tempphoto.afficher());
       QMessageBox::information(nullptr, QObject::tr(" suppression photographe "),
                              QObject::tr("photographe supprimé :"), QMessageBox::Cancel);
      }
     QPropertyAnimation *animation;
     animation = new QPropertyAnimation(ui->supprimer_photographe,"geometry");
     animation->setDuration(1000);
     animation->setStartValue(QRect(350,170,121,31));
     animation->setEndValue(QRect(350,170,150,31));
     animation->setEasingCurve(QEasingCurve::InOutQuint);
     animation->start();
}


void MainWindow::on_modifier_photographe_clicked()
{
    if (ui->modifier_photographe->isChecked())
        {
            ui->modifier_photographe->setDisabled(true);
            ui->modifier_photographe->setText("Modifiable");
            QSqlTableModel *tableModel= new QSqlTableModel();
            tableModel->setTable("PHOTO");
            tableModel->select();
            ui->tablephotographes->setModel(tableModel);
        }
        else
        {
            ui->modifier_photographe->setText("Modifier");
            ui->tablephotographes->setModel(tempphoto.afficher());

        }
    QPropertyAnimation *animation;
    animation = new QPropertyAnimation(ui->modifier_photographe,"geometry");
    animation->setDuration(1000);
    animation->setStartValue(QRect(380,230,81,20));
    animation->setEndValue(QRect(380,230,150,20));
    animation->setEasingCurve(QEasingCurve::InOutQuint);
    animation->start();
}

void MainWindow::on_modifier_graphiste_clicked()
{
    if (ui->modifier_graphiste->isChecked())
        {
            ui->modifier_graphiste->setDisabled(true);
            ui->modifier_graphiste->setText("Modifiable");
            QSqlTableModel *tableModel= new QSqlTableModel();
            tableModel->setTable("GRAPHISTE");
            tableModel->select();
            ui->tablegraphistes->setModel(tableModel);
        }
        else
        {
            ui->modifier_graphiste->setText("Modifier");
            ui->tablegraphistes->setModel(tempgraph.afficher());

        }
    QPropertyAnimation *animation;
    animation = new QPropertyAnimation(ui->modifier_graphiste,"geometry");
    animation->setDuration(1000);
    animation->setStartValue(QRect(380,230,81,20));
    animation->setEndValue(QRect(380,230,150,20));
    animation->setEasingCurve(QEasingCurve::InOutQuint);
    animation->start();
}


void MainWindow::on_retour_clicked()
{
     ui->stackedWidget->setCurrentIndex(21);
}


void MainWindow::on_tri_photographe_clicked()
{
    Photographe p;
       /*QString critere=ui->cb_historique->currentText();*/
           QString mode;
            if (ui->rb_asc_historique->isChecked()==true)
       {
                ui->tablephotographes->setModel(p.trie());


       }
            else if(ui->rb_desc_historique->isChecked()==true)

                ui->tablephotographes->setModel(p.trie2());

{
            QPropertyAnimation *animation;
            animation = new QPropertyAnimation(ui->tri_photographe,"geometry");
            animation->setDuration(1000);
            animation->setStartValue(QRect(420,130,75,23));
            animation->setEndValue(QRect(420,130,75,23));
            animation->setEasingCurve(QEasingCurve::InOutQuint);
            animation->start();
}
}


void MainWindow::on_tri_graphiste_clicked()
{
    Graphiste g;
       /*QString critere=ui->cb_historique->currentText();*/
           QString mode;
            if (ui->_rb_asc_historique_2->isChecked()==true)
       {
                ui->tablegraphistes->setModel(g.trie());


       }
            else if(ui->_rb_desc_historique_2->isChecked()==true)

                ui->tablegraphistes->setModel(g.trie2());
{
            QPropertyAnimation *animation;
            animation = new QPropertyAnimation(ui->tri_graphiste,"geometry");
            animation->setDuration(1000);
            animation->setStartValue(QRect(420,130,75,23));
            animation->setEndValue(QRect(420,130,75,23));
            animation->setEasingCurve(QEasingCurve::InOutQuint);
            animation->start();

}
}


void MainWindow::on_quit_button_clicked()
{
    close();
}


void MainWindow::on_recherche_photographe_clicked()
{
    Photographe P;
    QString text;

    if (ui->radioButton_ID->isChecked()==true)
   {
   text=ui->lineEdit_rechercher->text();
     if(text == "")
     {
         ui->tablephotographes->setModel(P.afficher());
     }

     else
     {
         ui->tablephotographes->setModel(P.chercher_photo_id(text));
     }
    }


   if(ui->radioButton_nom->isChecked()==true)
    {
        text=ui->lineEdit_rechercher->text();
             if(text == "")

             {
                 ui->tablephotographes->setModel(P.afficher());

             }

             else

             {
                 ui->tablephotographes->setModel(P.chercher_photo_nom(text));
             }

    }

     else if     (ui->radioButton_prenom->isChecked()==true)
     {

         text=ui->lineEdit_rechercher->text();
              if(text == "")

              {
                  ui->tablephotographes->setModel(P.afficher());
              }

              else

              {
                  ui->tablephotographes->setModel(P.chercher_photo_prenom(text));
              }
     }

   QPropertyAnimation *animation;
   animation = new QPropertyAnimation(ui->recherche_mar,"geometry");
   animation->setDuration(1000);
   animation->setStartValue(QRect(420,10,75,23));
   animation->setEndValue(QRect(420,10,150,23));
   animation->setEasingCurve(QEasingCurve::InOutQuint);
   animation->start();
}

void MainWindow::on_rechercher_graphiste_clicked()
{
    Graphiste g;
    QString text;

    if (ui->_radioButton_ID_2->isChecked()==true)
   {
   text=ui->_lineEdit_rechercher_2->text();
     if(text == "")
     {
         ui->tablegraphistes->setModel(g.afficher());
     }

     else
     {
         ui->tablegraphistes->setModel(g.chercher_photo_id(text));
     }
    }


   if(ui->_radioButton_nom_2->isChecked()==true)
    {
        text=ui->_lineEdit_rechercher_2->text();
             if(text == "")

             {
                 ui->tablegraphistes->setModel(g.afficher());

             }

             else

             {
                 ui->tablegraphistes->setModel(g.chercher_photo_nom(text));
             }

    }

     else if     (ui->_radioButton_prenom_2->isChecked()==true)
     {

         text=ui->_lineEdit_rechercher_2->text();
              if(text == "")

              {
                  ui->tablegraphistes->setModel(g.afficher());
              }

              else

              {
                  ui->tablegraphistes->setModel(g.chercher_photo_prenom(text));
              }
     }

   QPropertyAnimation *animation;
   animation = new QPropertyAnimation(ui->rechercher_graphiste,"geometry");
   animation->setDuration(1000);
   animation->setStartValue(QRect(420,10,75,23));
   animation->setEndValue(QRect(420,10,150,23));
   animation->setEasingCurve(QEasingCurve::InOutQuint);
   animation->start();
}


void MainWindow::on_exporterpdf_photographe_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("liste_photographes.pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        QSqlQuery q;
        q.prepare("SELECT * FROM PHOTO ");
        q.exec();
        QString pdf="<br> <img src='C:/Users/wissa/OneDrive/Bureau/projet/logo.png' height='42' width='144'/> <h1  style='color:red'>       LISTE DES PHOTOGRAPHES  <br></h1>\n <br> <table>  <tr>  <th> ID </th> <th> NOM </th> <th> PRENOM </th> <th> TEL  </th> <th> E-MAIL </th>  </tr>" ;


        while ( q.next()) {

            pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"    </td>  <td>" + q.value(1).toString() +"</td>  <td>" +q.value(2).toString() +"</td>      <td>     "+q.value(3).toString()+"</td>       <td>    "+q.value(4).toString()+"</td>" ;

        }
        doc.setHtml(pdf);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);

        QPropertyAnimation *animation;
        animation = new QPropertyAnimation(ui->exporterpdf_photographe,"geometry");
        animation->setDuration(1000);
        animation->setStartValue(QRect(390,290,91,23));
        animation->setEndValue(QRect(390,290,150,23));
        animation->setEasingCurve(QEasingCurve::InOutQuint);
        animation->start();
}

void MainWindow::on_exporterpdf_graphiste_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("liste_GRAPHISTES.pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        QSqlQuery q;
        q.prepare("SELECT * FROM GRAPHISTE ");
        q.exec();
        QString pdf="<br> <img src='C:/Users/wissa/OneDrive/Bureau/projet/logo.png' height='42' width='144'/> <h1  style='color:red'>       LISTE DES GRAPHISTES  <br></h1>\n <br> <table>  <tr>  <th> ID </th> <th> NOM </th> <th> PRENOM </th> <th> TEL  </th> <th> E-MAIL </th>  </tr>" ;


        while ( q.next()) {

            pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"    </td>  <td>   " + q.value(1).toString() +"</td>  <td>" +q.value(2).toString() +"  "" " "</td>      <td>     "+q.value(3).toString()+"--------"+"</td>       <td>"+q.value(4).toString()+"       </td>" ;

        }
        doc.setHtml(pdf);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);

        QPropertyAnimation *animation;
        animation = new QPropertyAnimation(ui->exporterpdf_graphiste,"geometry");
        animation->setDuration(1000);
        animation->setStartValue(QRect(390,290,91,23));
        animation->setEndValue(QRect(390,290,150,23));
        animation->setEasingCurve(QEasingCurve::InOutQuint);
        animation->start();
}

void MainWindow::on_selectionnermail_photographe_clicked()
{
    QDialog *d=new Dialog(this);
    d->show();

    d->exec();
}

void MainWindow::on_selectionnermail_graphiste_clicked()
{
    QDialog *d=new Dialog(this);
    d->show();

    d->exec();
}


void MainWindow::on_retour2_clicked()
{
 ui->stackedWidget->setCurrentIndex(21);
}


void MainWindow::on__quit_button_2_clicked()
{
    close();
}

void MainWindow::readdata(){
    //qDebug()<<A.read_from_arduino();
}

void MainWindow::showTime(){
    ui->timer->setText(QTime::currentTime().toString("hh:mm:ss"));

}

//********************************************
//***********************************
//*****************************/

//Module Beauté


//***********Coiffeurs************



void MainWindow::on_pushButton_maillocat_clicked()//page du mailing locat
{
    QDialog *d=new Dialog(this);
    d->show();

    d->exec();
}

void MainWindow::on_pushButton_mailcoiff_clicked()//page du mailing coiff
{
    QDialog *d=new Dialog(this);
    d->show();

    d->exec();
}


void MainWindow::on_tableView_coiff_activated(const QModelIndex &index)//affichage liste coiff
{
    QString val=ui->tableView_coiff->model()->data(index).toString();
    QSqlQuery q;
    q.prepare("select * from COIFFEURS where NOM='"+val+"'");
    if(q.exec())
    {
        while (q.next()) {
            ui->lineEdit_nomcoiff->setText(q.value(0).toString());
            ui->lineEdit_adrcoiff->setText(q.value(1).toString());
            ui->lineEdit_numcoiff->setText(q.value(2).toString());

            ui->lineEdit_prxcoiff->setText(q.value(3).toString());

        }
}
}


void MainWindow::on_pushButton_ajoutcoiff_clicked()//ajout coiffeur
{
    QString nom=ui->lineEdit_nomcoiff->text();
    QString adresse=ui->lineEdit_adrcoiff->text();
    int num=ui->lineEdit_numcoiff->text().toInt();
     int prix=ui->lineEdit_prxcoiff->text().toInt();
     QString operateur;

     QString num_string=QString :: number(num);

     if (num_string[0] == "9")
             operateur = "Telecom";
           if (num_string[0] == "2")
             operateur = "Ooredoo";
           if (num_string[0] == "5")
             operateur = "Orange";



  /* qDebug()<<nom;
        qDebug()<<adresse;
            qDebug()<<num;
           qDebug()<<prix;*/


    coiffeurs coiff(nom,adresse,operateur,num,prix);
    bool test=coiff.ajouter();
    if(test)
{
    ui->tableView_coiff->setModel(coiff.afficher());
    QMessageBox::information(nullptr, QObject::tr("Ajouter un coiff"),
                      QObject::tr("coif ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    ui->lineEdit_nomcoiff->setText("");
    ui->lineEdit_adrcoiff->setText("");
    ui->lineEdit_numcoiff->setText("");
    ui->lineEdit_prxcoiff->setText("");
    }
      else
       { QMessageBox::critical(nullptr, QObject::tr("Ajouter un coiff"),
                      QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);}
}



void MainWindow::on_fm_coiff_clicked()//modifier un coiff
{
    QString nom =ui->lineEdit_nomcoiff->text();
       QString adresse =ui->lineEdit_adrcoiff->text();
       int numero=ui->lineEdit_numcoiff->text().toInt();
       int prix =ui->lineEdit_prxcoiff->text().toInt();
        QString operateur;
       coiffeurs coiff(nom,adresse,operateur,numero,prix);
          bool test=coiff.modifier(nom);
          if(test)
        {
              ui->lineEdit_nomcoiff->setText("");
                       ui->lineEdit_adrcoiff->setText("");
                       ui->lineEdit_numcoiff->setText("");
                       ui->lineEdit_prxcoiff->setText("");
                ui->tableView_coiff->setModel(coiff.afficher());//afficher tableau coiff

        QMessageBox::information(nullptr, QObject::tr("modifier un coiffeur"),
                          QObject::tr("modifié.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

        }
          else
              QMessageBox::critical(nullptr, QObject::tr("modifier"),
                          QObject::tr("non modifié !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_fs_coiff_clicked()//supprimer un coif
{
    QString i = ui->lineEdit_nomcoiff->text();
        bool test = coiff.supprimer(i);

        if (i=="")
            test=false;
        if(test){
            ui->tableView_coiff->setModel(coiff.afficher());
            QMessageBox::information(nullptr,"supression coiffeurs","coiffeurs supprimée avec succes.");}
}



void MainWindow::on_pushButton_rechcoiff_clicked()//recherche coiff
{
    /* QString nom=ui->nomrecherche_an->text();
       ui->tableView_2->setModel(coiff.recherche_nom(nom));*/

       QString rech=ui->nomrecherche_coiff->text();
       if(rech!="")  { ui->tableView_coiff->setModel(coiff.recherche(rech)); }
       else{ QMessageBox::information(this,"Pour chercher il Faut","tapez quelque chose !");
       ui->tableView_coiff->setModel(coiff.afficher());
   }
}


void MainWindow::on_upanim_ascoif_clicked()//tri asc coiff
{
    if(ui->comboBox_coif->currentIndex()==0)
       ui->tableView_coiff->setModel(coiff.afficherup_nom());
       else if(ui->comboBox_coif->currentIndex()==1)
       ui->tableView_coiff->setModel(coiff.afficherup_prix());
}



void MainWindow::on_downanim_dscoiff_clicked()//tri desc coiff
{
    if(ui->comboBox_coif->currentIndex()==0)
       ui->tableView_coiff->setModel(coiff.afficherdown_nom());
       else if(ui->comboBox_coif->currentIndex()==1)
       ui->tableView_coiff->setModel(coiff.afficherdown_prix());
}



void MainWindow::on_nomrecherche_coiff_textChanged(const QString &arg1)//entrer un texte dans la barre de rech coiff
{
    if(arg1=="")
{  ui->tableView_coiff->setModel(coiff.afficher());  }
}

void MainWindow::on_pushButton_quitcoiff_2_clicked()//fermer la fenetre
{
    close();
}

void MainWindow::on_pushButton_rtcoiff_clicked()//retour a la page du menu
{
  ui->stackedWidget->setCurrentIndex(0);
}
//***********Locateurs************


void MainWindow::on_tableView_locat_activated(const QModelIndex &index)//affichage liste locat
{
    QString val=ui->tableView_locat->model()->data(index).toString();
              QSqlQuery q;
              q.prepare("SELECT * FROM LOCATEURS WHERE NOML='"+val+"'");
              if(q.exec())
              {
                  while (q.next()) {
                      ui->lineEdit_nomlocat->setText(q.value(0).toString());
                      ui->lineEdit_adrlocat->setText(q.value(1).toString());
                      ui->lineEdit_numlocat->setText(q.value(2).toString());
                      ui->lineEdit_prxlocat->setText(q.value(3).toString());

                  }
              }
}



void MainWindow::on_pushButton_ajoutlocat_clicked()//ajout locat
{
    QString noml=ui->lineEdit_nomlocat->text();
          QString adressel=ui->lineEdit_adrlocat->text();
          int numerol=ui->lineEdit_numlocat->text().toInt();
          int prixl=ui->lineEdit_prxlocat->text().toInt();
         locateurs locat1(noml,adressel,numerol,prixl);
          bool test=locat1.ajouter();
          if(test){
                   ui->tableView_locat->setModel(locat.afficher());
                   QMessageBox::information(nullptr,"ajout locateurs","locateurs ajoutée avec succes.");
                   ui->lineEdit_nomlocat->setText("");
                   ui->lineEdit_adrlocat->setText("");
                   ui->lineEdit_numlocat->setText("");
                   ui->lineEdit_prxlocat->setText("");
               }
               else QMessageBox::warning(nullptr,"ajout locateurs","locateurs non ajoutée.");

}



void MainWindow::on_fm_locat_clicked()//modifier locat
{
    QString noml =ui->lineEdit_nomlocat->text();
       QString adressel =ui->lineEdit_adrlocat->text();
       int numerol=ui->lineEdit_numlocat->text().toInt();
       int prixl =ui->lineEdit_prxlocat->text().toInt();
       QString numl=QString::number(numerol);
       QString prxl=QString::number(prixl);
       locateurs locat(noml,adressel,numerol,prixl);
          bool test=locat.modifier(noml);
          if(test)
        {
              ui->tableView_locat->setModel(locat.afficher());//afficher tableau locat
              ui->lineEdit_nomlocat->setText(noml);
              ui->lineEdit_adrlocat->setText(adressel);
              ui->lineEdit_numlocat->setText(numl);
              ui->lineEdit_prxlocat->setText(prxl);

        QMessageBox::information(nullptr, QObject::tr("modifier un locateurs"),
                          QObject::tr("modifié.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}
}


void MainWindow::on_fs_locat_clicked()//supprimer un locat
{
    QString i = ui->lineEdit_nomlocat->text();
        bool test = locat.supprimer(i);

        if (i=="")
            test=false;
        if(test){
            ui->tableView_locat->setModel(locat.afficher());
            QMessageBox::information(nullptr,"supression locateurs","locateurs supprimée avec succes.");

        }
        else QMessageBox::warning(nullptr,"supression locateurs","locateurs non supprimée.");
}



void MainWindow::on_upanim_aslocat_clicked()//tri asc locat
{
    if(ui->comboBox_locat->currentIndex()==0)
       ui->tableView_locat->setModel(locat.afficherup_nom());
       else if(ui->comboBox_locat->currentIndex()==1)
       ui->tableView_locat->setModel(locat.afficherup_prix());
}



void MainWindow::on_downanim_dslocat_clicked()//tri desc locat
{
    if(ui->comboBox_locat->currentIndex()==0)
      ui->tableView_locat->setModel(locat.afficherdown_nom());
      else if(ui->comboBox_locat->currentIndex()==1)
      ui->tableView_locat->setModel(locat.afficherdown_prix());
}



void MainWindow::on_pushButton_rechlocat_clicked()//recherche locat
{
    /* QString noml=ui->nomrecherche_locat->text();
      ui->tableView_locat->setModel(locat.recherche_nom(nom));*/

      QString rech=ui->nomrecherche_locat->text();
      if(rech!="")  { ui->tableView_locat->setModel(locat.recherche(rech)); }
      else{ QMessageBox::information(this,"Pour chercher il Faut","tapez quelque chose !");
      ui->tableView_locat->setModel(locat.afficher());
  }
}



void MainWindow::on_nomrecherche_locat_textChanged(const QString &arg1)
{

        if(arg1=="")
    {  ui->tableView_locat->setModel(locat.afficher());  }
}



//******************statistique coiff****************


void MainWindow::on_pushButton_statcoiff_clicked()
{
    int res;
        statistiques w(this);
        w.setWindowTitle("Statistiques des operateurs");

        res = w.exec();
        qDebug() << res;
        if (res == QDialog::Rejected)
          return;
}



//MOSLEMMMM*************************************************

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(25);
}

void MainWindow::on_pushButton_3_clicked()
{
     ui->stackedWidget->setCurrentIndex(26);
}

//slots employe
void MainWindow::on_pb_ok_clicked()
{
    int id = ui->idtxt->text().toInt();
    int cin= ui->cintxt_3->text().toInt();

    QString nom= ui->nomtxt_3->text();
    QString prenom= ui->prenomtxt_3->text();

    QString role= ui->roletxt->currentText();

  emp t(id,cin,nom,prenom,role);
  bool test=t.ajouter();
  if(test)
{
      MainWindow::on_pb_actualiser_5_clicked();
QMessageBox::information(nullptr, QObject::tr("Ajouter un employe"),
                  QObject::tr("employe ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un employe"),
                  QObject::tr("Erreur ! Check your data !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_actualiser_5_clicked()
{

    QString ha = ui->tri_2->currentText();

    if(ha == "ID")
    {
        ui->tab_15->setModel(t.afficher());
        ui->supptxt->setModel(t.afficher());
    }
    if(ha == "PRENOM")
    {
        ui->tab_15->setModel(t.afficher2());
        ui->supptxt->setModel(t.afficher2());
    }
    if(ha == "ROLE")
    {
        ui->tab_15->setModel(t.afficher3());
        ui->supptxt->setModel(t.afficher3());
    }
}

void MainWindow::on_pb_supprimer_2_clicked()
{
    int id = ui->supptxt->currentText().toInt();

    bool test=t.supprimer(id);
    if(test)
    {MainWindow::on_pb_actualiser_5_clicked();//refresh

        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_15->setModel(t.afficher());


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_modifierp_5_clicked()
{
    int id = ui->idtxt->text().toInt();
    QString res= QString::number(id);
    int cin = ui->cintxt_3->text().toInt();
    QString res1= QString::number(cin);
    QString nom = ui->nomtxt_3->text();
    QString prenom = ui->prenomtxt_3->text();

    QString role = ui->roletxt->currentText();

    QSqlQuery query;
    query.prepare ("update employes set cin='"+res1+"',nom = '"+nom+"',prenom = '"+prenom+"',role='"+role+"' where id = '"+res+"'");

    if(query.exec())
    {
        MainWindow::on_pb_actualiser_5_clicked();
        QMessageBox::information(this,tr("Edit"),tr("Updated Successfully, Press 'Actualiser' to Apply changes !"));
    }
    else QMessageBox::critical(this,tr("Edit"),tr("Update Failed !"));
}











void MainWindow::on_pb_modifierp_6_clicked() //recherche
{
    QString nom = ui->Snomtxt_2->text();
    QString prenom = ui->Sprenomtxt_2->text();
    QString CIN = ui->SCIN_2->text();

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from EMPLOYES where nom = '"+nom+"' OR prenom = '"+prenom+"' OR CIN = '"+CIN+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ROLE"));


    ui->Stab_2->setModel(model);

}


//slot client
void MainWindow::on_pb_ok_2_clicked()
{

    int cin= ui->cintxt_2->text().toInt();

    QString nom= ui->nomtxt_2->text();
    QString prenom= ui->prenomtxt_2->text();
    QString coiff= ui->coi_2->currentText();

    QString voiture= ui->voit_2->currentText();
    QString offre= ui->off_2->currentText();
    QString trait= ui->trait_2->currentText();

    QString deco= ui->deco_2->currentText();
    QString cerem= ui->certxt_2->currentText();
    QString cost= ui->cost_2->currentText();

    QString local= ui->loc_2->currentText();
    QString music= ui->mus_2->currentText();
    QString photo= ui->pho_2->currentText();


  client c(cin,nom,prenom,offre,cerem,photo,local,voiture,music,trait,deco,cost,coiff);
  bool test=c.ajouter();
  if(test)
{
      MainWindow::on_pb_actualiser_2_clicked();
QMessageBox::information(nullptr, QObject::tr("Ajouter un employe"),
                  QObject::tr("employe ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un employe"),
                  QObject::tr("Erreur ! Check your data !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pb_actualiser_2_clicked()
{
    QString ha = ui->tri->currentText();

    if(ha == "CIN")
    {
        ui->tab_14->setModel(c.afficher());
        ui->supptxt->setModel(c.afficher());
    }
    if(ha == "PRENOM")
    {
        ui->tab_14->setModel(c.afficher3());
        ui->supptxt->setModel(c.afficher3());
    }
    if(ha == "NOM")
    {
        ui->tab_14->setModel(c.afficher4());
        ui->supptxt->setModel(c.afficher4());
    }
}

void MainWindow::on_pb_supprimer_clicked()
{
    int cin = ui->supptxt->currentText().toInt();

    bool test=c.supprimer(cin);
    if(test)
    {MainWindow::on_pb_actualiser_2_clicked();//refresh

        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_14->setModel(c.afficher());

}
}

void MainWindow::on_pb_modifierp_2_clicked()
{
    int cin= ui->cintxt_2->text().toInt();
    QString res= QString::number(cin);

    QString nom= ui->nomtxt_2->text();
    QString prenom= ui->prenomtxt_2->text();
    QString coiff= ui->coi_2->currentText();

    QString voiture= ui->voit_2->currentText();
    QString offre= ui->off_2->currentText();
    QString trait= ui->trait_2->currentText();

    QString deco= ui->deco_2->currentText();
    QString cerem= ui->certxt_2->currentText();
    QString cost= ui->cost_2->currentText();

    QString local= ui->loc_2->currentText();
    QString music= ui->mus_2->currentText();
    QString photo= ui->pho_2->currentText();

    QSqlQuery query;
    query.prepare ("update CLIENTS set nom = '"+nom+"',prenom = '"+prenom+"',coiff = '"+coiff+"', voiture = '"+voiture+"' , offre = '"+offre+"', trait = '"+trait+"', deco = '"+deco+"', cerem = '"+cerem+"', cost = '"+cost+"', local = '"+local+"' , music = '"+music+"', photo = '"+photo+"' where CIN = '"+res+"'");

    if(query.exec())
    {
        MainWindow::on_pb_actualiser_2_clicked();
        QMessageBox::information(this,tr("Edit"),tr("Updated Successfully, Press 'Actualiser' to Apply changes !"));
    }
    else QMessageBox::critical(this,tr("Edit"),tr("Update Failed !"));
}

void MainWindow::on_pb_ok_3_clicked()
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

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(27);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(27);
}

void MainWindow::on_car_tri_clicked()
{



              if (ui->prix_croissant_car->isChecked()==true)

                  ui->table_car->setModel(cartemp.trie_asc());



              else if(ui->prix_decroissant_car->isChecked()==true)

                  ui->table_car->setModel(cartemp.trie_dsc());
}
void MainWindow::on_pushButton_valtemp_clicked()
{
temp=ui->lineEdit_valtemp->text().toInt();
}


void MainWindow::update_label_affichtemp(){
    data=Ard.read_from_arduino();
    int d=data.toInt();



    if(d > temp)//si la temperature ambiante > temperature donnee
       Ard.write_to_arduino("2");
    else

     if(d < temp)//si la temperature ambiante < temperature donnee
       Ard.write_to_arduino("3");

    //Ard.close_arduino();

}
