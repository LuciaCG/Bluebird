#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlTableModel>
#include <QTableView>
#include <QtSql>
#include <QHeaderView>
#include <QtWidgets>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase firstDB = QSqlDatabase::addDatabase("QSQLITE");
    firstDB.setHostName("bluebird");
    firstDB.setDatabaseName("/home/csunix/sc16rk/Year2/Project/bluebird/app.db");
    firstDB.open();
    if(!firstDB.open())
        ui->label->setText("FAILED");
     else
        ui->label->setText("Connected");

    QSqlTableModel *model = new QSqlTableModel(this,firstDB);
    model->setTable("Movies");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Movie Title"));
    ui->tableView->setModel(model);
    ui->tableView->show();


    QTimer *timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, &QTimer::timeout, [&]() {
       QString ct = QTime::currentTime().toString();
       ui->clock->setText(ct);
    } );
    timer->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}
