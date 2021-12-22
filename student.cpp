#include "student.h"
#include "ui_student.h"

student::student(QWidget *parent, QString login) :
    QMainWindow(parent),
    ui(new Ui::student)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("SELECT * FROM liza_and_egor.users WHERE login='"+login+"'");
    query.exec();
    query.next();
    ui->surn->setText(query.value(0).toString());
    ui->name->setText(query.value(1).toString());
    ui->papa->setText(query.value(2).toString());
    ui->mail->setText(query.value(3).toString());
    ui->ph->setText(query.value(4).toString());
    dialog = new adds;
}

student::~student()
{
    delete ui;
}

void student::on_pushButton_clicked()
{
    dialog->exec();
}

