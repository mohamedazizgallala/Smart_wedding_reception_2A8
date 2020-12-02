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


    void on_buttonajouter_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_search_carButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_buttonajouter_2_clicked();

    void on_search_carButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_10_clicked();

    void on_login_button_clicked();

    void on_buttonquitter_6_clicked();

    void on_buttonquitter_clicked();

    void on_buttonsedeconn_clicked();

    void on_buttonquitter_2_clicked();

    void on_buttonsedeconn_2_clicked();

    void on_back_4_clicked();

    void on_buttonquitter_3_clicked();

    void on_buttonsedeconn_3_clicked();

    void on_back_3_clicked();

    void on_buttonquitter_4_clicked();

    void on_buttonsedeconn_4_clicked();

    void on_back_2_clicked();

    void on_buttonquitter_5_clicked();

    void on_buttonsedeconn_5_clicked();

    void on_button_traiteur_clicked();

    void on_button_decorateur_clicked();

    void on_buttonanimateur_clicked();

    void on_buttonprofil_clicked();

    void on_back_clicked();



private:
    Ui::MainWindow *ui;
    animateur tempanimateur;
    traiteur temptraiteur;

};
#endif // MAINWINDOW_H
