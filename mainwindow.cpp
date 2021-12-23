#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_db = QSqlDatabase::addDatabase("QPSQL");
    QSettings settings;
    settings.beginGroup("/Database_browser/settings");
    m_db.setDatabaseName(settings.value("Database_name", "fn1131_2021").toString());
    m_db.setHostName(settings.value("Host_ip", "195.19.32.74").toString());
    m_db.setPort(settings.value("P0rt", 5432).toInt());
    m_db.setUserName(settings.value("L0gin", "student").toString());
    m_db.setPassword(settings.value("Password", "bmstu").toString());
    settings.endGroup();
    if(!m_db.open()){
        ui->label->setText("Вход Закрыт!");
        ui->centralwidget->setStyleSheet("background-color: #E35984");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
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

