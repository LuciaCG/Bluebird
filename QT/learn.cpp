#include "learn.h"
#include "ui_learn.h"

learn::learn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::learn)
{
    ui->setupUi(this);
}

learn::~learn()
{
    delete ui;
}
