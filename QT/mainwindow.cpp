#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlTableModel>
#include <QTableView>
#include <QtSql>
#include <QHeaderView>
#include <QtWidgets>
#include "learn.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Initialising the data base connection
    QSqlDatabase firstDB = QSqlDatabase::addDatabase("QSQLITE");
    firstDB.setHostName("bluebird");
    //Database location
    firstDB.setDatabaseName("/home/csunix/sc16rk/Year2/Project/bluebird/app.db");
    //Checks database connection
    firstDB.open();
    if(!firstDB.open())
        ui->label_2->setText("FAILED");
     else
        ui->label_2->setText("Connected");

    //Creating an SQL table model
    QSqlTableModel *model = new QSqlTableModel(this,firstDB);
    //Selecting the Table we want from DB
    model->setTable("Movies");
    model->removeColumn(0); // don't show the id
    model->removeColumn(1); // don't show the synopsis
    model->select();

    //Aesthetics
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Title"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Rating"));

    //Displaying the table in the Tableview
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setModel(model);

    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableView->show();


    QTimer *timer = new QTimer(this);
    //Sets an delay between each updateS
    timer->setInterval(1000);
    //using connect time to update the label
    connect(timer, &QTimer::timeout, [&]() {
       //Getting current time from the system and turning into string to be displayed
       QString ct = QTime::currentTime().toString();
       //setting the clock label to the current time
       ui->clock_2->setText(ct);
    } );
    //updates the clock
    timer->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BlackPanther_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    //check if title has been selected
    if ((ui->tableView->selectionModel()->isSelected(ui->tableView->currentIndex()))) {
        //check what title has been selected
        int row = index.row() + 1;
        //send title to learn
        learn *instance = new learn(this, row);
        instance->show();
    }
}
