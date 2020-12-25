#ifndef CLL_H
#define CLL_H
#include "client.h"
#include <QDialog>

namespace Ui {
class cll;
}

class cll : public QDialog
{
    Q_OBJECT

public:
    explicit cll(QWidget *parent = nullptr);
    ~cll();

private slots:
    void on_pb_ok_2_clicked();

    void on_pb_actualiser_2_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifierp_2_clicked();

    void on_pb_ok_3_clicked();

private:
    Ui::cll *ui;
    client c;
};

#endif // CLL_H
