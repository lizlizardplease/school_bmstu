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
    QSqlQuery query1, query;
    query.prepare("SELECT * FROM liza_and_egor.users WHERE login='"+login+"'");
    query1.prepare("SELECT cost FROM liza_and_egor.courses WHERE title='"+chosen+"'");
    query.exec();
    query.next();
    query1.exec();
    query1.next();
    if (ui->pushButton->isEnabled())
    {
        qDebug() << query.value(7).toString().remove(0,1).toFloat();
        qDebug() << query1.value(0).toString().remove(0,1).toFloat() <<  query1.value(0).toString().remove(0,1);
        QString tmp =  query1.value(0).toString().remove(0,1);
        if(tmp.toFloat() > query.value(7).toString().remove(0,1).toFloat()){
            ui->out->setText("У вас нет столько денег...");
            return;
        }
        else{
        query1.prepare("UPDATE liza_and_egor.courses SET amount=amount+1 WHERE title='"+chosen+"'");
        m_model->setQuery("INSERT INTO liza_and_egor.courses_users VALUES ('"+chosen+"', '" + login + "');");
        if (!m_model->lastError().isValid()){
            query1.exec();
            query.prepare("UPDATE liza_and_egor.users SET bank = bank - '" + tmp + "' WHERE login='"+login+"'");
            query.exec();
        }
        else{
            ui->out->setText("Вы уже купили этот курс.");
            return;
        }
        accept();
        }
    }
}


void adds::on_pushButton_2_clicked()
{

}

