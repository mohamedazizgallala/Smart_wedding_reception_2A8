#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "photographe.h"
#include <QDebug>
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget->setCurrentIndex(1);
    ui->tablephotographes->setModel(tempphoto.afficher());
    ui->tablephotographes->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tablephotographes->setSelectionMode(QAbstractItemView::SingleSelection);

    QItemSelectionModel *select = ui->tablephotographes->selectionModel();
    email_recipient =select->selectedRows(4).value(0).data().toString();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::login()
{

   if (cn.loginconnection( ui->id->text(), ui->password->text()))
   {
          ui->stackedWidget->setCurrentIndex(2);
    } else
        { qDebug()<< "non";

}
}

void MainWindow::on_Login_clicked()
{
   login();
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}



void MainWindow::on_ajouter_button_clicked()
{
    int id = ui->lineedit_id->text().toInt();
    QString nom = ui->lineedit_nom->text();
    QString prenom = ui->lineedit_prenom->text();
    int tel = ui->lineeedit_tel->text().toInt();
    QString adresse = ui->lineedit_adresse->text();
    Photographe P(id,nom,prenom,tel,adresse);
    bool test =P.ajouter();
      if (test)

     {  ui->tablephotographes->setModel(tempphoto.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout photographe"),
                                 QObject::tr("photographe ajouté :"), QMessageBox::Cancel);

     }

}

void MainWindow::on_SUPPRIMER8BUTTON_clicked()
{
   int id = ui->lineEdit_2->text().toInt();
    bool test = tempphoto.supprimer(id);
    if (test)
     {
        ui->tablephotographes->setModel(tempphoto.afficher());
      QMessageBox::information(nullptr, QObject::tr(" suppression photographe "),
                             QObject::tr("photographe supprimé :"), QMessageBox::Cancel);
     }
 }



void MainWindow::on_modifier_button_clicked()
{
    if (ui->modifier_button->isChecked())
        {
            ui->modifier_button->setDisabled(true);
            ui->modifier_button->setText("Modifiable");
            QSqlTableModel *tableModel= new QSqlTableModel();
            tableModel->setTable("PHOTO");
            tableModel->select();
            ui->tablephotographes->setModel(tableModel);
        }
        else
        {
            ui->modifier_button->setText("Modifier");
            ui->tablephotographes->setModel(tempphoto.afficher());

        }
}


void MainWindow::on_pushButton_3_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_tri_button_clicked()
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
}


void MainWindow::on_quit_button_clicked()
{
    close();
}


void MainWindow::on_pushButton_recherche_clicked()
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
}

void MainWindow::on_pushButton_2_clicked()
{
    Smtp * smtp=new Smtp("wissal.soudani@esprit.tn","wissalesprit","smtp.gmail.com",465);
    smtp->sendMail("wissal.soudani@esprit.tn",ui->recepteur->text(),ui->objet->text(),ui->msg->toPlainText());

}

void MainWindow::on_pushButton_4_clicked()
{
    QItemSelectionModel *select = ui->tablephotographes->selectionModel();
    email_recipient =select->selectedRows(4).value(0).data().toString();
    ui->recepteur->setText(email_recipient);
}


