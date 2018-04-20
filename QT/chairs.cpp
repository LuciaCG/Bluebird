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


    QSqlQuery queryRes;

    queryRes.prepare("SELECT * FROM seat__reserved WHERE screening = ?;");
    queryRes.addBindValue(id);
    queryRes.exec();

    while(queryRes.next()){

        QString row = queryRes.value(1).toString();
        int col = queryRes.value(2).toInt() - 1;
        int row2 = 0;

        if (row == "A"){
            row2 = 0;
            }
        else if (row == "B"){
            row2 = 1;
            }
        else if (row == "C")
            row2 = 2;
        else if (row == "D")
            row2 = 3;
        else if (row == "E")
            row2 = 4;
        else if (row == "F")
            row2 = 5;
        else if (row == "G")
            row2 = 6;

        QTableWidgetItem *item = new QTableWidgetItem();
        item->setFlags(item->flags() ^ Qt::ItemIsSelectable);

        ui->tableWidget->setItem(row2, col, item);


    }


    // paint reserved seats
    Delegate * dg = new Delegate(this, id);
    ui->tableWidget->setItemDelegate(dg);




    // show seats
    ui->tableWidget->show();







    QSqlQuery queryPrice;
    queryPrice.exec("SELECT * FROM  type_of_tickets");
    while(queryPrice.next()){
        if (queryPrice.value(0).toString() == "Child")
            priceC = queryPrice.value(1).toDouble();
        else if (queryPrice.value(0).toString() == "Adult")
            priceA = queryPrice.value(1).toDouble();
        else if (queryPrice.value(0).toString() == "Senior")
            priceO = queryPrice.value(1).toDouble();
        else if (queryPrice.value(0).toString() == "VIP")
            priceV = queryPrice.value(1).toDouble();
    }

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

            //QItemSelectionModel *selectionModel = ui->tableWidget->selectionModel();
            //QModelIndexList *selectedRows = selectionModel->selectedIndexes();
           // if (selectedRows.size() > 0) {
           // ui->connetion->setText(QString::number(selectedRows->size()));
            //}
            // const QModelIndexList list = ui->tableWidget->selectionModel()->selection().indexes();
           // for (int i = 0; i < list.count(); i++)
             //   {
             //   QModelIndex index = list.at(i);
            //    ui->connetion->setText(QString::number(ui->tableWidget->Sel));
                //ui->user->setText(list.at(i));//QString::number(index));
           //     }

            QString rowLetter = "";
            if(ui->tableWidget->currentRow() == 0)
            {
            rowLetter = "A";
            }
            if(ui->tableWidget->currentRow() == 1)
            {
            rowLetter = "B";
            }
            if(ui->tableWidget->currentRow() == 2)
            {
            rowLetter = "C";
            }
            if(ui->tableWidget->currentRow() == 3)
            {
            rowLetter = "D";
            }
            if(ui->tableWidget->currentRow() == 4)
            {
            rowLetter = "E";
            }
            if(ui->tableWidget->currentRow() == 5)
            {
            rowLetter = "F";
            }
            if(ui->tableWidget->currentRow() == 6)
            {
            rowLetter = "G";
            }
            int columnNum = ui->tableWidget->currentColumn()+1;
            QSqlQuery query;
            query.prepare("INSERT INTO Seat__Reserved (screening,rowReservedID,seatNumberReservedID) "
                          "VALUES (?, ?, ?)");
            query.addBindValue(id);
            query.addBindValue(rowLetter);
            query.addBindValue(columnNum);


            query.exec();

            double paid = ui->doubleSpinBox->value();

            double ticketAdult = ui->Adult->value() * priceA;
            double ticketChild = ui->Child->value() * priceC;
            double ticketOAP = ui->OAP->value() * priceO;
            double ticketVIP = ui->VIP->value() * priceV;
            double ticketTotal = ticketAdult + ticketChild + ticketOAP + ticketVIP;

            double change = paid - ticketTotal;

            //send title to learn
            payment *instance = new payment(this, screen, id, user, ticketTotal, paid, change, rowLetter, columnNum);
            instance->show();
        }
    }
}

