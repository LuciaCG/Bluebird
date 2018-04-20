#include "payment.h"
#include "ui_payment.h"

#include <QtWidgets>
#include <QSqlQuery>
#include <QPrinter>
#include <QtSql>

payment::payment(QWidget *parent, QString _screen, int _id , QString _user, double _ticketTotal, double _paid, double _change, QString _seatsSelected) :
    QWidget(parent),
    ui(new Ui::payment),
  screen(_screen), // SCREEN NUMBER
  id(_id),
  user(_user),
  ticketTotal(_ticketTotal),
  paid(_paid),
  change(_change),
  seatsSelected(_seatsSelected)
{
  ui->setupUi(this);
  ui->user->setText(user);
  QString ct = QTime::currentTime().toString();
  QDateTime current = QDateTime::currentDateTime();
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
    model->setTable("Seat__Reserved");
    model->select();

//receipts

    //Displaying the table in the Tableview
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setModel(model);

    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->show();


    QSqlQuery query;
    query.prepare("INSERT INTO receipts (userName, employeeName,screening,price,pricePaid,change,transactionTime) "
                  "VALUES (?, ?, ?,?,?,?,?)");
    query.addBindValue("TILL");
    query.addBindValue(user);
    query.addBindValue(id);
    query.addBindValue(ticketTotal);
    query.addBindValue(paid);
    query.addBindValue(change);
    query.addBindValue(current);

    query.exec();

     ui->due->setText(QString::number(ticketTotal));
     QString fileName = seatsSelected + "" + QString::number(id); // Change name to movie ID + Seats being used
     if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

     QPrinter printer(QPrinter::PrinterResolution);
     printer.setOutputFormat(QPrinter::PdfFormat);
     printer.setPaperSize(QPrinter::A4);
     printer.setOutputFileName(fileName);

     QTextDocument doc;

     doc.setHtml("<h1> RECEIPT FOR: Seats: "+ seatsSelected + " Screening:" + QString::number(id) +"</h1>"
                 "\n"
                 "<p>Till Employee: "+ user + " </p>"
                 "\n"
                 "<p>Screening ID : "+ QString::number(id) +"</p>"
                 "<h2>MOVIE SCREEN : "+screen +"</h2>"
                 "<p>amount paid: £"+ QString::number(paid) +"</p>"
                 "<p>Price: £"+ QString::number(ticketTotal) +"</p>"
                 "<p>Change: £"+ QString::number(change) +"</p>"
                 "<p>Time of transaction: "+ ct + "</p>"
                 );
     doc.setPageSize(printer.pageRect().size());
     doc.print(&printer);
}
payment::~payment()
{
    delete ui;
}

void payment::on_logout_clicked()
{
    this->parentWidget()->parentWidget()->parentWidget()->parentWidget()->show(); //show log in page
    this->parentWidget()->parentWidget()->parentWidget()->close();
}

void payment::on_back_clicked()
{
    this->hide();
    this->parentWidget()->show();
}
