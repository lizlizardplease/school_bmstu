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
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    dialog = new money;
    dialog->setWindowTitle("Меню доходов и расходов");
    dialog1 = new course;
    dialog1->setWindowTitle("Добавление нового курса");
    //
    // здесь добавить диалог для добавления нового пользователя
    //
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


void administrator::on_pushButton_clicked()
{
    if (dialog1->exec() == QDialog::Accepted){
        m_model->setQuery("SELECT * FROM liza_and_egor.courses;");
    }
}


void administrator::on_pushButton_3_clicked()
{
    QApplication::quit();
}

