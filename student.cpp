#include "student.h"
#include "ui_student.h"

student::student(QWidget *parent, QString l) :
    QMainWindow(parent),
    ui(new Ui::student)
{
    login = l;
    ui->setupUi(this);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    update();
    m_model = new QSqlQueryModel;
    ui->tableView->setModel(m_model);
    m_model->setQuery(" SELECT title, description, (surname || ' ' || name) AS ФИО_Преподавателя FROM liza_and_egor.users JOIN liza_and_egor.courses ON login = tutor JOIN liza_and_egor.courses_users ON title = course WHERE username = '"+ login + "';");
    dialog = new adds(this, login);
    dialog->setWindowTitle("Каталог новых курсов");
    dialog_ch = new change(this, login);
    dialog_ch->setWindowTitle("Изменение данных");
    dialog_pay = new pay(this, login);
    dialog_pay->setWindowTitle("Баланс");

}

student::~student()
{
    delete ui;
}

void student::on_pushButton_clicked()
{
    if (dialog->exec() == QDialog::Accepted)
    {
        m_model->setQuery(" SELECT title, description, (surname || ' ' || name) AS ФИО_Преподавателя FROM liza_and_egor.users JOIN liza_and_egor.courses ON login = tutor JOIN liza_and_egor.courses_users ON title = course WHERE username = '"+ login + "';");
        update();
    }
}

void student::update(){
    QSqlQuery query;
    query.prepare("SELECT * FROM liza_and_egor.users WHERE login='"+login+"'");
    query.exec();
    query.next();
    ui->surn->setText(query.value(0).toString());
    ui->name->setText(query.value(1).toString());
    ui->papa->setText(query.value(2).toString());
    ui->mail->setText(query.value(3).toString());
    ui->ph->setText(query.value(8).toString());
    ui->cash->setText(query.value(7).toString());
}

void student::on_pushButton_3_clicked()
{
    if (dialog_ch->exec() == QDialog::Accepted)
    {
        update();
    }
}



void student::on_pushButton_2_clicked()
{

    if (dialog_pay->exec() == QDialog::Accepted)
    {
        update();
    }
}

void student::on_pushButton_4_clicked()
{
    QApplication::quit();
}

