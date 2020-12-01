#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMessageBox>
#include <QMainWindow>
#include <QSqlTableModel>
#include "photographe.h"
#include "connection.h"
#include "smtp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Connection cn;


private slots:
     void on_pushButton_clicked();
    void on_Login_clicked();
    void on_ajouter_button_clicked();
    void on_SUPPRIMER8BUTTON_clicked();
    void on_modifier_button_clicked();
    void login();
    void on_pushButton_3_clicked();
    void on_tri_button_clicked();
    void on_quit_button_clicked();
    void on_pushButton_recherche_clicked();



    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_recherche_clicked();

private:
    Ui::MainWindow *ui;
    Photographe tempphoto;
    QString email_recipient;
};

#endif // MAINWINDOW_H
