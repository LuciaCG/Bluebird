#include "chairs.h"
#include "ui_chairs.h"
#include "payment.h"

chairs::chairs(QWidget *parent, QString _screen, int _id, QString _user) :
    QWidget(parent),
    ui(new Ui::chairs),
    screen(_screen), // SCREEN NUMBER
    id(_id),
    user(_user)
{
    ui->setupUi(this);
    ui->user->setText(user);

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


    // SCREENING

    // get capacity of room
    QSqlQuery queryRoom;
    queryRoom.exec("SELECT * FROM Screen");
    int capacity = 0;
    while (queryRoom.next()) {
            if (queryRoom.value(0).toString() == screen){
                capacity = queryRoom.value(1).toInt();
             }
        }

    QSqlQuery querySeats;
    querySeats.exec("SELECT * FROM Seats");

    int auxRow = 0, auxCol = 0;
    QString lastRow = "";
    int lastCol = 0;

    for (int n = 0; n < capacity; n++){ //how many rows and collumns we need?
        querySeats.next();
        if (lastRow < querySeats.value(0).toString()){ //we ned more rows
            auxRow++;
            lastRow = querySeats.value(0).toString();
        }
        if (lastCol < querySeats.value(1).toInt()){ //we need more collumns
            auxCol++;
            lastCol = querySeats.value(1).toInt();
        }
    }

    ui->tableWidget->setRowCount(auxRow);
    ui->tableWidget->setColumnCount(auxCol);

    // set the vertical headers
    char headerRow = 'a';
    QStringList listRow;

    for (int i = 0; i < auxRow; i++){
        listRow.append(QString(QChar::fromLatin1(headerRow)));
        headerRow++;
    }
    ui->tableWidget->setVerticalHeaderLabels(listRow);

    // set the horizontal heathers
    int headerCol = 0;
    QStringList listCol;

    for (int i = 0; i < auxCol; i++){
        headerCol++;
        listCol.append(QString::number(headerCol));
    }
    ui->tableWidget->setHorizontalHeaderLabels(listCol);

    // create squared cells
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(ui->tableWidget->horizontalHeader()->sectionSize(0));
    ui->tableWidget->setFixedSize(ui->tableWidget->horizontalHeader()->length()
                                  + ui->tableWidget->verticalHeader()->width(),
                                  ui->tableWidget->verticalHeader()->length()
                                  + ui->tableWidget->horizontalHeader()->height());

    // Initial style
    QString background = "background-color: green;";
    ui->tableWidget->setStyleSheet(background);

    QString header = "QHeaderView::section { background-color:#555555; color:#FFFFFF; font-weight:bold; }";
    ui->tableWidget->horizontalHeader()->setStyleSheet(header);
    ui->tableWidget->verticalHeader()->setStyleSheet(header);

    // compare vs the reserved seats
    QSqlQuery queryRes;
    queryRes.prepare("SELECT * FROM seat__reserved WHERE screening = ?;");
    queryRes.addBindValue(id);
    queryRes.exec();

    //queryRes.last();

    //ui->user->setText(queryRes.value(2).toString());

    Delegate * dg = new Delegate(this, id);
    ui->tableWidget->setItemDelegate(dg);

    ui->tableWidget->show();



    // CLOCK
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

chairs::~chairs()
{
    delete ui;
}

void chairs::on_back_clicked()
{
    this->hide();
    this->parentWidget()->show();
}

void chairs::on_logout_clicked()
{
    this->parentWidget()->parentWidget()->parentWidget()->show(); //show log in page
    this->parentWidget()->parentWidget()->close();
}

void chairs::on_selection_clicked()
{

    int totalNumber = ui->Adult->value() + ui->Child->value() +
            ui->OAP->value() + ui->VIP->value();

    int n = ui->tableWidget->selectionModel()->selectedIndexes().size();

    if(totalNumber < n ){
        ui->warning->setText("• Too many selected");
    }
    else if(totalNumber > n ){
        ui->warning->setText("• Too few selected");
    }
    else {

        if (n == 0){
            ui->warning->setText("• Please, select some seats");
        }
        else{
            ui->warning->setText("");

            int ticketAdult = ui->Adult->value() * 9;
            double ticketChild = ui->Child->value() * 6.5;
            int ticketOAP = ui->OAP->value() * 7;
            int ticketVIP = ui->VIP->value() * 12;
            double ticketTotal = ticketAdult + ticketChild + ticketOAP + ticketVIP;

            QString s = QString::number(ticketTotal);

            //send title to learn
            payment *instance = new payment(this, screen, id, user, ticketTotal);
            instance->show();
        }
    }
}

/*bool tableWidget::event(QEvent *event){
    if(event->type() == QEvent::MouseButtonPress){
        ui->user->setText("user");
    }
}
*/
/*
bool FilterObject::eventFilter(QObject *tableWidget, QEvent *event){

}


void mouseEvent::mousePressEvent(QMouseEvent *event)
{
 ui->user->setText("FUCK");

}
*/
