#ifndef ADDS_H
#define ADDS_H

#include <QDialog>

namespace Ui {
class adds;
}

class adds : public QDialog
{
    Q_OBJECT

public:
    explicit adds(QWidget *parent = nullptr);
    ~adds();

private:
    Ui::adds *ui;
};

#endif // ADDS_H
