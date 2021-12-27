#ifndef ADDS_H
#define ADDS_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class adds;
}

class adds : public QDialog
{
    Q_OBJECT

public:
    explicit adds(QWidget *parent = nullptr, QString login = "");
    ~adds();

private slots:

    void on_tableView_pressed(const QModelIndex &index);

    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::adds *ui;
    QSqlQueryModel *m_model;
    QString login;
    QString chosen;
};

#endif // ADDS_H
