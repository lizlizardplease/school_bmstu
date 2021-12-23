#include "change.h"
#include "ui_change.h"

change::change(QWidget *parent, QString l) :
    QDialog(parent),
    ui(new Ui::change)
{
    login = l;
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("SELECT * FROM liza_and_egor.users WHERE login='"+login+"'");
    query.exec();
    query.next();
    ui->s_edit->setText(query.value(0).toString());
    ui->n_edit->setText(query.value(1).toString());
    ui->p_edit->setText(query.value(2).toString());
    ui->m_edit->setText(query.value(3).toString());
    ui->lineEdit->setText(query.value(8).toString());
}

change::~change()
{
    delete ui;
}

void change::on_pushButton_clicked()
{
    QSqlQuery query;
    QString deal = "UPDATE liza_and_egor.users SET name = '" + ui->n_edit->text() + "', surname = '";
    deal += ui->s_edit->text() + "', second_name = '" + ui->p_edit->text() + "', email = '";
    deal += ui->m_edit->text() + "', phone = '" + ui->lineEdit->text() + "' WHERE login = '" + login + "';";
    query.prepare(deal);
    query.exec();
    accept();
}

