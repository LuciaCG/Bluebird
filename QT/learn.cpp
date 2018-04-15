#include "learn.h"
#include "ui_learn.h"
#include "chairs.h"
#include "mainwindow.h"

#include <QtWidgets>
#include <QSqlTableModel>
#include <QTableView>

learn::learn(QWidget *parent, QString _name, int _id, QString _user) :
    QWidget(parent),
    ui(new Ui::learn),
    name(_name),
    screen(_id),
    user(_user)
{
    ui->setupUi(this);
    ui->user->setText(user);
    ui->title->setText(name);
    ui->tableView->setFocus();
    QWidget::setTabOrder(ui->tableView, ui->selection);
    QWidget::setTabOrder(ui->selection, ui->logout);
    QWidget::setTabOrder(ui->logout, ui->back);


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
        ui->connetion->setText("FAILED");
     else
        ui->connetion->setText("Connected");


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
    ui->tableView->setModel(model);

    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(1);

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QModelIndex index = ui->tableView->model()->index(0 , 0);
    ui->tableView->setCurrentIndex(index);
    ui->tableView->show();


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



learn::~learn()
{
    delete ui;
}

void learn::on_selection_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    //check if time has been selected
    if ((ui->tableView->selectionModel()->isSelected(ui->tableView->currentIndex()))) {
        //check what screen has been selected
        int row = index.row();
        QString time = ui->tableView->model()->data(ui->tableView->model()->index(row,2)).toString();
        int id = ui->tableView->model()->data(ui->tableView->model()->index(row,0)).toInt();

        //send title to learn
        chairs *instance = new chairs(this, time, id, user);
        instance->show();
    }
}

void learn::on_back_clicked()
{
    this->hide();
    this->parentWidget()->show();
}

void learn::on_logout_clicked()
{
    this->parentWidget()->parentWidget()->show(); //show log in page
    this->parentWidget()->close();
}

void learn::keyPressEvent(QKeyEvent* pe)
{
    if(pe->key() == Qt::Key_Return) {
        QWidget * fw = QWidget::focusWidget();
        if (fw == ui->tableView || fw == ui->selection) on_selection_clicked();
        else if (fw == ui->logout) on_logout_clicked();
        else if (fw == ui->back) on_back_clicked();
    }
}
