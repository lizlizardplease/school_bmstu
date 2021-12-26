#include "guest.h"
#include "ui_guest.h"

guest::guest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guest)
{
    ui->setupUi(this);
    ui->role->addItem("student");
    ui->role->addItem("teacher");
    ui->role->addItem("admin");
}

guest::~guest()
{
    delete ui;
}

void guest::on_pushButton_2_clicked()
{
    if (ui->log_2->text() == "" || ui->pas_2->text() == ""){
        ui->error_2->setText("Логин и пароль обязательны к заполнению!");
        return;
    }
    QSqlQuery query;
    QString tmp, deal = "INSERT INTO liza_and_egor.users VALUES('" + ui->surn_2->text() + "', '";

    deal += ui->name_2->text() + "', '" + ui->papa_2->text() + "', '" + ui->mail_2->text()+ "', '";
    if (ui->role->currentText() == ""){
        ui->error_2->setText("выберите роль!");
        return;
    }
    else
        deal += ui->role->currentText() + "', '" + ui->log_2->text()+ "', '" + ui->pas_2->text() + "', 0, '" + ui->ph_2->text() + "');";
    query.prepare(deal);
    query.exec();
    accept();
}

