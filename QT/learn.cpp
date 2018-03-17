#include "learn.h"
#include "ui_learn.h"
#include <string>

learn::learn(QWidget *parent, int _row) :
    QWidget(parent),
    ui(new Ui::learn),
    row(_row)
{
    ui->setupUi(this);

    ui->lblTitle_6->setText(QString::number(row));

}

learn::~learn()
{
    delete ui;
}
