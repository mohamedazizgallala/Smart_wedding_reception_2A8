#include "mainwindow.h"
#include <QApplication>
#include "connexion.h"
#include <QMessageBox>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connexion c;
    bool test=c.create_cnx();

    //debut config langue
    QTranslator T;
    QStringList langue;
    langue<<"English"<<"Francais";
    const QString languel=QInputDialog::getItem(NULL,"Langue","Selectionner langue",langue);
    if(languel=="English")
        T.load(":/english.qm");
    if(languel!="Francais")
                 a.installTranslator(&T);
                            //fin config langue
    a.setStyle("fusion");
    MainWindow w;
    if (test)
   { w.show();
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                           QObject::tr("La connexion est établie."), QMessageBox::Ok);
        }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Database is open"),
                           QObject::tr("La connexion est établie."), QMessageBox::Cancel); }




    return a.exec();
}
