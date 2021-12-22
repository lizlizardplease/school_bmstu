#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QMainWindow>
#include <QtSql>
#include "money.h"

namespace Ui {
class administrator;
}

class administrator : public QMainWindow
{
    Q_OBJECT

public:
    explicit administrator(QWidget *parent = nullptr);
    ~administrator();

private slots:
    void on_employee_clicked();

    void on_courses_clicked();

    void on_students_clicked();

    void on_cash_clicked();

private:
    Ui::administrator *ui;
    QSqlQueryModel *m_model;
    money* dialog;
};

#endif // ADMINISTRATOR_H
