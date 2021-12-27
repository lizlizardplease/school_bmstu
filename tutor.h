#ifndef TUTOR_H
#define TUTOR_H

#include <QMainWindow>
#include <QtSql>
#include <QMessageBox>
#include "change.h"
#include "pay.h"

namespace Ui {
class tutor;
}

class tutor : public QMainWindow
{
    Q_OBJECT

public:
    explicit tutor(QString login = "", QWidget *parent = nullptr);
    ~tutor();

private slots:
    void on_change_clicked();
    void update();

//<<<<<<< HEAD
//    void on_pushButton_money_clicked();
//=======
    void on_pay_clicked();
//>>>>>>> ddb503610846b20bbbb66a4275fdc3fe807dffc3

    void on_pushButton_clicked();

private:
    Ui::tutor *ui;
    QSqlQueryModel *m_model;
    QString login;
    change *dialog;
    pay *dialog1;
};

#endif // TUTOR_H
