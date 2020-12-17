#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "coiffeurs.h"
#include "locateurs.h"
#include "email.h"
#include "adresseemail.h"
#include "smtpclient.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onstatus(Status::e status, QString errorMessage);
//passer de page a une autre page et close
    void on_pushButton_2_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_clicked();


//mailing



//coiffeurs

    void on_tableView_coiff_activated(const QModelIndex &index);

    void on_pushButton_ajoutcoiff_clicked();

    void on_fm_coiff_clicked();

    void on_fs_coiff_clicked();

    void on_pushButton_rechlocat_clicked();

    void on_pushButton_rechcoiff_clicked();

    void on_upanim_ascoif_clicked();

    void on_downanim_dscoiff_clicked();

    void on_nomrecherche_coiff_textChanged(const QString &arg1);


 //locateurs

    void on_tableView_locat_activated(const QModelIndex &index);

    void on_pushButton_ajoutlocat_clicked();

    void on_fm_locat_clicked();

    void on_fs_locat_clicked();

    void on_upanim_aslocat_clicked();

    void on_downanim_dslocat_clicked();

    void on_nomrecherche_locat_textChanged(const QString &arg1);

    void on_pushButton_send_clicked();

    void on_pushButton_statcoiff_clicked();

    void on_pushButton_rtcoiff_clicked();

    void on_pushButton_quitcoiff_clicked();

    void on_pushButton_maillocat_clicked();

    void on_pushButton_mailcoiff_clicked();

    void on_pushButton_anmailbt_clicked();

private:
    Ui::MainWindow *ui;
    coiffeurs coiff;
    locateurs locat;
    Smtpclient *client;

};
#endif // MAINWINDOW_H
