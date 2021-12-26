#include "welcome.h"
#include "ui_welcome.h"

welcome::welcome(QSqlDatabase &db) :
    QDialog(),
    ui(new Ui::welcome)
{
    ui->setupUi(this);
    m_db = db;
    if(!m_db.open()){
        ui->label->setText("Вход Закрыт!");
       // ui->centralwidget->setStyleSheet("background-color: #E35984");
    }
}
welcome::welcome() :
    QDialog(),
    ui(new Ui::welcome)
{
    ui->setupUi(this);
    /*if(!m_db.open()){
        ui->label->setText("Вход Закрыт!");
       // ui->centralwidget->setStyleSheet("background-color: #E35984");
    }*/
}

welcome::~welcome()
{
    delete ui;
}

void welcome::on_pushButton_clicked()
{
    QString Username, Password;
    Username = ui->login->text();
    Password=ui->pass->text();
    QSqlQuery query;
    query.prepare("SELECT role FROM liza_and_egor.users WHERE login='"+Username+"' AND password='"+Password+"'");
    query.exec();
    if (query.first())
    {
        this->hide();
        QString type = query.value(0).toString();
        if (type == "admin"){
            administrator *me = new administrator;
            me->show();
        }
        else{
            if (type == "teacher"){
                tutor *me = new tutor(this, Username);
                me->show();
            }
            else {
                if (type == "student"){
                    student *me = new student(this, Username);
                    me->show();
                }
                else{
                    ui->error->setText("Неправильный логин или пароль");
                }
            }
        }
     }
}

