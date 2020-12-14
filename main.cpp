#include "mainwindow_location.h"
#include <QApplication>
#include "connexion.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion c;
    bool test=c.create_cnx();
    MainWindow w;
    if (test)
   { w.show();
       // QMessageBox::information(nullptr, QObject::tr("Database is open"),
                          // QObject::tr("La connexion est établie."), QMessageBox::Ok);
        }
   // else {
        //QMessageBox::critical(nullptr, QObject::tr("Database is open"),
                         //  QObject::tr("La connexion est établie."), QMessageBox::Cancel); }




    return a.exec();
}
