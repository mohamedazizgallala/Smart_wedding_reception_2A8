#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "coiffeurs.h"
#include "locateurs.h"
#include <qtableview.h>
#include "stat.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->client=NULL;
    //coiff
    ui->tableView_coiff->setModel(coiff.afficher());
    //locat
    ui->tableView_locat->setModel(locat.afficher());
   // ui->tableView_locat->setModel(locat.afficher());
    ui->stackedWidget->setCurrentIndex(0);






    //***********************************insert image*********************


    //*******login*****
    QPixmap pix("C:/Users/HP/Desktop/projet/Module final/resources/login.png");//login
    int w1 = ui->label->width();
    int h1 = ui->label->height();
    ui->label->setPixmap(pix.scaled(w1,h1,Qt::KeepAspectRatio));


    QPixmap pix1("C:/Users/HP/Desktop/projet/Module final/resources/retry.png");//retour a la login
    int wret = ui->label_40->width();
    int hret = ui->label_40->height();
    ui->label_40->setPixmap(pix1.scaled(wret,hret,Qt::KeepAspectRatio));


   /* QPixmap pixic("C:/Users/HP/Desktop/projet/Module final/resources/icon.png");//icon
    int wic = ui->label_26->width();
    int hic = ui->label_26->height();
    ui->label_26->setPixmap(pixic.scaled(wic,hic,Qt::KeepAspectRatio));*/


    //******interface coiffeures*****
    QPixmap pixmail("C:/Users/HP/Desktop/projet/Module final/resources/mail.png");//mail  coif
     int w3 = ui->label_10->width();
     int h4 = ui->label_10->height();
     ui->label_10->setPixmap(pixmail.scaled(w3,h4,Qt::KeepAspectRatio));

     QPixmap pixstat("C:/Users/HP/Desktop/projet/Module final/resources/stat.png");//stat coif
      int ws = ui->label_11->width();
      int hs = ui->label_11->height();
      ui->label_11->setPixmap(pixstat.scaled(ws,hs,Qt::KeepAspectRatio));

     QPixmap pixmodif("C:/Users/HP/Desktop/projet/Module final/resources/modif.png");//modifier coif
      int w5 = ui->label_12->width();
      int h6 = ui->label_12->height();
      ui->label_12->setPixmap(pixmodif.scaled(w5,h6,Qt::KeepAspectRatio));

      QPixmap pixsupp("C:/Users/HP/Desktop/projet/Module final/resources/del.png");//supprimer coiff
       int wsup = ui->label_13->width();
       int hsup = ui->label_13->height();
       ui->label_13->setPixmap(pixsupp.scaled(wsup,hsup,Qt::KeepAspectRatio));

       QPixmap pixadd("C:/Users/HP/Desktop/projet/Module final/resources/add.png");//ajouter coiff
        int wad = ui->label_14->width();
        int had = ui->label_14->height();
        ui->label_14->setPixmap(pixadd.scaled(wad,had,Qt::KeepAspectRatio));

        QPixmap pixcoif("C:/Users/HP/Desktop/projet/Module final/resources/coiff.png");//coiffeur
         int wc = ui->label_22->width();
         int hc = ui->label_22->height();
         ui->label_22->setPixmap(pixcoif.scaled(wc,hc,Qt::KeepAspectRatio));

        QPixmap pixrech("C:/Users/HP/Desktop/projet/Module final/resources/search.png");//rechercher un coiff
          int wr = ui->label_24->width();
          int hr = ui->label_24->height();
          ui->label_24->setPixmap(pixrech.scaled(wr,hr,Qt::KeepAspectRatio));


        QPixmap pixenrg1("C:/Users/HP/Desktop/projet/Module final/resources/enreg.png");//enregistrer coiffeur
           int wsv = ui->label_28->width();
           int hsv = ui->label_28->height();
           ui->label_28->setPixmap(pixenrg1.scaled(wsv,hsv,Qt::KeepAspectRatio));


         QPixmap pixqt1("C:/Users/HP/Desktop/projet/Module final/resources/quit.png");//quitter coiffeur
            int wq = ui->label_29->width();
            int hq = ui->label_29->height();
            ui->label_29->setPixmap(pixqt1.scaled(wq,hq,Qt::KeepAspectRatio));

          QPixmap pixadr1("C:/Users/HP/Desktop/projet/Module final/resources/local.png");//adresse coiffeur
               int wadr = ui->label_37->width();
               int hadr = ui->label_37->height();
               ui->label_37->setPixmap(pixadr1.scaled(wadr,hadr,Qt::KeepAspectRatio));

          QPixmap pixnum1("C:/Users/HP/Desktop/projet/Module final/resources/phone.png");//numero coiffeur
                int wn = ui->label_38->width();
                int hn = ui->label_38->height();
                ui->label_38->setPixmap(pixnum1.scaled(wn,hn,Qt::KeepAspectRatio));

          QPixmap pixnom1("C:/Users/HP/Desktop/projet/Module final/resources/liste1.png");//nom coiffeur
                 int wnm = ui->label_36->width();
                 int hnm = ui->label_36->height();
                 ui->label_36->setPixmap(pixnom1.scaled(wnm,hnm,Qt::KeepAspectRatio));

          QPixmap pixpc1("C:/Users/HP/Desktop/projet/Module final/resources/prix.png");//prix coiffeur
                 int wp = ui->label_39->width();
                 int hp = ui->label_39->height();
                 ui->label_39->setPixmap(pixpc1.scaled(wp,hp,Qt::KeepAspectRatio));


          //******interface locateur*********
         QPixmap pixloc("C:/Users/HP/Desktop/projet/Module final/resources/habit.png");//locateur
          int wl = ui->label_23->width();
          int hl = ui->label_23->height();
          ui->label_23->setPixmap(pixloc.scaled(wl,hl,Qt::KeepAspectRatio));


          QPixmap pixmail2("C:/Users/HP/Desktop/projet/Module final/resources/mail.png");//mail locateur
           int wl1 = ui->label_19->width();
           int hl1 = ui->label_19->height();
           ui->label_19->setPixmap(pixmail2.scaled(wl1,hl1,Qt::KeepAspectRatio));

           QPixmap pixstat2("C:/Users/HP/Desktop/projet/Module final/resources/stat.png");//stat loc
            int wl2 = ui->label_20->width();
            int hl2 = ui->label_20->height();
            ui->label_20->setPixmap(pixstat2.scaled(wl2,hl2,Qt::KeepAspectRatio));

           QPixmap pixmodif2("C:/Users/HP/Desktop/projet/Module final/resources/modif.png");//modifier loc
            int wl3 = ui->label_27->width();
            int hl3 = ui->label_27->height();
            ui->label_27->setPixmap(pixmodif2.scaled(wl3,hl3,Qt::KeepAspectRatio));

            QPixmap pixsupp2("C:/Users/HP/Desktop/projet/Module final/resources/del.png");//supprimer loc
             int wl4 = ui->label_26->width();
             int hl4 = ui->label_26->height();
             ui->label_26->setPixmap(pixsupp2.scaled(wl4,hl4,Qt::KeepAspectRatio));

             QPixmap pixadd2("C:/Users/HP/Desktop/projet/Module final/resources/add.png");//ajouter loc
              int wl5 = ui->label_21->width();
              int hl5 = ui->label_21->height();
              ui->label_21->setPixmap(pixadd2.scaled(wl5,hl5,Qt::KeepAspectRatio));

             QPixmap pixrech2("C:/Users/HP/Desktop/projet/Module final/resources/search.png");//rechercher loc
               int wl6 = ui->label_25->width();
               int hl6 = ui->label_25->height();
               ui->label_25->setPixmap(pixrech2.scaled(wl6,hl6,Qt::KeepAspectRatio));


              QPixmap pixenrg2("C:/Users/HP/Desktop/projet/Module final/resources/enreg.png");//enregistrer loc
                  int wl7 = ui->label_30->width();
                  int hl7 = ui->label_30->height();
                  ui->label_30->setPixmap(pixenrg2.scaled(wl7,hl7,Qt::KeepAspectRatio));


               QPixmap pixqt2("C:/Users/HP/Desktop/projet/Module final/resources/quit.png");//quitter loc
                   int wl8 = ui->label_31->width();
                   int hl8 = ui->label_31->height();
                   ui->label_31->setPixmap(pixqt2.scaled(wl8,hl8,Qt::KeepAspectRatio));

             QPixmap pixadr2("C:/Users/HP/Desktop/projet/Module final/resources/local.png");//adresse coiffeur
                         int wl9 = ui->label_32->width();
                         int hl9 = ui->label_32->height();
                         ui->label_32->setPixmap(pixadr2.scaled(wl9,hl9,Qt::KeepAspectRatio));

                QPixmap pixnum2("C:/Users/HP/Desktop/projet/Module final/resources/phone.png");//numero coiffeur
                          int wl10 = ui->label_33->width();
                          int hl10 = ui->label_33->height();
                          ui->label_33->setPixmap(pixnum2.scaled(wl10,hl10,Qt::KeepAspectRatio));

                QPixmap pixnom2("C:/Users/HP/Desktop/projet/Module final/resources/liste1.png");//nom coiffeur
                           int wl11 = ui->label_34->width();
                           int hl11 = ui->label_34->height();
                           ui->label_34->setPixmap(pixnom2.scaled(wl11,hl11,Qt::KeepAspectRatio));

                QPixmap pixpc2("C:/Users/HP/Desktop/projet/Module final/resources/prix.png");//prix coiffeur
                           int wl12 = ui->label_35->width();
                           int hl12 = ui->label_35->height();
                           ui->label_35->setPixmap(pixpc2.scaled(wl12,hl12,Qt::KeepAspectRatio));
                           ui->tableView_coiff->setModel(coiff.afficher());

