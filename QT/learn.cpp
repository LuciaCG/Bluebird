#include "learn.h"
#include "ui_learn.h"

#include <QSqlTableModel>
#include <QTableView>

learn::learn(QWidget *parent, QString _name) :
    QWidget(parent),
    ui(new Ui::learn),
    name(_name)
{
    ui->setupUi(this);

    //
    //Initialising the data base connection
    //
    QSqlDatabase firstDB = QSqlDatabase::addDatabase("QSQLITE");
    firstDB.setHostName("bluebird");
    firstDB.setDatabaseName("/home/csunix/sc16rk/Year2/Project/bluebird/app.db");
    firstDB.open();
    if(!firstDB.open())
        ui->label_3->setText("FAILED");
     else
        ui->label_3->setText("Connected");

    //set title of page
    ui->lblTitle_6->setText(name);

}

learn::~learn()
{
    delete ui;
}
