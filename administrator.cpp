#include "administrator.h"
#include "ui_administrator.h"
#include "mainwindow.h"

administrator::administrator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::administrator)
{
    ui->setupUi(this);
    m_model=new QSqlQueryModel;
    ui->tableView->setModel(m_model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    dialog = new money;
    dialog1 = new course;
    dialog2 = new guest;
}

administrator::~administrator()
{
    delete ui;
}

void administrator::on_employee_clicked()
{
    m_model->setQuery("SELECT * FROM liza_and_egor.users WHERE role = 'teacher';");
    ui->label->setText("Все преподаватели");
}


void administrator::on_courses_clicked()
{
    m_model->setQuery("SELECT * FROM liza_and_egor.courses;");
    ui->label->setText("Все курсы");
}


void administrator::on_students_clicked()
{
    m_model->setQuery("SELECT * FROM liza_and_egor.users WHERE role = 'student';");
    ui->label->setText("Все ученики");
}


void administrator::on_cash_clicked()
{
   dialog->exec();
}


void administrator::on_pushButton_clicked()
{
    if (dialog1->exec() == QDialog::Accepted){
        m_model->setQuery("SELECT * FROM liza_and_egor.courses;");
        ui->label->setText("Все курсы");
    }
}


void administrator::on_pushButton_2_clicked()
{
    if (dialog2->exec() == QDialog::Accepted){
        m_model->setQuery("SELECT * FROM liza_and_egor.users;");
        ui->label->setText("Все пользователи");
    }
}



