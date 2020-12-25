#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cll.h"
#include "employe.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    cll a;
    a.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    Employe z;
    z.exec();
}
