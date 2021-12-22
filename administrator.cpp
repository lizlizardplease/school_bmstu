#include "administrator.h"
#include "ui_administrator.h"

administrator::administrator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::administrator)
{
    ui->setupUi(this);
    m_model=new QSqlQueryModel;
    ui->tableView->setModel(m_model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    dialog = new money;
}

administrator::~administrator()
{
    delete ui;
}

void administrator::on_employee_clicked()
{
    m_model->setQuery("SELECT * FROM liza_and_egor.users WHERE role = 'teacher';");
}


void administrator::on_courses_clicked()
{
    m_model->setQuery("SELECT * FROM liza_and_egor.courses;");
}


void administrator::on_students_clicked()
{
    m_model->setQuery("SELECT * FROM liza_and_egor.users WHERE role = 'student';");
}


void administrator::on_cash_clicked()
{
   dialog->exec();
}

