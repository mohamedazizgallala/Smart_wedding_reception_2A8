#include "mainwindow_location.h"
#include "ui_mainwindow_location.h"
#include "send_email_location.h"
#include "pie_location.h"
#include <QMediaPlayer>
#include <QUrl>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //***********************
    //***********************

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

}

MainWindow::~MainWindow()
{
    delete ui;
}

//**************************************************
//*****************************
/****************/

     //general LOGIN
void MainWindow::on_login_button_clicked()
{
 /*player.setMedia(QUrl::fromLocalFile("C:/Users/malek/Desktop/Module_location/The Voice_button sound effect.wav"));
player.setVolume(1.0);
 player.play();*/

   QSqlQuery query;
    QMessageBox msgBox;



        QString id =ui->id->text(), pw=ui->password->text(),type="";
        query.prepare("SELECT role FROM employe WHERE id =:id and password=:pw");
        query.bindValue(":id", id);
        query.bindValue(":pw",pw);
        query.exec();

        /*QString idValue = query.boundValue(3).toString();
        someNumber = query.value(1).toString();
        msgBox.setText("The stock is: "+someNumber+"\nThe placeholder has the value: ");
        msgBox.exec();*/

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
      // else if (type=="marketing")
          // ui->stackedWidget->setCurrentIndex();
       //else if (type=="graphisme")
         //  ui->stackedWidget->setCurrentIndex();
       //else if (type=="beaute")
          // ui->stackedWidget->setCurrentIndex();
      // else if (type=="RH")
          // ui->stackedWidget->setCurrentIndex();
       }

}
 //********************************************
//***********************************
//*****************************/

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
               ui->tableView->setModel(verif_combinaison);
           }

       }
    else if (!ui->checkBox_marque->isChecked() && ui->checkBox_couleur->isChecked() && !ui->checkBox_entreprise->isChecked())
       {
           QSqlQueryModel *verif_couleur=cartemp.rechercher_couleur(couleur);
           if (verif_couleur!=nullptr)
           {
               ui->tableView->setModel(verif_couleur);
           }
       }
    else if (ui->checkBox_marque->isChecked() && !ui->checkBox_couleur->isChecked() && !ui->checkBox_entreprise->isChecked())
       {
           QSqlQueryModel *verif_marque=cartemp.rechercher_marque(marque);
           if (verif_marque!=nullptr)
           {
               ui->tableView->setModel(verif_marque);
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

//*****************************************************
//******************************************************
/*******************************************************/

  //MODULE MARKETING



