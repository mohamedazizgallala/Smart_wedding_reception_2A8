#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTimer>
#include <QTime>

#include <QMainWindow>
#include "evenement.h"

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


private:
    Ui::MainWindow *ui;
    evenement tmpev;
    QTimer *timer;

public slots:
    void timetest();
};


#endif // MAINWINDOW_H
