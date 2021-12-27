#include "pay.h"
#include "ui_pay.h"
#include <QtSql>

pay::pay(QWidget *parent, QString username) :
    QDialog(parent),
    ui(new Ui::pay), login(username)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("SELECT role FROM liza_and_egor.users WHERE login = '"+ login + "';");
    query.exec();
    query.next();
    if (query.value(0).toString() == "student"){
        type = 0;
        ui->label->setText("Введите сумму, которую хотите положить на счет");
    }
    else{
        type = 1;
        ui->label->setText("Введите сумму для вывода");
    }

}

pay::~pay()
{
    delete ui;
}

void pay::on_pushButton_clicked()
{
    QSqlQuery query;
    QString tmp = ui->textEdit->toPlainText();
    query.prepare("SELECT * FROM liza_and_egor.users WHERE login='"+login+"'");
    query.exec();
    query.next();
    if (type == 1){
        if(query.value(7).toString().remove(0,1).toFloat() < tmp.toFloat()){
            ui->error->setText("У вас нет столько денег...");
            return;
        }
        else{
        query.prepare("UPDATE liza_and_egor.users SET bank = bank - '" + tmp + "' WHERE login='"+login+"'");
        query.exec();
    }
    }
    else{
            query.prepare("UPDATE liza_and_egor.users SET bank = bank + '" + tmp + "' WHERE login='"+login+"'");
            query.exec();
        }
    accept();
    QMessageBox::information(this, tr("Баланс"), tr("Баланс успешно пополнен."));
}

