#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->stackedWidget; no need for this
    ui->table_car->setModel(cartemp.afficher_car()); //actualiser la table
    ui->table_car->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_car->setSelectionMode(QAbstractItemView::SingleSelection);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_login_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_add_car_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_add_carButton_clicked()
{
    QString marque=ui->marqueEdit->text();
    QString matricule=ui->matriculeEdit->text();
    QString entreprise=ui->entreprise_carEdit->text();
    QString couleur=ui->couleurEdit->text();
    int prix = ui->prix_jourEdit->text().toInt();
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
     ui->critere_1_car->addItem("Marque");
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
     ui->critere_3_car->addItem("Modèle");
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
     ui->stackedWidget->setCurrentIndex(5);
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
     ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_search_local_clicked()
{
     ui->stackedWidget->setCurrentIndex(7);
     ui->critere_1_local->addItem("Endroit");
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
     ui->critere_3_local->addItem("Type:Salle de fêtes");
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
     ui->stackedWidget->setCurrentIndex(5);
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
