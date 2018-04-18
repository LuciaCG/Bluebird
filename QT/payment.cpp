#include "payment.h"
#include "ui_payment.h"

#include <QtWidgets>
#include <QSqlQuery>

payment::payment(QWidget *parent, QString _screen, int _id , QString _user, double _ticketTotal) :
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

     ui->due->setText(QString::number(ticketTotal));
}
payment::~payment()
{
    delete ui;
}

void payment::on_logout_clicked()
{
    this->parentWidget()->parentWidget()->parentWidget()->parentWidget()->show(); //show log in page
    this->parentWidget()->parentWidget()->parentWidget()->close();
}

void payment::on_back_clicked()
{
    this->hide();
    this->parentWidget()->show();
}
