#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   //to add pictures to the loagin app
    QPixmap pix(":/resources/img/hack.jpg");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked() //created on assigning slot to the object
{   //to recieve texts from the user in corresponding lineEdits
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username== "test" && password=="test")
            {
        QMessageBox::information(this,"Login","how dare you crack my login id");   //this will show the information message
        //this will open second window
        sec = new secdialog(this);
        sec->show();
    }
    else
        QMessageBox::warning(this,"Login","you really think it's gonna be that easy");

}
