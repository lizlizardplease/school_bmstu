#include "tutor.h"
#include "ui_tutor.h"


tutor::tutor(QString l, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tutor)
{
    this->login=l;
    dialog = new change(this, login);
    dialog->setWindowTitle("Изменение данных");
    ui->setupUi(this);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QSqlQuery query;
    query.prepare("SELECT * FROM liza_and_egor.users WHERE login='"+login+"'");
    query.exec();
    query.next();
    update();
    m_model = new QSqlQueryModel;
    ui->tableView->setModel(m_model);
    m_model->setQuery("SELECT title AS название FROM liza_and_egor.courses WHERE tutor='"+login+"'");
}

tutor::~tutor()
{
    delete ui;
}

void tutor::update()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM liza_and_egor.users WHERE login='"+login+"'");
    query.exec();
    query.next();
    ui->surn->setText(query.value(0).toString());
    ui->name->setText(query.value(1).toString());
    ui->papa->setText(query.value(2).toString());
    ui->mail->setText(query.value(3).toString());
    ui->ph->setText(query.value(8).toString());
}

void tutor::on_change_clicked()
{
    if (dialog->exec() == QDialog::Accepted){
        update();
        QMessageBox::information(this, tr("Изменение данных"), tr("Данные успешно сохранены."));
    }
}

void tutor::on_pushButton_money_clicked()
{
    // sql запрос на изменение баланса в таблице на 0
    QSqlQuery query;
    query.prepare ("UPDATE liza_and_egor.users SET bank=0 WHERE login='"+login+"'");
    if (query.exec())
        QMessageBox::information(this, tr("Баланс"), tr("Баланс успешно списан."));
}



