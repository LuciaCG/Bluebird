#include "login.h"
#include "mainwindow.h"

 #include <QCryptographicHash>
#include "ui_login.h"
#include <QSqlTableModel>
#include <QtWidgets>
#include <QSqlQuery>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
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
        ui->label_3->setText("FAILED");
     else
        ui->label_3->setText("Connected");

}
void Login::on_Login_2_clicked()
{
    QString user,pass;
    user = ui->Username->text();
    pass = ui->Password->text();


    QSqlQuery qry;
    qry.prepare("SELECT * FROM Employee");

    qry.exec();

    bool aux = true;
    while(qry.next() && aux){
        if(qry.value("name") == user){
            QString password = QString(QCryptographicHash::hash(pass.toLocal8Bit(), QCryptographicHash::Sha256).toHex());
            if (qry.value("password") == password)
                aux = false;
        }
    }
    if (aux)
        ui->label_3->setText("Incorrect password or username");
    else{
        MainWindow *instance = new MainWindow(this, user);
        instance->show();
        this->hide();
    }

}
Login::~Login()
{
    delete ui;
}

