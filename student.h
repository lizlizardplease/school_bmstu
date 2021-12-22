#ifndef STUDENT_H
#define STUDENT_H

#include <QMainWindow>
#include <QtSql>
#include "adds.h"

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

private:
    Ui::student *ui;
    adds* dialog;
};

#endif // STUDENT_H
