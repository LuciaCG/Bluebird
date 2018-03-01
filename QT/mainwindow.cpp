#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlTableModel>
#include <QTableView>
#include <QtSql>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Connects the database
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("\testing.db");
    mydb.open();
    //Checks if the Database is open, changes label to its current status
    if(!mydb.open())
        ui->label->setText("FAILED");
    else
        ui->label->setText("Connected");

//All the methods dont throw errors but none of them display the data
    //TRY ONE TO DISPLAY
    //QSqlTableModel *model = new QSqlTableModel(this, mydb);
    //   model->setTable("Movies");
    //    model->setSort(2, Qt::DescendingOrder);
    //    model->select();
    //    model->setHeaderData(0, Qt::Horizontal, tr("Film"));
    //    ui->tableView->setModel(model);

            //TRY TWO TO DISPLAY
   //QSqlTableModel *model = new QSqlTableModel(this, mydb);
     //model->setTable("Movies");
     //model->setEditStrategy(QSqlTableModel::OnManualSubmit);
     //model->select();
     //model->setHeaderData(0, Qt::Horizontal, tr("Film"));
     //ui->tableView->setModel(model);


            //TRY Three TO DISPLAY
 //QSqlQueryModel * model = new QSqlQueryModel();
 //QSqlQuery* qry=new QSqlQuery(mydb);
 //qry->prepare("for a in models.Movies.query.all()");
 //qry->prepare("print(a.movieTitle)");
 //qry->exec();
 //model->setQuery(*qry);
 //ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

