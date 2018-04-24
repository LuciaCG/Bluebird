#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "learn.h"

#include <QtSql>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent, QString _user) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    user(_user)
{
    ui->setupUi(this);
    ui->user->setText(user);
    ui->tableWidget->setFocus();

    QWidget::setTabOrder(ui->tableWidget, ui->select);
    QWidget::setTabOrder(ui->select, ui->logout);

    QNetworkAccessManager manager;
    QEventLoop eventLoop;
    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QUrl url("http://localhost:5000/movies.json");

    QNetworkRequest request(url);
    reply = manager.get(request);

    eventLoop.exec();

    if (reply->error() != QNetworkReply::NoError)
        ui->connection->setText("Failed Connection");
    else {
        connected = true;
        data = reply->readAll();
    }



    QJsonDocument response = QJsonDocument::fromJson(data);

    QJsonObject stuff = response.object();

    QJsonValue value = stuff.value("movies");

    QJsonArray array = value.toArray();

    int auxRow = array.size(), auxCol = 2;

    ui->tableWidget->setRowCount(auxRow);
    ui->tableWidget->setColumnCount(auxCol);

    QStringList Headers;
    Headers << "Title" << "Rating";
    ui->tableWidget->setHorizontalHeaderLabels(Headers);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for(int i = 0; i < array.size(); i++){
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(array[i].toObject().value("movieTitle").toString()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(array[i].toObject().value("ageRating").toString()));
    }

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget->show();

    QTimer *timer = new QTimer(this);
    //Sets an delay between each updateS
    timer->setInterval(1000);
    //using connect time to update the label
    connect(timer, &QTimer::timeout, [&]() {
       //Getting current time from the system and turning into string to be displayed
       QString ct = QTime::currentTime().toString();
       //setting the clock label to the current time
       ui->clock->setText(ct);
    } );
    //updates the clock
    timer->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_select_clicked()
{
    QModelIndex index = ui->tableWidget->currentIndex();
    //check if title has been selected
    if ((ui->tableWidget->selectionModel()->isSelected(ui->tableWidget->currentIndex()))) {
        //check what title has been selected
        int row = index.row();
        QString name = ui->tableWidget->model()->data(ui->tableWidget->model()->index(row,0)).toString();
        //send title to learn
        learn *instance = new learn(this, name, row + 1, user);
        instance->show();
    }
}

void MainWindow::on_logout_clicked()
{
    this->parentWidget()->show();
    this->close();
}

void MainWindow::keyPressEvent(QKeyEvent* pe)
{
    if(pe->key() == Qt::Key_Return) {
        QWidget * fw = QWidget::focusWidget();
        if (fw == ui->tableWidget || fw == ui->select) on_select_clicked();
        else if (fw == ui->logout) on_logout_clicked();
    }
}

