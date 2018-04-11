#include "chairs.h"
#include "ui_chairs.h"

#include <QtWidgets>

chairs::chairs(QWidget *parent, QString _time, int _id) :
    QWidget(parent),
    ui(new Ui::chairs),
    time(_time),
    id(_id)
{
    ui->setupUi(this);



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
