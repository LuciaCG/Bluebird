#include "login.h"
#include "mainwindow.h"
#include "ui_login.h"


#include <QCryptographicHash>
#include <QSqlTableModel>
#include <QtWidgets>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->Username->setFocus();
    QWidget::setTabOrder(ui->Username, ui->Password);
    QWidget::setTabOrder(ui->Password, ui->login);

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
        ui->warning->setText("WARNING: Failed Connexion");

}

Login::~Login()
{
    delete ui;
}

void Login::on_login_clicked()
{
    QString user,pass;
    user = ui->Username->text();
    pass = ui->Password->text();


    QSqlQuery qry;
    qry.prepare("SELECT * FROM Employee");

    qry.exec();

    bool aux = true;
    //qry.next(); // WE CAN'T USE "ONLINE"
    while(qry.next() && aux){
        if(qry.value("name") == user){
            QString password = QString(QCryptographicHash::hash(pass.toLocal8Bit(), QCryptographicHash::Sha256).toHex());
            if (qry.value("password") == password)
                aux = false;
        }
    }
    if (aux)
        ui->warning->setText("WARNING: Incorrect Password Or Username");
    else{
        ui->warning->setText("");
        MainWindow *instance = new MainWindow(this, user);
        instance->show();
        this->hide();
    }

}

void Login::keyPressEvent(QKeyEvent* pe)
{
    if(pe->key() == Qt::Key_Return) on_login_clicked();
}

