#include "course.h"
#include "ui_course.h"
#include <QtSql>

course::course(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::course)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("SELECT login FROM liza_and_egor.users WHERE role = 'teacher'");
    query.exec();
    while(query.next())
        ui->comboBox->addItem(query.value(0).toString());
}

course::~course()
{
    delete ui;
}

void course::on_pushButton_clicked()
{
    QSqlQuery query;
    QString tmp, deal = "INSERT INTO liza_and_egor.courses VALUES('";
    tmp = ui->name->text();
    qDebug() << tmp;
    if (tmp == ""){
        ui->label_8->setText("вы не ввели название курса.....");
        return;
    }
    else
        deal += tmp + "', '";
    tmp = ui->shed->text();
    qDebug() << tmp;
    if (tmp == ""){
        ui->label_8->setText("вы не ввели расписание курса.....");
        return;
    }
    else
        deal += tmp + "', 0, '";
    tmp = ui->comboBox->currentText();
    qDebug() << tmp;
    if (tmp == ""){
        ui->label_8->setText("вы не выбрали учителя.....");
        return;
    }
    else
        deal += tmp + "', ";
    tmp = ui->cost->text();
    qDebug() << tmp;
    if (tmp == ""){
        ui->label_8->setText("вы не ввели стоимость курса.....");
        return;
    }
    else
        deal += tmp + ", '" + ui->textEdit->toPlainText() + "', '";
    tmp = ui->dateEdit->text();
    qDebug() << tmp;
        deal += tmp + "');";
    query.prepare(deal);
    query.exec();
    accept();
}

