#ifndef STUDENT_H
#define STUDENT_H

#include <QMainWindow>
#include <QtSql>

namespace Ui {
class student;
}

class student : public QMainWindow
{
    Q_OBJECT

public:
    explicit student(QWidget *parent = nullptr, QString login = "");
    ~student();

private:
    Ui::student *ui;
};

#endif // STUDENT_H
