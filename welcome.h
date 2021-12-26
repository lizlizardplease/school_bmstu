#ifndef WELCOME_H
#define WELCOME_H

#include <QDialog>
#include <QtSql>
#include "administrator.h"
#include "tutor.h"
#include "student.h"
namespace Ui {
class welcome;
}

class welcome : public QDialog
{
    Q_OBJECT

public:
    explicit welcome(QSqlDatabase &db);
    welcome();
    ~welcome();

private slots:
    void on_pushButton_clicked();

private:
    Ui::welcome *ui;
    QSqlDatabase m_db;
};

#endif // WELCOME_H
