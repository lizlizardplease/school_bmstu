#ifndef STUDENT_H
#define STUDENT_H

#include <QMainWindow>
#include <QtSql>
#include "adds.h"
#include "change.h"

namespace Ui {
class student;
}

class student : public QMainWindow
{
    Q_OBJECT

public:
    explicit student(QWidget *parent = nullptr, QString login = "");
    ~student();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    void update();
    Ui::student *ui;
    adds* dialog;
    QString login;
    QSqlQueryModel *m_model;
    change* dialog_ch;
};

#endif // STUDENT_H
