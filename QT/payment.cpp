#include "payment.h"
#include "ui_payment.h"
#include "chairs.h"



#include <QSqlTableModel>
#include <QTableView>
#include <QtSql>
#include <QHeaderView>
#include <QtWidgets>

payment::payment(QWidget *parent, QString _screen, int _id , QString _user, int _ticketTotal) :
    QWidget(parent),
    ui(new Ui::payment),
  screen(_screen), // SCREEN NUMBER
  id(_id),
  user(_user),
  ticketTotal(_ticketTotal)
{
  ui->setupUi(this);
  ui->user->setText(user);

    //Initialising the data base connection
    QSqlDatabase firstDB = QSqlDatabase::addDatabase("QSQLITE");
    firstDB.setHostName("bluebird");
        //getting the relative path of the database
    QDir bluebird = QDir::current();
    bluebird.cdUp();
    QString database = bluebird.path();
    firstDB.setDatabaseName(database + "/app.db");
        //connecting
    firstDB.open();
    if(!firstDB.open())
        ui->connetion->setText("FAILED");
     else
        ui->connetion->setText("Connected");

     ui->Test->setText(QString::number(ticketTotal));
}
payment::~payment()
{
    delete ui;
}
