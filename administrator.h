#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QMainWindow>

namespace Ui {
class administrator;
}

class administrator : public QMainWindow
{
    Q_OBJECT

public:
    explicit administrator(QWidget *parent = nullptr);
    ~administrator();

private:
    Ui::administrator *ui;
};

#endif // ADMINISTRATOR_H
