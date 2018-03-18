#include "learn.h"
#include "ui_learn.h"

#include <QtWidgets>
#include <QSqlTableModel>
#include <QTableView>

learn::learn(QWidget *parent, QString _name, int _row) :
    QWidget(parent),
    ui(new Ui::learn),
    name(_name),
    row(_row)
{
    ui->setupUi(this);

    //
    //Initialising the data base connection
    //
    QSqlDatabase firstDB = QSqlDatabase::addDatabase("QSQLITE");
    firstDB.setHostName("bluebird");
    firstDB.setDatabaseName("/home/csunix/sc16rk/Year2/Project/bluebird/app.db");
    firstDB.open();
    if(!firstDB.open())
        ui->label_3->setText("FAILED");
     else
        ui->label_3->setText("Connected");

    //set title of page
    ui->lblTitle_6->setText(name);

    //Creating an SQL table model
    QSqlTableModel *model = new QSqlTableModel(this,firstDB);

    //Selecting the Table we want from DB
    model->setTable("Screenings");
    model->removeColumn(0); // don't show the id
    model->removeColumn(0); // remove movies_id
    model->setFilter(QString("movies_id = %1").arg(row));
    model->select();

    //Aesthetics
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Times Available"));

    //Displaying the table in the Tableview
    ui->tableView2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView2->setModel(model);

    ui->tableView2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableView2->show();


    QTimer *timer = new QTimer(this);
    //Sets an delay between each updateS
    timer->setInterval(1000);
    //using connect time to update the label
    connect(timer, &QTimer::timeout, [&]() {
       //Getting current time from the system and turning into string to be displayed
       QString ct = QTime::currentTime().toString();
       //setting the clock label to the current time
       ui->clock_3->setText(ct);
    } );
    //updates the clock
    timer->start();

}



learn::~learn()
{
    delete ui;
}
