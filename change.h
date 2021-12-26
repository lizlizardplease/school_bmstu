#ifndef CHANGE_H
#define CHANGE_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class change;
}

class change : public QDialog
{
    Q_OBJECT

public:
    explicit change(QWidget *parent = nullptr, QString login = "");
    ~change();

private slots:
    void on_pushButton_clicked();
signals:
    void redef();
private:
    Ui::change *ui;
    QString login;
};
#endif // CHANGE_H
