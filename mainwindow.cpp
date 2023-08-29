#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialog.h"
#include <QLineEdit>


Dialog *dlg;


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

    Dialog dialog;
    QString email= "paulo";
    QString senha= "123";
    if(ui->lineEdit->text()== email && ui->lineEdit_2->text() == senha){
        close();
        dialog.exec();
    }else {
        if(ui->lineEdit->text() != email){
            ui->label_7->setText("E-MAIL INVÁLIDO!");
        }
        else if(ui->lineEdit_2->text() != senha){
            ui->label_7->setText("SENHA INVÁLIDA!");
        }

    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
}
