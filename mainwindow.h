#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "decorateur.h"
#include "traiteur.h"
#include "animateur.h"
#include <QMainWindow>

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

    void on_buttonquitter_6_org_clicked();

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



private:
    Ui::MainWindow *ui;
    animateur tempanimateur;
    traiteur temptraiteur;

};
#endif // MAINWINDOW_H
