#ifndef GUEST_H
#define GUEST_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class guest;
}

class guest : public QDialog
{
    Q_OBJECT

public:
    explicit guest(QWidget *parent = nullptr);
    ~guest();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::guest *ui;
};

#endif // GUEST_H
