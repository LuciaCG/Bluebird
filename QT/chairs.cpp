#include "chairs.h"
#include "ui_chairs.h"

#include <QSqlTableModel>
#include <QtWidgets>
#include <QSqlQuery>

chairs::chairs(QWidget *parent, QString _screen, int _id) :
    QWidget(parent),
    ui(new Ui::chairs),
    screen(_screen), // SCREEN NUMBER
    id(_id)
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


    ui->lblTitle_6->setText("FUCK!");



    // SCREENING
    //Creating an SQL table model
    QSqlTableModel *model = new QSqlTableModel(this,firstDB);

    //Selecting the Table we want from DB
    model->setTable("Screen");

    QSqlQuery query;
    query.exec("SELECT * FROM Screen");
    while (query.next()) {
            if (query.value(0).toString() == screen)
                ui->lblTitle_6->setText(query.value(1).toString());
        }


    //Displaying the table in the Tableview
    ui->tableView3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView3->setModel(model);

    ui->tableView3->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableView3->show();











    // CLOCK
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

chairs::~chairs()
{
    delete ui;
}
