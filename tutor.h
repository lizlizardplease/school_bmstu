#ifndef TUTOR_H
#define TUTOR_H

#include <QMainWindow>

namespace Ui {
class tutor;
}

class tutor : public QMainWindow
{
    Q_OBJECT

public:
    explicit tutor(QWidget *parent = nullptr);
    ~tutor();

private:
    Ui::tutor *ui;
};

#endif // TUTOR_H
