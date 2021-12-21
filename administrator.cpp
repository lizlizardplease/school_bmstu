#include "administrator.h"
#include "ui_administrator.h"

administrator::administrator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::administrator)
{
    ui->setupUi(this);
}

administrator::~administrator()
{
    delete ui;
}
