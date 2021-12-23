#include "student.h"
#include "ui_student.h"

student::student(QWidget *parent, QString l) :
    QMainWindow(parent),
    ui(new Ui::student)
{
    login = l;
    ui->setupUi(this);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    update();
    dialog = new adds(this, login);
    dialog_ch = new change(this, login);
    qDebug() << login;
}

student::~student()
{
    delete ui;
}

void student::on_pushButton_clicked()
{
    dialog->exec();
}

void student::update(){
    QSqlQuery query;
    qDebug() << login;
    query.prepare("SELECT * FROM liza_and_egor.users WHERE login='"+login+"'");
    query.exec();
    query.next();
    ui->surn->setText(query.value(0).toString());
    ui->name->setText(query.value(1).toString());
    ui->papa->setText(query.value(2).toString());
    ui->mail->setText(query.value(3).toString());
    ui->ph->setText(query.value(8).toString());
}
void student::on_pushButton_3_clicked()
{
    if (dialog_ch->exec() == QDialog::Accepted){
        update();
    }
}

