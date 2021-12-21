#include "tutor.h"
#include "ui_tutor.h"

tutor::tutor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tutor)
{
    ui->setupUi(this);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

tutor::~tutor()
{
    delete ui;
}
