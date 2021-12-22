#include "adds.h"
#include "ui_adds.h"

adds::adds(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adds)
{
    ui->setupUi(this);
}

adds::~adds()
{
    delete ui;
}
