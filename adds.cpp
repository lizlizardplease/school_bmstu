#include "adds.h"
#include "ui_adds.h"

adds::adds(QWidget *parent, QString l) :
    QDialog(parent),
    ui(new Ui::adds)
{
    login = l;
    m_model = new QSqlQueryModel;
    ui->setupUi(this);
    ui->tableView->setModel(m_model);
    m_model->setQuery("SELECT title AS название, cost AS цена, (surname || ' ' || name) AS преподаватель FROM liza_and_egor.users INNER JOIN liza_and_egor.courses ON login = tutor");
    QSqlQuery query;
    query.prepare("SELECT bank FROM liza_and_egor.users WHERE login='"+login+"'");
    query.exec();
    query.next();
    ui->cash->setText(query.value(0).toString());
}

adds::~adds()
{
    delete ui;
}



void adds::on_tableView_pressed(const QModelIndex &index)
{
    if(index.column() == 0){
        ui->pushButton->setEnabled(1);
        chosen = index.data(0).toString();
        ui->pushButton->setText("Купить курс\n" + chosen);
    }
    else
    {
        ui->pushButton->setEnabled(0);
        ui->pushButton->setText("Купить");
    }
}


void adds::on_pushButton_clicked()
{
    QSqlQuery query;
    query.prepare("INSERT INTO liza_and_egor.courses_users VALUES ('"+chosen+"', '" + login + "');");
    QSqlQuery query1;
    query1.prepare("UPDATE liza_and_egor.courses SET amount=amount+1 WHERE title='"+chosen+"'");
    if (ui->pushButton->isEnabled())
    {
        query.exec();
        query1.exec();
        qDebug() << login << "  " << chosen;
        qDebug() << m_model->lastError();
        accept();
    }
}

