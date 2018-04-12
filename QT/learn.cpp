#include "learn.h"
#include "ui_learn.h"
#include "chairs.h"

#include <QtWidgets>
#include <QSqlTableModel>
#include <QTableView>

learn::learn(QWidget *parent, QString _name, int _id) :
    QWidget(parent),
    ui(new Ui::learn),
    name(_name),
    screen(_id)
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

    //set title of page
    ui->lblTitle_6->setText(name);

    //Creating an SQL table model
    QSqlTableModel *model = new QSqlTableModel(this,firstDB);

    //Selecting the Table we want from DB
    model->setTable("Screenings");
    model->setFilter(QString("movies_id = %1").arg(screen));
    model->select();

    //Aesthetics
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Screens"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Times Available"));

    //Displaying the table in the Tableview
    ui->tableView2->setModel(model);

    ui->tableView2->hideColumn(0);
    ui->tableView2->hideColumn(1);

    ui->tableView2->setEditTriggers(QAbstractItemView::NoEditTriggers);


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

void learn::on_pushButton_clicked()
{
    QModelIndex index = ui->tableView2->currentIndex();
    //check if time has been selected
    if ((ui->tableView2->selectionModel()->isSelected(ui->tableView2->currentIndex()))) {
        //check what screen has been selected
        int row = index.row();
        QString time = ui->tableView2->model()->data(ui->tableView2->model()->index(row,2)).toString();
        int id = ui->tableView2->model()->data(ui->tableView2->model()->index(row,0)).toInt();

        //send title to learn
        chairs *instance = new chairs(this, time, id);
        instance->show();
    }
}