connect(this->ui->pushButton_send, SIGNAL(clicked(bool)), this, SLOT(send_mail()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onstatus(Status::e status, QString errorMessage)//mailing
{
    switch (status) {
       case Status::Success:
          { qDebug()<< "message envoyer avec succes";
           break;}
       case Status::Failed:
       { qDebug()<< "erreur lors de l'envoi du message";
            qCritical()<< errorMessage;}

       break;
       default:
           break;
       }
       this->client->deleteLater();
}



void MainWindow::on_pushButton_2_clicked()
{
    close();
}

void MainWindow::on_pushButton_12_clicked()
{
    close();
}

void MainWindow::on_pushButton_14_clicked()
{
    close();
}

void MainWindow::on_pushButton_clicked()//du login au coiff ou locat
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}




//*****************coiffeurs***************


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


void MainWindow::on_pushButton_ajoutcoiff_clicked()//ajout coiffeurs
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




void MainWindow::on_fm_coiff_clicked()//modifier coiffeurs
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



void MainWindow::on_fs_coiff_clicked()//supprimer coiffeur
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



void MainWindow::on_upanim_ascoif_clicked()//tri ascendante coiff
{
    if(ui->comboBox_coif->currentIndex()==0)
       ui->tableView_coiff->setModel(coiff.afficherup_nom());
       else if(ui->comboBox_coif->currentIndex()==1)
       ui->tableView_coiff->setModel(coiff.afficherup_prix());

}



void MainWindow::on_downanim_dscoiff_clicked()//tri descendante coiff
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


//stat prix coiff

 /*  QSqlQuery query;

       //chiffres d'affaires des coiff
               QString chif="";
               query.prepare("SELECT COUNT(PRIX) FROM COIFFEURS");
               query.exec();
               while(query.next()){
               chif= query.value(0).toString();}*/




//*******************************locateurs******************

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

void MainWindow::on_fs_locat_clicked()//supprimer locat
{
    QString i = ui->lineEdit_nomlocat->text();
        bool test = locat.supprimer(i);

        if (i=="")
            test=false;
        if(test){
            ui->tableView_locat->setModel(locat.afficher());
            QMessageBox::information(nullptr,"supression locateurs","locateurs supprimée avec succes.");

        }
        else QMessageBox::warning(nullptr,"supression locateurs","locateurs non supprimée.");}


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

void MainWindow::on_pushButton_rechlocat_clicked()
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



//****************Mailing********************

void MainWindow::on_pushButton_send_clicked()//envoyer un mail
{
    QString subject,content;
       //AdresseEmail from,to,compte;
       content = ui->textEdit_msg->toPlainText();
       subject= ui->lineEdit_obj->text();
       AdresseEmail from("coifflocat20@gmail.com");
       AdresseEmail to(ui->linEdit_from->text());
       AdresseEmail compte ("coifflocat20@gmail.com", "esprit123");
       Email email(compte,from,to,subject,content);
       this->client = new Smtpclient("smtp.gmail.com");
       connect(this->client, SIGNAL(status(Status::e,QString)),
               this, SLOT(onstatus(Status::e, QString)), Qt::UniqueConnection);
       this->client->envoiEmail(email);
}
void MainWindow::on_pushButton_17_clicked()//annuler l'envoie
{
     ui->stackedWidget->setCurrentIndex(1);
}

//******************statistique****************

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
