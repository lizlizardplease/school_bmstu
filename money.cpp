#include "money.h"
#include "ui_money.h"

money::money(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::money)
{

    ui->setupUi(this);
    m_model=new QSqlQueryModel;
    ui->tableView->setModel(m_model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);


}

money::~money()
{
    delete ui;
}

// платить часть налогов
void money::on_pushButton_3_clicked()
{
    //QSqlQuery query;
    //query.prepare("SELECT * FROM liza_and_egor.courses WHERE (begin>=date2 AND begin<date)");
    //query.exec();
    //while(query.next())
    //{
        //ui->comboBox->addItem(query.value(0).toString());
    //}
    //m_model->setQuery("SELECT * FROM liza_and_egor.courses");
    QString new_date2=date2.toString();
    QString new_date1=date1.toString();
    m_model->setQuery("SELECT * FROM liza_and_egor.courses WHERE (begin>='"+new_date2+"') AND (begin<'"+new_date1+"');");
}

// платить налоги
void money::on_pushButton_clicked()
{

}

// забрать все себе в кошелек
void money::on_pushButton_2_clicked()
{
   // comboBox
    // m_model->setQuery("SELECT * FROM liza_and_egor.courses WHERE begin<;");
}

// показать формулу расчета прибыли
void money::on_pushButton_4_clicked()
{
    QMessageBox::information(this, tr("Прибыль"), tr("Общая (чистая) прибыль за месяц рассчитывается по секретной формуле: x-x*y-(x-x*y)*K, где "
                                                     "\nx - (Количество человек на курсе * Стоимость курса), "
                                                     "\ny - (Процент преподавателю + секретный коэффициент), "
                                                     "\nK - Коэффициент вашей жадности в этом месяце!"));
}


// кнопка создания даты
void money::on_pushButton_5_clicked()
{
    QString month=ui->comboBox->currentText(); // берем дату из комбобокса
    QString year=ui->comboBox_2->currentText(); // берем дату из комбобокса
    int month1=month.toInt();
    int year1 =year.toInt();
    int day1 =1;
    //date1(year1,month1,day1);
    date1.setDate(year1, month1, day1);
    day1=date1.daysInMonth();
    date1.setDate(year1, month1, day1);
    ui->label_2->setText(date1.toString());

    //date2(date1);
    date2.setDate(year1, month1, day1);
    int day2=-(date1.daysInMonth());
    date2=date2.addDays(day2);
    ui->label_3->setText(date2.toString());
}

