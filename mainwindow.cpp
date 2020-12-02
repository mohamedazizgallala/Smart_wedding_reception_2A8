#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPrintDialog>
#include <QPrinter>
#include <QSqlTableModel>
#include "exportexcelobject.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_4->setModel(tempanimateur.afficher());
    ui->tableView_4->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_4->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_5->setModel(temptraiteur.afficher());
    ui->tableView_5->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_5->setSelectionMode(QAbstractItemView::SingleSelection);


}

MainWindow::~MainWindow()
{
    delete ui;
}

 void MainWindow::on_buttonajouter_clicked()
    {

        bool test_saisie=true;
        int id_animateur=ui->lineEdit_id->text().toInt();
        if(id_animateur<1111 || id_animateur>9999)
        { //test_saisie de saisie
            test_saisie = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajout id "),
                        QObject::tr("ID invalide!\n"
                                    "OK pour quitter."), QMessageBox::Ok);
        }
        QString nom=ui->lineEdit_nom->text();
        if(nom==""||nom.size()>20)
        {
            test_saisie = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajout un nom"),
                        QObject::tr("nom vide/limite atteinte!\n"
                                    "OK pour quitter."), QMessageBox::Ok);
        }
        QString adresse=ui->lineEdit_adresse->text();
        if(adresse==""||adresse.size()>100)
        {
            test_saisie = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajout adresse "),
                        QObject::tr("adresse vide!/limite atteinte\n"
                                    "OK pour quitter."), QMessageBox::Ok);
        }
        QString description=ui->lineEdit_description->text();
        if(description==""||description.size()>500)
        {
            test_saisie = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajout description "),
                        QObject::tr("description vide ou trop longue!\n"
                                    "OK pour quitter."), QMessageBox::Ok);
        }
        QString contacts=ui->lineEdit_contacts->text();
        if(contacts==""||contacts.size()>200)
        {
            test_saisie = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajouter contacts "),
                        QObject::tr("contacts trop long ou vide!\n"
                                    "OK pour quitter."), QMessageBox::Ok);
        }
        int prix=ui->lineEdit_prix->text().toInt();
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
            ui->tableView_4->setModel(tempanimateur.afficher());
           QMessageBox::information(nullptr,QObject::tr("Ajout animateur"),
                                    QObject::tr("animateur ajouté.\n"
                                                "Click to exit"), QMessageBox::Cancel);
            }
        }else
            QMessageBox::critical(nullptr, QObject::tr("Ajout animateur"),
                        QObject::tr("Erreur !.\n"
                                    "OK pour quitter."), QMessageBox::Ok);
    }


void MainWindow::on_pushButton_3_clicked()
{
    int id=ui->lineEdit_supprimer->text().toInt();
    bool test=tempanimateur.supprimer(id);
    if (test)
    {   ui->tableView_4->setModel(tempanimateur.afficher());
        QMessageBox::information(nullptr,"Suppression Animateur","Supprimé avec succés");
    }
    else
{
        QMessageBox::warning(nullptr,"Suppression Animateur","Echec de supression");

}

}

