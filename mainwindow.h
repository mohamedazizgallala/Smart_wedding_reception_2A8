#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QStatusBar>
#include <QMainWindow>
#include <QSqlTableModel>
#include "photographe.h"
#include "graphiste.h"
#include "connection.h"
#include "smtp.h"
#include <QPrinter>
#include <QPrintDialog>
#include <qtextbrowser.h>
#include <QFileDialog>
#include <QFileInfo>


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

    void on_quit_button_clicked();

    void on_ajouter_photographe_clicked();

    void on_recherche_photographe_clicked();

    void on_exporterpdf_graphiste_clicked();

    void on_exporterpdf_photographe_clicked();

    void on_tri_photographe_clicked();

    void on_modifier_photographe_clicked();

    void on_envoyermail_graphiste_clicked();

    void on_supprimer_graphiste_clicked();

    void on_rechercher_graphiste_clicked();

    void on_ajouter_graphiste_clicked();

    void on_modifier_graphiste_clicked();

    void on_envoyermail_photographe_clicked();

    void on_selectionnermail_photographe_clicked();

    void on_tri_graphiste_clicked();

    void on_selectionnermail_graphiste_clicked();

    void on_supprimer_photographe_clicked();

    void on_retour_clicked();

    void on_retour2_clicked();

    void on_Login_graphisme_clicked();

    void on__quit_button_2_clicked();

    void on_Button_espacegraphistes_clicked();

    void on_button_espace_photographes_clicked();

private:
    Ui::MainWindow *ui;
    Photographe tempphoto;
    QString email_recipient;
    Graphiste tempgraph;
};

#endif // MAINWINDOW_H
