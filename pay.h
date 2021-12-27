#ifndef PAY_H
#define PAY_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class pay;
}

class pay : public QDialog
{
    Q_OBJECT

public:
    explicit pay(QWidget *parent = nullptr, QString username = "");
    ~pay();

private slots:
    void on_pushButton_clicked();

private:
    Ui::pay *ui;
    QString login;
    bool type;
};

#endif // PAY_H
