#include "Modulebeaute.h"
#include "ui_mainwindow.h"
#include "coiffeurs.h"
#include "locateurs.h"
#include <qtableview.h>
#include "statbeaute.h"
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
    ui->stackedWidget_coiff->setCurrentIndex(0);






    //***********************************insert image*********************


    //*******login*****
    QPixmap pix("C:/Users/HP/Desktop/projet/Module final/resources/login.png");//login
    int w1 = ui->label->width();
    int h1 = ui->label->height();
    ui->label->setPixmap(pix.scaled(w1,h1,Qt::KeepAspectRatio));


    QPixmap pix1("C:/Users/HP/Desktop/projet/Module final/resources/retry.png");//retour a la login
    int wret = ui->label_rtncoiff->width();
    int hret = ui->label_rtncoiff->height();
    ui->label_rtncoiff->setPixmap(pix1.scaled(wret,hret,Qt::KeepAspectRatio));





    //******interface coiffeures*****
    QPixmap pixmail("C:/Users/HP/Desktop/projet/Module final/resources/mail.png");//mail  coif
     int w3 = ui->label_mlcoiff->width();
     int h4 = ui->label_mlcoiff->height();
     ui->label_mlcoiff->setPixmap(pixmail.scaled(w3,h4,Qt::KeepAspectRatio));

     QPixmap pixstat("C:/Users/HP/Desktop/projet/Module final/resources/stat.png");//stat coif
      int ws = ui->label_stcoiff->width();
      int hs = ui->label_stcoiff->height();
      ui->label_stcoiff->setPixmap(pixstat.scaled(ws,hs,Qt::KeepAspectRatio));

     QPixmap pixmodif("C:/Users/HP/Desktop/projet/Module final/resources/modif.png");//modifier coif
      int w5 = ui->label_modcoiff->width();
      int h6 = ui->label_modcoiff->height();
      ui->label_modcoiff->setPixmap(pixmodif.scaled(w5,h6,Qt::KeepAspectRatio));

      QPixmap pixsupp("C:/Users/HP/Desktop/projet/Module final/resources/del.png");//supprimer coiff
       int wsup = ui->label_supcoiff->width();
       int hsup = ui->label_supcoiff->height();
       ui->label_supcoiff->setPixmap(pixsupp.scaled(wsup,hsup,Qt::KeepAspectRatio));

       QPixmap pixadd("C:/Users/HP/Desktop/projet/Module final/resources/add.png");//ajouter coiff
        int wad = ui->label_ajcoiff->width();
        int had = ui->label_ajcoiff->height();
        ui->label_ajcoiff->setPixmap(pixadd.scaled(wad,had,Qt::KeepAspectRatio));

        QPixmap pixcoif("C:/Users/HP/Desktop/projet/Module final/resources/coiff.png");//icon coiffeur
         int wc = ui->label_iconcoiff->width();
         int hc = ui->label_iconcoiff->height();
         ui->label_iconcoiff->setPixmap(pixcoif.scaled(wc,hc,Qt::KeepAspectRatio));

        QPixmap pixrech("C:/Users/HP/Desktop/projet/Module final/resources/search.png");//rechercher un coiff
          int wr = ui->label_rchcoiff->width();
          int hr = ui->label_rchcoiff->height();
          ui->label_rchcoiff->setPixmap(pixrech.scaled(wr,hr,Qt::KeepAspectRatio));


         QPixmap pixqt1("C:/Users/HP/Desktop/projet/Module final/resources/quit.png");//quitter coiffeur
            int wq = ui->label_qcoiff->width();
            int hq = ui->label_qcoiff->height();
            ui->label_qcoiff->setPixmap(pixqt1.scaled(wq,hq,Qt::KeepAspectRatio));



          //******interface locateur*********
         QPixmap pixloc("C:/Users/HP/Desktop/projet/Module final/resources/habit.png");//icon  locateur
          int wl = ui->label_iconloc->width();
          int hl = ui->label_iconloc->height();
          ui->label_iconloc->setPixmap(pixloc.scaled(wl,hl,Qt::KeepAspectRatio));


          QPixmap pixmail2("C:/Users/HP/Desktop/projet/Module final/resources/mail.png");//mail locateur
           int wl1 = ui->label_mlloc->width();
           int hl1 = ui->label_mlloc->height();
           ui->label_mlloc->setPixmap(pixmail2.scaled(wl1,hl1,Qt::KeepAspectRatio));


           QPixmap pixmodif2("C:/Users/HP/Desktop/projet/Module final/resources/modif.png");//modifier loc
            int wl3 = ui->label_modloc->width();
            int hl3 = ui->label_modloc->height();
            ui->label_modloc->setPixmap(pixmodif2.scaled(wl3,hl3,Qt::KeepAspectRatio));

            QPixmap pixsupp2("C:/Users/HP/Desktop/projet/Module final/resources/del.png");//supprimer loc
             int wl4 = ui->label_suploc->width();
             int hl4 = ui->label_suploc->height();
             ui->label_suploc->setPixmap(pixsupp2.scaled(wl4,hl4,Qt::KeepAspectRatio));

             QPixmap pixadd2("C:/Users/HP/Desktop/projet/Module final/resources/add.png");//ajouter loc
              int wl5 = ui->label_ajloc->width();
              int hl5 = ui->label_ajloc->height();
              ui->label_ajloc->setPixmap(pixadd2.scaled(wl5,hl5,Qt::KeepAspectRatio));

             QPixmap pixrech2("C:/Users/HP/Desktop/projet/Module final/resources/search.png");//rechercher loc
               int wl6 = ui->label_rechloc->width();
               int hl6 = ui->label_rechloc->height();
               ui->label_rechloc->setPixmap(pixrech2.scaled(wl6,hl6,Qt::KeepAspectRatio));




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

void MainWindow::on_pushButton_quitcoiff_clicked()
{
    close();
}

void MainWindow::on_pushButton_14_clicked()
{
    close();
}

void MainWindow::on_pushButton_clicked()//du login au coiff ou locat
{
   /*


    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/ressource/Click.wav"));
    music->play();

    QString username = ui->login_name->text();
    QString password = ui->login_pass->text();
   // QString role = ui->login_role->currentText();
    QString etat="connecté(e)";
           if((username !=  "")&&(password!="")&&(role !="")) {
login h(username,password,role);
bool test=h.connect();

if(test)
{

    if( role=="GM" )
    {
     ui->pages->setCurrentIndex(1);
    }
ui->tableViewInvites->setModel(tmpinvite.afficher());
ui->tableViewCerems->setModel(tmpcerem.afficher());
}
else{
QMessageBox::warning(this,"Connection", "Vérifier svp ");
}

}
     */

    ui->stackedWidget_coiff->setCurrentIndex(1);


}

void MainWindow::on_pushButton_rtcoiff_clicked()
{
    ui->stackedWidget_coiff->setCurrentIndex(0);
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
void MainWindow::on_pushButton_anmailbt_clicked()//annuler l'envoie
{
     ui->stackedWidget_coiff->setCurrentIndex(1);
}

void MainWindow::on_pushButton_maillocat_clicked()
{
       ui->stackedWidget_coiff->setCurrentIndex(2);
}



void MainWindow::on_pushButton_mailcoiff_clicked()
{
       ui->stackedWidget_coiff->setCurrentIndex(2);
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



