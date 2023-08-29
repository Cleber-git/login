#ifndef SLOT_FECHAR_H
#define SLOT_FECHAR_H

#include <QDialog>
#include <QtSql/QSqlQuery>
#include "mainwindow.h"



namespace Ui {
class slot_Fechar;
}

class slot_Fechar : public QDialog
{
    Q_OBJECT

public:
    explicit slot_Fechar(QWidget *parent = nullptr);
    ~slot_Fechar();

private:
    Ui::slot_Fechar *ui;
};

#endif // SLOT_FECHAR_H
