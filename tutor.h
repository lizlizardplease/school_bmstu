#ifndef TUTOR_H
#define TUTOR_H

#include <QMainWindow>
#include <QtSql>
#include "change.h"

namespace Ui {
class tutor;
}

class tutor : public QMainWindow
{
    Q_OBJECT

public:
    explicit tutor(QWidget *parent = nullptr, QString login = "");
    ~tutor();

private slots:
    void on_change_clicked();
    void update();

private:
    Ui::tutor *ui;
    QSqlQueryModel *m_model;
    QString login;
    change *dialog;
};

#endif // TUTOR_H
