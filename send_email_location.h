#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    explicit Dialog(QString,QString,QString,QWidget *parent = nullptr);
    ~Dialog();
    void set_tmpemail(QString e){tmpemail=e;}

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    QString tmpemail;
};

#endif // DIALOG_H
