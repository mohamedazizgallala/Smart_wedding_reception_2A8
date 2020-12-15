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

    //***************************************
    //******************************************
    //****************************************
    //module marketing


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

};
#endif // MAINWINDOW_H
