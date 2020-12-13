#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "photographe.h"
#include "graphiste.h"
#include <QDebug>
#include <QMediaPlayer>
#include <QWidget>
/*#include <QPrinter>
#include <QPrintDialog>*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
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


    ui->lineedit_id->setValidator(new QIntValidator(0,99999999,this));
    ui->_lineedit_id_2->setValidator(new QIntValidator(0,99999999,this));
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Login_graphisme_clicked()
{

   if (cn.loginconnection( ui->id->text(), ui->password->text()))
   {
          ui->stackedWidget->setCurrentIndex(2);
    } else
        { qDebug()<< "non";

}
}

void MainWindow::on_Button_espacegraphistes_clicked()
{
  ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_button_espace_photographes_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
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

     {  ui->tablephotographes->setModel(tempphoto.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout photographe"),
                                 QObject::tr("photographe ajouté :"), QMessageBox::Cancel);
     }
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

     {  ui->tablegraphistes->setModel(tempgraph.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout graphiste"),
                                 QObject::tr("graphiste ajouté :"), QMessageBox::Cancel);

     }
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
}


void MainWindow::on_retour_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
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
}



void MainWindow::on_envoyermail_photographe_clicked()
{
    Smtp * smtp=new Smtp("wissal.soudani@esprit.tn","wissalesprit","smtp.gmail.com",465);
    smtp->sendMail("wissal.soudani@esprit.tn",ui->recepteur->text(),ui->objet->text(),ui->msg->toPlainText());

}

void MainWindow::on_envoyermail_graphiste_clicked()
{
    Smtp * smtp=new Smtp("wissal.soudani@esprit.tn","wissalesprit","smtp.gmail.com",465);
    smtp->sendMail("wissal.soudani@esprit.tn",ui->recepteur_2->text(),ui->objet_2->text(),ui->msg_2->toPlainText());
}



void MainWindow::on_selectionnermail_photographe_clicked()
{
    QItemSelectionModel *select = ui->tablegraphistes->selectionModel();
    email_recipient =select->selectedRows(4).value(0).data().toString();
    ui->recepteur->setText(email_recipient);
}

void MainWindow::on_selectionnermail_graphiste_clicked()
{
    QItemSelectionModel *select = ui->tablegraphistes->selectionModel();
    email_recipient =select->selectedRows(4).value(0).data().toString();
    ui->recepteur_2->setText(email_recipient);
}



void MainWindow::on_retour2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on__quit_button_2_clicked()
{
    close();
}



