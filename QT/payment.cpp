#include "payment.h"
#include "ui_payment.h"
#include "chairs.h"

#include <QtWidgets>
#include <QSqlQuery>
#include <QPrinter>
#include <QtSql>



payment::payment(QWidget *parent, QString _screen, int _id , QString _user, double _ticketTotal, double _paid, double _change, QString _seatsSelected,QString _movieTime,QString _movieName) :
    QWidget(parent),
    ui(new Ui::payment),
  screen(_screen), // SCREEN NUMBER
  id(_id),
  user(_user),
  ticketTotal(_ticketTotal),
  paid(_paid),
  change(_change),
  seatsSelected(_seatsSelected),
  movieTime(_movieTime),
  movieName(_movieName)

{
  ui->setupUi(this);
  ui->user->setText(user);
  ui->title->setText("Checkout");
  //QWidget::setTabOrder(ui->user, ui->logout);
  //QWidget::setTabOrder(ui->logout, ui->next);
  //QWidget::setTabOrder(ui->next, ui->user);

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


    QString ct = QTime::currentTime().toString();


    // DISPLAY RECEIPTS
    /*
    QNetworkAccessManager manager;
    QEventLoop eventLoop;
    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QUrl url("http://localhost:5000/receipts.json");

    QNetworkRequest request(url);
    reply = manager.get(request);

    eventLoop.exec();

    if (reply->error() != QNetworkReply::NoError)
          ui->connection->setText("Failed Connection");
    else {
        connected = true;
        data = reply->readAll();
    }

    QJsonDocument newResponse = QJsonDocument::fromJson(data);

    QJsonObject stuff = newResponse.object();

    QJsonValue value = stuff.value("receipt");
    QJsonArray array = value.toArray();

    int auxRow = array.size(), auxCol = 6;

    ui->tableWidget->setRowCount(auxRow);
    ui->tableWidget->setColumnCount(auxCol);

    QStringList Headers;
    Headers << "Employee" << "Screening" << "Price" << "Paid" << "Change" << "Transaction Time";
    ui->tableWidget->setHorizontalHeaderLabels(Headers);

    for(int i = 0; i < array.size(); i++){
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(array[i].toObject().value("employeeName").toString()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(array[i].toObject().value("screening").toInt())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(array[i].toObject().value("price").toDouble())));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(array[i].toObject().value("pricePaid").toDouble())));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(array[i].toObject().value("change").toDouble())));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(array[i].toObject().value("transactionTime").toString()));
    }

    //Displaying the table in the Tableview
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->tableWidget->setFixedSize(ui->tableWidget->horizontalHeader()->length()
                                      + ui->tableWidget->verticalHeader()->width(),
                                      ui->tableWidget->height());


    ui->tableWidget->show();
    */
     //ui->due->setText(QString::number(ticketTotal));
     QString fileName = seatsSelected + "" + QString::number(id); // Change name to movie ID + Seats being used
     if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

     QPrinter printer(QPrinter::PrinterResolution);
     printer.setOutputFormat(QPrinter::PdfFormat);
     printer.setPaperSize(QPrinter::A4);
     printer.setOutputFileName(fileName);

     QString path = "../app/static/images/" + seatsSelected+QString::number(id)+".png";
     QString pathReceipt = "../app/static/images/logoReceipt";
     QString split = seatsSelected;
     split.replace(QString("_"), QString(" "));
     QTextDocument doc;
     doc.setHtml(" <img src="+pathReceipt+" >"
                 "<h1> RECEIPT FOR: "+movieName+"</h1> "
                 "\n"
                 "<h1>Seats: "+ split + "</h1>"
                 "\n"
                 "<p>Screening: " + QString::number(id) +"</p>"
                 "\n"
                 "<p>Till Employee: "+ user + " </p>"
                 "\n"
                 "<p>Screening ID : "+ QString::number(id) +"</p>"
                 "<h2>MOVIE SCREEN : "+screen +"</h2>"
                 "<h3>MOVIE TIME: "+ movieTime + "</h3>"
                 "<p>amount paid: £"+ QString::number(paid) +"</p>"
                 "<p>Price: £"+ QString::number(ticketTotal) +"</p>"
                 "<p>Change: £"+ QString::number(change) +"</p>"
                 "<p>Time of transaction: "+ ct + "</p>"
                 "\n"
                 "<p> <img src="+path+" ></p>"
                 );
     doc.setPageSize(printer.pageRect().size());
     doc.print(&printer);

    ui->Movie->setText(screen);
    ui->Changes->setText("Chanege: £"+QString::number(change));
}
payment::~payment()
{
    delete ui;
    delete reply;
}


void payment::on_logout_clicked()
{
    this->parentWidget()->parentWidget()->parentWidget()->parentWidget()->show(); //show log in page
    this->parentWidget()->parentWidget()->parentWidget()->close();
}

void payment::on_next_clicked()
{
    this->parentWidget()->parentWidget()->parentWidget()->show(); //show movies page
    this->parentWidget()->parentWidget()->close();
}

