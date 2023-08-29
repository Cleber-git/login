#include "slot_fechar.h"
#include "ui_slot_fechar.h"
#include <QMessageBox>
#include <QProcess>
#include <QList>
#include <QLCDNumber>
#include <QDebug>


slot_Fechar::slot_Fechar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::slot_Fechar)
{
    ui->setupUi(this);

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString path = "/home/cleber/login/db/fechamento_de_caixa.db";
    qDebug() << "Testing debug: "<<path;
    db.setDatabaseName(path);

    if( !db.open() )
    {
        QMessageBox::critical(this, "ERRO", "Houve um erro na conexão com o banco de dados");
        QApplication::exit(0);
        QProcess::startDetached(QCoreApplication::applicationFilePath());
    }




    QLCDNumber *lcd1 = ui->lcd_dinheiro;
    QLCDNumber *lcd2 = ui->lcd_credito;
    QLCDNumber *lcd3 = ui->lcd_debito;
    QLCDNumber *lcd4 = ui->lcd_pix;

    QList<QString> colunas;
    QList<QLCDNumber *> lcds;

    lcds << lcd1 << lcd2 << lcd3 << lcd4;

    colunas << "dinheiro" << "crédito" <<"débito" <<"pix";

    QSqlQuery query;
    QString sql;
    double sum = 0;





    for (int i = 0;  i < 4 ; i++ ) {

        sql = "SELECT SUM("+colunas[i]+") FROM valores";
        query.prepare(sql);

        if(!query.exec()){
            QMessageBox::critical(this, "ERRO", "Houve um erro na abertura da tela");
            destroy();

        }else if(query.next()){
            lcds[i]->display(query.value(0).toFloat());
        }
        sum += lcds[i]->value();



    }

    ui->lcdNumber->display(sum);







    }

slot_Fechar::~slot_Fechar()
{
    delete ui;
}
