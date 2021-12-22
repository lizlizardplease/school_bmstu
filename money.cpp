#include "money.h"
#include "ui_money.h"

money::money(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::money)
{
    ui->setupUi(this);
}

money::~money()
{
    delete ui;
}


