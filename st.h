#ifndef ST_H
#define ST_H

#include <QDialog>

namespace Ui {
class Student;
}

class Student : public QDialog
{
    Q_OBJECT

public:
    explicit Student(QWidget *parent = nullptr);
    ~Student();

private:
    Ui::Student *ui;
};

#endif // ST_H
