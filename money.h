#ifndef MONEY_H
#define MONEY_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>

namespace Ui {
class money;
}

class money : public QDialog
{
    Q_OBJECT

public:
    explicit money(QWidget *parent = nullptr);
    ~money();


private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::money *ui;
    QSqlQueryModel *m_model;
    QDate date1;
    QDate date2;
};

#endif // MONEY_H
