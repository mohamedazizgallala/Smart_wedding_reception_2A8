#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "car.h"
#include "local.h"
#include <QMessageBox>
#include <QMainWindow>
#include <QSqlTableModel>
#include <QFileDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QMediaPlayer>
#include "decorateur.h"
#include "traiteur.h"
#include "animateur.h"
#include "exportexcelobject.h"
#include "evenement.h"
#include "graphiste.h"
#include "photographe.h"
#include "arduino.h"
//beaute
#include "coiffeurs.h"
#include "locateurs.h"
//moslem
#include "client.h"
#include "emp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    //**********************************
    //**************************************
    //******************************************
    //module location

    void on_login_button_clicked();

    void on_add_car_clicked();

    void on_add_carButton_clicked();

    void on_search_car_clicked();

    void on_return_search_carButton_clicked();

    void on_return_add_carButton_clicked();

    void on_showlist_car_clicked();

    void on_return_car_listButton_clicked();

    void on_send_email_car_clicked();

    void on_return_send_emailButton_clicked();

    void on_add_local_clicked();

    void on_return_add_localButton_clicked();

    void on_add_localButton_clicked();

    void on_search_local_clicked();

    void on_return_search_localButton_clicked();

    void on_showlist_local_clicked();

    void on_return_local_listButton_clicked();

    void on_email_local_clicked();

    void on_deconnexion_clicked();

    void on_quit_clicked();

    void on_supprimer_car_listButton_clicked();

    void on_modifier_car_listButton_clicked();

    void on_imprimer_car_listButton_clicked();

    void on_search_carButton_clicked();

    void on_imprimer_car_listButton_2_clicked();

    void on_supprimer_local_listButton_clicked();

    void on_modifier_local_listButton_clicked();

    void on_search_localButton_clicked();

    void on_imprimer_local_listButton_clicked();

    //***************************************
    //******************************************
    //****************************************
    //module organisation

    void on_buttonajouter_org_clicked();

    void on_pushButton_3_org_clicked();

    void on_pushButton_4_org_clicked();

    void on_search_carButton_8_org_clicked();

    void on_pushButton_6_org_clicked();

    void on_pushButton_7_org_clicked();

    void on_buttonajouter_2_org_clicked();

    void on_search_carButton_9_org_clicked();

    void on_pushButton_11_org_clicked();

    void on_pushButton_8_org_clicked();

    void on_pushButton_9_org_clicked();

    void on_pushButton_12_org_clicked();

    void on_pushButton_5_org_clicked();

    void on_pushButton_10_org_clicked();

    void on_login_button_org_clicked();

   // void on_buttonquitter_6_org_clicked();

    void on_buttonquitter_org_clicked();

    void on_buttonsedeconn_org_clicked();

    void on_buttonquitter_2_org_clicked();

    void on_buttonsedeconn_2_org_clicked();

    void on_back_4_org_clicked();

    void on_buttonquitter_3_org_clicked();

    void on_buttonsedeconn_3_org_clicked();

    void on_back_3_org_clicked();

    void on_buttonquitter_4_org_clicked();

    void on_buttonsedeconn_4_org_clicked();

    void on_back_2_org_clicked();

    void on_buttonquitter_5_org_clicked();

    void on_buttonsedeconn_5_org_clicked();

    void on_button_traiteur_org_clicked();

    void on_button_decorateur_org_clicked();

    void on_buttonanimateur_org_clicked();

    void on_buttonprofil_org_clicked();

    void on_back_org_clicked();

    void on_buttonajouter_3_org_clicked();

    void readdata();

    //***************************************
    //******************************************
    //****************************************
    //module marketing

    void on_buton_ajouter_mar_clicked();

        void on_pushButton_4_mar_clicked();

        void on_boutonsupprimer_mar_clicked();

        void on_bouton_modifier_mar_clicked();

        void on_retour4_mar_clicked();

        void on_pushButton_2_mar_clicked();

        void on_RETOUR1_mar_clicked();

        void on_pushButton_3_mar_clicked();

        void on_lineEdit_mar_textChanged(const QString &arg1);

        void on_pushButton_5_mar_clicked();


    void notif(QString t,QString m);
        void on_SUPPRIMER_mar_clicked();

        void on_MODIF_mar_clicked();

        void on_pushButton_6_mar_clicked();

        void on_pushButton_8_mar_clicked();

        void on_eventsupprimer_2_mar_clicked();

        void on_retour4_2_mar_clicked();

        void on_pushButton_11_mar_clicked();

        void on_pushButton_12_mar_clicked();

        void on_RETOUR1_3_mar_clicked();

        void on_retour4_5_mar_clicked();

        void on_event_ajouter_2_mar_clicked();

        void on_event_afficher_mar_clicked();

        void on_event_modifier_2_mar_clicked();

        void on_pushButton_9_mar_clicked();

        void on_lineEdit_2_mar_textChanged(const QString &arg1);

        void on_SUPPRIMER_3_mar_clicked();

        void on_pushButton_24_mar_clicked();

        void on_pushButton_7_mar_clicked();


        void on_pushButton_13_mar_clicked();


        void on_pushButton_65_mar_clicked();

        void on_pushButton_14_mar_clicked();

        void on_retour4_3_mar_clicked();

       // void on_lineEdit_adresse_cursorPositionChanged(int arg1, int arg2);

        void on_pushButton_mar_clicked();

        void on_pushButton_10_mar_clicked();

        void on_pushButton_15_mar_clicked();

        void on_lineEdit_mar_cursorPositionChanged(int arg1, int arg2);

        void on_SUPPRIMER_2_mar_clicked();

        void on_SUPPRIMER_4_mar_clicked();

        void on_tableView_2_mar_activated(const QModelIndex &index);

        void on_pdf_mar_clicked();

        void on_tri_mar_clicked();

        void on_recherche_mar_clicked();

        void on_msg_mar_cursorPositionChanged(int arg1, int arg2);

        void on_testtest_mar_clicked();

        void on_trii_mar_clicked();

        void on_recherchee_mar_clicked();

        //********************************************
       //***********************************
       //*****************************/

       //module graphisme


        void on_button_espace_photographes_clicked();

        void on_Button_espacegraphistes_clicked();

        void on_ajouter_photographe_clicked();

        void on_ajouter_graphiste_clicked();

        void on_supprimer_graphiste_clicked();

        void on_supprimer_photographe_clicked();

        void on_modifier_photographe_clicked();

        void on_modifier_graphiste_clicked();

        void on_retour_clicked();

        void on_tri_photographe_clicked();

        void on_tri_graphiste_clicked();

        void on__quit_button_2_clicked();

        void on_quit_button_clicked();

        void on_exporterpdf_photographe_clicked();

        void on_selectionnermail_photographe_clicked();

        //void on_envoyermail_photographe_clicked();

        void on_selectionnermail_graphiste_clicked();

        //void on_envoyermail_graphiste_clicked();

        void on_exporterpdf_graphiste_clicked();

        void on_rechercher_graphiste_clicked();

        void on_recherche_photographe_clicked();

        void on_retour2_clicked();
        void detect();
        void showTime();

   //module beauté


        //passer de page a une autre page et close
         void on_button_beaute_clicked();

         void on_pushButton_ajoutcoiff_clicked();

         void on_pushButton_maillocat_clicked();

         void on_pushButton_mailcoiff_clicked();

         void on_tableView_coiff_activated(const QModelIndex &index);

         void on_fm_coiff_clicked();

         void on_fs_coiff_clicked();

         void on_pushButton_rechcoiff_clicked();

         void on_upanim_ascoif_clicked();

         void on_downanim_dscoiff_clicked();

         void on_nomrecherche_coiff_textChanged(const QString &arg1);

         void on_pushButton_quitcoiff_2_clicked();

         void on_pushButton_rtcoiff_clicked();

         void on_tableView_locat_activated(const QModelIndex &index);

         void on_pushButton_ajoutlocat_clicked();

         void on_fm_locat_clicked();

         void on_fs_locat_clicked();

         void on_upanim_aslocat_clicked();

         void on_downanim_dslocat_clicked();

         void on_pushButton_rechlocat_clicked();

         void on_nomrecherche_locat_textChanged(const QString &arg1);

         void on_pushButton_statcoiff_clicked();

         void on_emchiemp_clicked();

         void on_pushButton_clicked();

         void on_pushButton_3_clicked();
//moslem
         //client cll
         void on_pb_ok_2_clicked();

         void on_pb_actualiser_2_clicked();

         void on_pb_supprimer_clicked();

         void on_pb_modifierp_2_clicked();

         void on_pb_ok_3_clicked();
         //employe emp
         void on_pb_ok_clicked();

         void on_pb_actualiser_5_clicked();

         void on_pb_supprimer_2_clicked();

         void on_pb_modifierp_5_clicked();

         void on_pb_modifierp_6_clicked();
         void on_pushButton_4_clicked();

         void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    //variable location
    car cartemp; //to use for crud other than ajouter
    local localtemp;
   QMediaPlayer player;

   //variable organisation
   animateur tempanimateur;
       traiteur temptraiteur;

    //variable marketing
       evenement tmpev;

    //variable graphisme
       Photographe tempphoto;
       QString email_recipient;
       Graphiste tempgraph;
       Arduino Ard;
       QByteArray data1;
       //variables beauté


            coiffeurs coiff;
            locateurs locat;
//moslem
            emp t;
             client c;


};
#endif // MAINWINDOW_H
