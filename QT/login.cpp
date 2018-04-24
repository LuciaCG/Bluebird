#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"

#include <QtWidgets>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->Username->setFocus();
    QWidget::setTabOrder(ui->Username, ui->Password);
    QWidget::setTabOrder(ui->Password, ui->login);
    connected = false;

    QNetworkAccessManager manager;
    QEventLoop eventLoop;
    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QUrl url("http://localhost:5000/employee.json");

    QNetworkRequest request(url);
    reply = manager.get(request);

    eventLoop.exec();

    if (reply->error() != QNetworkReply::NoError)
        ui->warning->setText("WARNING: Failed Connection");
    else {
        connected = true;
        data = reply->readAll();
    }

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



    if (connected){



        QJsonDocument response = QJsonDocument::fromJson(data);

        QJsonObject stuff = response.object();

        QJsonValue value = stuff.value("employee");

        QJsonArray array = value.toArray();

        bool found = false;
        int i = 0;

        while(!found && i < array.size()){

            if(array[i].toObject().value("name").toString() == user){
                QString password = QString(QCryptographicHash::hash(pass.toLocal8Bit(), QCryptographicHash::Sha256).toHex());
                if (array[i].toObject().value("password").toString() == password)
                    found = true;
            }
            i++;
        }
        if (!found)
            ui->warning->setText("WARNING: Incorrect Password Or Username");
        else{
            ui->warning->setText("");
            MainWindow *instance = new MainWindow(this, user);
            instance->show();
            this->hide();
        }
    }
}

void Login::keyPressEvent(QKeyEvent* pe)
{
    if(pe->key() == Qt::Key_Return) on_login_clicked();
}

