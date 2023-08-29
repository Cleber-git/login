#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QFont>
#include <QProcess>
#include "slot_fechar.h"



Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->btn_fecharCaixa->hide();
    ui->btn_fecharCaixa->setEnabled(false);





}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString path = "/home/cleber/login/db/fechamento_de_caixa.db";
    db.setDatabaseName(path);
    if( !db.open() ){
        QMessageBox::critical(this, "ERRO", "Houve um erro na conexão com o banco de dados");
        QApplication::exit(0);
        QProcess::startDetached(QCoreApplication::applicationFilePath());
    }
    if( ui->lineEdit->text() != "" )
    {


        QString pay_method = ui->comboBox->currentText();
        QString lower = pay_method.toLower();


        QString preço = ui->lineEdit->text();


        QSqlQuery query;
        QString sql;
        // crédito débito dinheiro pix

        sql = "INSERT INTO valores ("+lower+") VALUES (:preco)";

        query.prepare(sql);
        query.bindValue(":preco", preço);

        if(!query.exec()){
            QMessageBox::critical(this, "ERRO", "Erro ao inserir dados, tente novamente.");

            return;

        }
        QMessageBox::information(this, "Sucesso!", "Dados inseridos com sucesso! Inserido na coluna: "+pay_method+".");
        ui->lineEdit->clear();
        ui->label_5->clear();
        ui->lineEdit->setFocus();


   }


    }





void Dialog::on_pushButton_2_clicked()
{
   QApplication::exit();



}

void Dialog::on_btn_fecharCaixa_clicked()
{
    slot_Fechar slt_f;
    slt_f.exec();
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString path = "/home/cleber/login/db/fechamento_de_caixa.db";
    db.setDatabaseName(path);
    if( !db.open() ){
        QMessageBox::critical(this, "ERRO", "Houve um erro na conexão com o banco de dados");
        QApplication::exit(0);
        QProcess::startDetached(QCoreApplication::applicationFilePath());
    }
    QSqlQuery query;
    QString sql = "DELETE FROM valores";
    query.prepare(sql);
    if (!query.exec()) {
        QMessageBox::critical(this, "ERRO", "Houve um erro ao tentar deletar banco de dados");

    }
    ui->btn_fecharCaixa->hide();
    ui->btn_fecharCaixa->setEnabled(false);
    ui->pushButton_3->show();


}

void Dialog::on_pushButton_3_clicked()
{
    ui->pushButton_3->hide();
    ui->btn_fecharCaixa->show();
    ui->btn_fecharCaixa->setEnabled(true);
}
