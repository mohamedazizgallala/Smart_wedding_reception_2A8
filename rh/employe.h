#ifndef EMPLOYE_H
#define EMPLOYE_H
#include "emp.h"

#include <QMainWindow>

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QDialog>

namespace Ui {
class Employe;
}

class Employe : public QDialog
{
    Q_OBJECT

public:
    explicit Employe(QWidget *parent = nullptr);
    ~Employe();

private slots:
    void on_pb_ok_clicked();

    void on_pb_actualiser_5_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifierp_5_clicked();

    void on_pb_modifierp_6_clicked();

private:
    Ui::Employe *ui;
    emp t;
};

#endif // EMPLOYE_H
