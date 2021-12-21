#ifndef MONEY_H
#define MONEY_H

#include <QDialog>

namespace Ui {
class money;
}

class money : public QDialog
{
    Q_OBJECT

public:
    explicit money(QWidget *parent = nullptr);
    ~money();

private:
    Ui::money *ui;
};

#endif // MONEY_H
