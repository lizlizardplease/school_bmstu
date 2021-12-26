#ifndef TUTOR_H
#define TUTOR_H

#include <QMainWindow>
#include <QtSql>
#include <QMessageBox>
#include "change.h"

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

    void on_pushButton_money_clicked();

private:
    Ui::tutor *ui;
    QSqlQueryModel *m_model;
    QString login;
    change *dialog;
};

#endif // TUTOR_H
