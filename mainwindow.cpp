#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    QSettings settings;
    settings.beginGroup("/Database_browser/settings");
    db.setDatabaseName(settings.value("Database_name", "fn1131_2021").toString());
    db.setHostName(settings.value("Host_ip", "195.19.32.74").toString());
    db.setPort(settings.value("P0rt", 5432).toInt());
    db.setUserName(settings.value("L0gin", "student").toString());
    db.setPassword(settings.value("Password", "bmstu").toString());
    settings.endGroup();
    if(!db.open()){
        ui->label->setText("Вход Закрыт!");
        ui->centralwidget->setStyleSheet("background-color: #E35984");
    }
}

MainWindow::~MainWindow()
{
    db.close();
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
        if (type == "admin")
        {
            administrator *me = new administrator;
            me->show();
        }
        else
        {
            if (type == "teacher")
            {
                tutor *me = new tutor(this, Username);
                me->show();
            }
            else
            {
                if (type == "student")
                {
                    student *me = new student(this, Username);
                    me->show();
                }
                else
                {
                    //ui->error->setText("Неправильный логин или пароль");
                    QMessageBox::critical(this, tr("Ошибка!"), tr("Неправильный логин или пароль!"));
                }
            }
        }
     }
    else
        QMessageBox::critical(this, tr("Ошибка!"), tr("Неправильный логин или пароль!"));
}