void MainWindow::on_pushButton_4_clicked()//imprimer pdf
{
    QPrinter printer;
    printer.setPrinterName("desirer printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog::Rejected) return;
    ui->tableView_4->render(&printer);


}

void MainWindow::on_search_carButton_8_clicked()//search animateur
{

    int i=ui->lineEdit->text().toInt();
    ui->tableView_4->setModel(tempanimateur.recherche(i));
}




void MainWindow::on_pushButton_6_clicked()
{
    ui->tableView_4->setModel(tempanimateur.afficher());
}




void MainWindow::on_pushButton_7_clicked()
{
    if (ui->pushButton_7->isChecked())
           {
               //ui->pushButton_7->setDisabled(true);
               ui->pushButton_7->setText("Modifiable");
               QSqlTableModel *tableModel= new QSqlTableModel();
               tableModel->setTable("ANIMATEUR");
               tableModel->select();
               ui->tableView_4->setModel(tableModel);
           }
           else
           {
               ui->pushButton_7->setText("Modifier");
               ui->tableView_4->setModel(tempanimateur.afficher());

           }

}

void MainWindow::on_buttonajouter_2_clicked()
{
    {

        bool test_saisie=true;
        int id_traiteur=ui->lineEdit_id_2->text().toInt();
        if(id_traiteur<1111 || id_traiteur>9999)
        { //test_saisie de saisie
            test_saisie = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajout id "),
                        QObject::tr("ID invalide!\n"
                                    "OK pour quitter."), QMessageBox::Ok);
        }
        QString nom=ui->lineEdit_nom_2->text();
        if(nom==""||nom.size()>20)
        {
            test_saisie = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajout un nom"),
                        QObject::tr("nom vide/limite atteinte!\n"
                                    "OK pour quitter."), QMessageBox::Ok);
        }
        QString adresse=ui->lineEdit_adresse_2->text();
        if(adresse==""||adresse.size()>100)
        {
            test_saisie = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajout adresse "),
                        QObject::tr("adresse vide!/limite atteinte\n"
                                    "OK pour quitter."), QMessageBox::Ok);
        }
        QString description=ui->lineEdit_description_2->text();
        if(description==""||description.size()>500)
        {
            test_saisie = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajout description "),
                        QObject::tr("description vide ou trop longue!\n"
                                    "OK pour quitter."), QMessageBox::Ok);
        }
        QString contacts=ui->lineEdit_contacts_2->text();
        if(contacts==""||contacts.size()>200)
        {
            test_saisie = false;
            QMessageBox::critical(nullptr, QObject::tr("Ajouter contacts "),
                        QObject::tr("contacts trop long ou vide!\n"
                                    "OK pour quitter."), QMessageBox::Ok);
        }
        int prix=ui->lineEdit_prix_2->text().toInt();
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
            ui->tableView_5->setModel(temptraiteur.afficher());
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

void MainWindow::on_search_carButton_9_clicked()
{
    int i=ui->lineEdit_8->text().toInt();
    ui->tableView_5->setModel(temptraiteur.recherche(i));
}

void MainWindow::on_pushButton_11_clicked()
{
    if (ui->pushButton_11->isChecked())
           {
               //ui->pushButton_11->setDisabled(true);
               ui->pushButton_11->setText("Modifiable");
               QSqlTableModel *tableModel= new QSqlTableModel();
               tableModel->setTable("traiteur");
               tableModel->select();
               ui->tableView_5->setModel(tableModel);
           }
           else
           {
               ui->pushButton_11->setText("Modifier");
               ui->tableView_5->setModel(temptraiteur.afficher());

           }
}

void MainWindow::on_pushButton_8_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                        tr("Fichiers d'extension Excel (*.xls)"));
        if (fileName.isEmpty())
            return;

        ExportExcelObject obj(fileName, "mydata", ui->tableView_5);

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

void MainWindow::on_pushButton_9_clicked()
{
    QPrinter printer;
    printer.setPrinterName("desirer printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog::Rejected) return;
    ui->tableView_5->render(&printer);
}

void MainWindow::on_pushButton_12_clicked()
{
    int id=ui->lineEdit_supprimer_2->text().toInt();
    bool test=temptraiteur.supprimer(id);
    if (test)
    {   ui->tableView_5->setModel(temptraiteur.afficher());
        QMessageBox::information(nullptr,"Suppression traiteur","Supprimé avec succés");
    }
    else
{
        QMessageBox::warning(nullptr,"Suppression traiteur","Echec de supression");

}
}

void MainWindow::on_pushButton_5_clicked()//excel
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                        tr("Fichiers d'extension Excel (*.xls)"));
        if (fileName.isEmpty())
            return;

        ExportExcelObject obj(fileName, "mydata", ui->tableView_4);

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

void MainWindow::on_pushButton_10_clicked()
{
    ui->tableView_5->setModel(temptraiteur.afficher());
}

void MainWindow::on_login_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_buttonquitter_6_clicked()
{
    close();
}

void MainWindow::on_buttonquitter_clicked()
{
   close();
}

void MainWindow::on_buttonsedeconn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_buttonquitter_2_clicked()
{
    close();
}

void MainWindow::on_buttonsedeconn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_back_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_buttonquitter_3_clicked()
{
    close();
}

void MainWindow::on_buttonsedeconn_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_back_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_buttonquitter_4_clicked()
{
    close();
}

void MainWindow::on_buttonsedeconn_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_back_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_buttonquitter_5_clicked()
{
    close();
}

void MainWindow::on_buttonsedeconn_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_button_traiteur_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_button_decorateur_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_buttonanimateur_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_buttonprofil_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

