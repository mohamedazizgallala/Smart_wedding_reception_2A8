#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "car.h"
#include <QMessageBox>
#include <QMainWindow>
#include <QSqlTableModel>

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

private:
    Ui::MainWindow *ui;
    car cartemp; //to use for crud other than ajouter
};
#endif // MAINWINDOW_H
