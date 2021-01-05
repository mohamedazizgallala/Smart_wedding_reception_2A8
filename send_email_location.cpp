#include "send_email_location.h"
#include "ui_send_email_location.h"
#include "smtp_location.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);


}
Dialog::Dialog(QString e,QString n,QString s,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    QString contenu="Contenu";
    ui->setupUi(this);

    ui->recipient->setText(e);


    // ui->message->setText("Cher Monsieur/Madame "+n+",\n\n"+contenu+"\n\n"+"Cordialement,\n");






}
Dialog::~Dialog()
{
    delete ui;

}

void Dialog::on_pushButton_2_clicked()
{
    Smtp* smtp = new Smtp("smart.wedding.reception.@gmail.com", "vanguards", "smtp.gmail.com", 465);

    smtp->sendMail("smart.wedding.reception.@gmail.com", ui->recipient->text() , ui->subject->text() ,ui->message->toPlainText());

    /*if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );*/

}
