#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlTableModel>
#include <QTableView>
#include <QtSql>
#include <QHeaderView>
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
    model->setHeaderData(0, Qt::Horizontal, tr("Row1"));
    model->setHeaderData(1, Qt::Horizontal, tr("Row2"));
    ui->tableView->setModel(model);
    ui->tableView->show();
 //   QSqlQueryModel model;
 //   model.setQuery("SELECT * FROM movies");
 //   for (int i = 0; i < model.rowCount(); ++i) {
 //       QString movieTitle = model.record(i).value("movieTitle").toString();
 //       qDebug() << movieTitle;
 //  }


 //   QTableView *view = new QTableView;
 //   view->setModel(&model);
 //   view->show();
    //QTableView *view = new QTableView;
    //view->setModel(&model);
    //model->setHeaderData(0, Qt::Horizontal, QObject::tr("movieTitle"));
    //view->show();

    //
    //Old database setup
    //
    //Connects the database
   // QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  //  db.setDatabaseName("db");
   // db.open();
    //Checks if the Database is open, changes label to its current status
   // if(!db.open())
   //     ui->label->setText("FAILED");
   // else
     //   ui->label->setText("Connected");

   //QSqlQuery query(QSqlDatabase::database("db", false));



   // QSqlTableModel model;
   // model.setTable("Movies");
   // model.select();

   // QTableView view;
   // view.setModel(&model);
   // view.show();

    //model.setHeaderData(0, Qt::Horizontal, QObject::tr("movieTitle"));
    //ui->tableView->setModel(&model);



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

    // Create model for the sql table
    //QSqlTableModel * model = new QSqlTableModel(this, mydb);
     //   model->setTable("Movies");
    //    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //    model->select();

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
