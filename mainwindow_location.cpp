#include "mainwindow_location.h"
#include "ui_mainwindow.h"
#include "send_email_location.h"
#include "pie_location.h"
#include <QMediaPlayer>
#include <QUrl>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->stackedWidget; no need for this
    ui->table_car->setModel(cartemp.afficher_car()); //actualiser la table
    ui->table_car->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_car->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->table_local->setModel(localtemp.afficher_local());
    ui->table_local->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_local->setSelectionMode(QAbstractItemView::SingleSelection);
    // mail_regex=QRegExp("^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_login_button_clicked()
{
 player.setMedia(QUrl::fromLocalFile("C:/Users/malek/Desktop/Module_location/The Voice_button sound effect.wav"));
player.setVolume(1.0);
 player.play();
    ui->stackedWidget->setCurrentIndex(1);
}

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
