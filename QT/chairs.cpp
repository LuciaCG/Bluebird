#include "chairs.h"
#include "ui_chairs.h"
#include "payment.h"

chairs::chairs(QWidget *parent, QString _screenName, int _screenID, QString _user,QString _movieTime,QString _movieName) :
    QWidget(parent),
    ui(new Ui::chairs),
    screenName(_screenName), // SCREEN NUMBER
    screenID(_screenID),
    user(_user),
    movieTime(_movieTime),
    movieName(_movieName)

{
    ui->setupUi(this);
    ui->user->setText(user);

    QWidget::setTabOrder(ui->tableWidget, ui->selection);
    QWidget::setTabOrder(ui->selection, ui->logout);
    QWidget::setTabOrder(ui->logout, ui->back);

    // SCREENING

    QNetworkAccessManager managerCap;
    QObject::connect(&managerCap, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QUrl urlCap("http://localhost:5000/screen.json");

    QNetworkRequest requestCap(urlCap);
    replyCap = managerCap.get(requestCap);

    eventLoop.exec();

    if (replyCap->error() != QNetworkReply::NoError){
        ui->connection->setText("Failed Connection");
        connected = false;
    }
    else {
        connected = true;
        dataCap = replyCap->readAll();
    }

    QJsonDocument responseCap = QJsonDocument::fromJson(dataCap);

    QJsonObject stuffCap = responseCap.object();

    QJsonValue valueCap = stuffCap.value("screen");

    QJsonArray arrayCap = valueCap.toArray();

    int capacity = 0;
    bool found = false;
    int i = 0;

    while(i < arrayCap.size() && !found){

        if (arrayCap[i].toObject().value("screenName").toString() == screenName){
            capacity = arrayCap[i].toObject().value("Capacity").toInt();
            found = true;

        }
        i++;
    }


    // SEATS

    QNetworkAccessManager managerSeats;
    QObject::connect(&managerSeats, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QUrl urlSeats("http://localhost:5000/seats.json");

    QNetworkRequest requestSeats(urlSeats);
    replySeats = managerSeats.get(requestSeats);

    eventLoop.exec();

    if (replySeats->error() != QNetworkReply::NoError){
        ui->warning->setText("WARNING: Failed Connection");
        connected = false;
    }
    else
        dataSeats = replySeats->readAll();

    QJsonDocument responseSeats = QJsonDocument::fromJson(dataSeats);

    QJsonObject stuffSeats = responseSeats.object();

    QJsonValue valueSeats = stuffSeats.value("seats");

    QJsonArray arraySeats = valueSeats.toArray();


    int auxRow = 0, auxCol = 0;
    QString lastRow = "";
    int lastCol = 0;

    for (int i = 0; i < capacity; i++){ //how many rows and collumns we need?

        if (lastRow < arraySeats[i].toObject().value("row").toString()){ //we ned more rows
            auxRow++;
            lastRow = arraySeats[i].toObject().value("row").toString();
        }
        if (lastCol < arraySeats[i].toObject().value("seatNumber").toInt()){ //we need more collumns
            auxCol++;
            lastCol = arraySeats[i].toObject().value("seatNumber").toInt();
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


    QTimer *Seatsupdate = new QTimer(this);
    Seatsupdate->setInterval(100);
    //using connect time to update the label
    connect(Seatsupdate, &QTimer::timeout, [&]() {



    // SEATS RESERVED

    QNetworkAccessManager managerRes;
    QObject::connect(&managerRes, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QUrl urlRes("http://localhost:5000/seatreserved.json");

    QNetworkRequest requestRes(urlRes);
    replyRes = managerRes.get(requestRes);

    eventLoop.exec();

    if (replyRes->error() != QNetworkReply::NoError){
        ui->warning->setText("WARNING: Failed Connection");
        connected = false;
    }
    else
        dataRes = replyRes->readAll();

    QJsonDocument responseRes = QJsonDocument::fromJson(dataRes);

    QJsonObject stuffRes = responseRes.object();

    QJsonValue valueRes = stuffRes.value("reserved");

    QJsonArray arrayRes = valueRes.toArray();

    i = 0;
    while(i < arrayRes.size()){
        if (screenID == arrayRes[i].toObject().value("screening").toInt()){

            QString row = arrayRes[i].toObject().value("rowReservedID").toString();
            int col = arrayRes[i].toObject().value("seatNumberReservedID").toInt() - 1;
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
        i++;
    }

    // paint reserved seats
    Delegate * dg = new Delegate(this, screenID);
    ui->tableWidget->setItemDelegate(dg);


    // show seats
    ui->tableWidget->show();

    } );
    Seatsupdate->start();


    // TYPE OF TICKETS

    QNetworkAccessManager managerT;
    QObject::connect(&managerT, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QUrl urlT("http://localhost:5000/typetickets.json");

    QNetworkRequest requestT(urlT);
    replyTickets = managerT.get(requestT);

    eventLoop.exec();

    if (replyTickets->error() != QNetworkReply::NoError){
        ui->warning->setText("WARNING: Failed Connection");
        connected = false;
    }
    else
        dataTickets = replyTickets->readAll();

    QJsonDocument responseT = QJsonDocument::fromJson(dataTickets);

    QJsonObject stuffT = responseT.object();

    QJsonValue valueT = stuffT.value("tickets");

    QJsonArray arrayT = valueT.toArray();

    priceC = arrayT[0].toObject().value("price").toDouble();
    priceA = arrayT[1].toObject().value("price").toDouble();
    priceO = arrayT[2].toObject().value("price").toDouble();
    priceV = arrayT[3].toObject().value("price").toDouble();

    // read price when numnber of tickets are selected
    ui->Adult->installEventFilter(this);
    ui->Child->installEventFilter(this);
    ui->OAP->installEventFilter(this);
    ui->VIP->installEventFilter(this);

    QTimer *update = new QTimer(this);
    update->setInterval(100);
    //using connect time to update the label
    connect(update, &QTimer::timeout, [&]() {
       //Getting current time from the system and turning into string to be displayed
        double ticketAdult = ui->Adult->value() * priceA;
        double ticketChild = ui->Child->value() * priceC;
        double ticketOAP = ui->OAP->value() * priceO;
        double ticketVIP = ui->VIP->value() * priceV;
        double priceupdate = ticketAdult + ticketChild + ticketOAP + ticketVIP;

        ui->price->setText("To pay: " + QString::number(priceupdate));

       QString ct = QTime::currentTime().toString();
       ui->clock->setText(ct);
    } );
    update->start();


    //updates the clock
    // CLOCK
    QTimer *timer = new QTimer(this);
    //Sets an delay between each updateS
    timer->setInterval(1000);
    //using connect time to update the label
    connect(timer, &QTimer::timeout, [&]() {
       //Getting current time from the system and turning into string to be displayed
        double ticketAdult = ui->Adult->value() * priceA;
        double ticketChild = ui->Child->value() * priceC;
        double ticketOAP = ui->OAP->value() * priceO;
        double ticketVIP = ui->VIP->value() * priceV;
        double priceupdate = ticketAdult + ticketChild + ticketOAP + ticketVIP;

        ui->price->setText("To pay: " + QString::number(priceupdate));

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
    delete replyCap;
    delete replySeats;
    delete replyRes;
    delete replyTickets;
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

            double paid = ui->doubleSpinBox->value();
            double ticketTotal = totalPrice();

            double change = paid - ticketTotal;

            if (change < 0){
                ui->warning->setText("• Not enough paid");
            }
            else {

                /////////////////////////////////////////////////////
                //               Chairs
                /////////////////////////////////////////////////////

                QItemSelectionModel *selections = ui->tableWidget->selectionModel();
                QModelIndexList selected = selections->selectedIndexes();
                QString seatsSelected = "";

                for( int i = 0 ; i < selected.size(); i++ )
                {
                    int row = selected[i].row();
                    int col = selected[i].column();

                    QString rowLetter = "";
                    if(row == 0)
                        rowLetter = "A";
                    if(row == 1)
                        rowLetter = "B";
                    if(row == 2)
                        rowLetter = "C";
                    if(row == 3)
                        rowLetter = "D";
                    if(row == 4)
                        rowLetter = "E";
                    if(row == 5)
                        rowLetter = "F";
                    if(row == 6)
                        rowLetter = "G";

                    int columnNum = col + 1;
                    QString columnNumString = QString::number(columnNum);
                    seatsSelected = seatsSelected + rowLetter + columnNumString + "_";

                    QUrl serviceUrl = QUrl("http://localhost:5000/postjsonR");
                    QNetworkRequest request1(serviceUrl);
                    QJsonObject json;

                    json.insert("screening", QJsonValue(int(screenID)));
                    json.insert("rowReservedID", QJsonValue(QString(rowLetter)));
                    json.insert("seatNumberReservedID", QJsonValue(int(col+1)));


                    QJsonDocument jsonDoc(json);
                    QByteArray jsonData= jsonDoc.toJson();
                    request1.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
                    request1.setHeader(QNetworkRequest::ContentLengthHeader,QByteArray::number(jsonData.size()));
                    QNetworkAccessManager networkManager;

                    networkManager.post(request1, jsonData);

                    QNetworkAccessManager managerS;
                    QEventLoop eventLoop;
                    QObject::connect(&managerS, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
                    QUrl urlS("http://localhost:5000/seatreserved.json");
                    QNetworkRequest requestS(urlS);
                    managerS.get(requestS);
                    eventLoop.exec();
                }

                //////////////////////////////////////////////////////
                //                 make receipt
                //////////////////////////////////////////////////////

                QUrl serviceUrl = QUrl("http://localhost:5000/postjson");
                QNetworkRequest request1(serviceUrl);
                QJsonObject json;

                json.insert("price", QJsonValue(double(ticketTotal)));
                json.insert("pricePaid", QJsonValue(double(paid)));
                json.insert("change", QJsonValue(double(change)));
                json.insert("userName", QJsonValue(QString("Till")));
                json.insert("employeeName", QJsonValue(QString(user)));
                json.insert("screening", QJsonValue(int(screenID)));
                json.insert("seatsslected", QJsonValue(QString(seatsSelected+QString::number(screenID))));

                QJsonDocument jsonDoc(json);
                QByteArray jsonData= jsonDoc.toJson();
                request1.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
                request1.setHeader(QNetworkRequest::ContentLengthHeader,QByteArray::number(jsonData.size()));
                QNetworkAccessManager networkManager;

                networkManager.post(request1, jsonData);

                QNetworkAccessManager manager;
                QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
                QUrl url("http://localhost:5000/receipts.json");
                QNetworkRequest request(url);
                manager.get(request);
                eventLoop.exec();

                payment *instance = new payment(this, screenName, screenID, user, ticketTotal, paid, change,seatsSelected,movieTime,movieName);
                instance->show();
            }
        }
    }
}

/*
bool chairs::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress &&
            (watched == ui->Adult || watched == ui->Child || watched == ui->OAP|| watched == ui->VIP))
    {
        watched->event(event);
        double price = totalPrice();
        ui->price->setText("To pay: " + QString::number(price));
    }
    return false;
}
*/

double chairs::totalPrice(){
    double ticketAdult = ui->Adult->value() * priceA;
    double ticketChild = ui->Child->value() * priceC;
    double ticketOAP = ui->OAP->value() * priceO;
    double ticketVIP = ui->VIP->value() * priceV;
    return ticketAdult + ticketChild + ticketOAP + ticketVIP;

}

