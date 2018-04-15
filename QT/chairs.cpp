#include "chairs.h"
#include "ui_chairs.h"

//#include <QSqlTableModel>
#include <QtWidgets>
#include <QSqlQuery>
#include <QTableWidget>

////////////////////////////////////////////
// DELEGATE CLASS TO HELP WITH CELLS STYLES
////////////////////////////////////////////

#include <QStyledItemDelegate>

/*
class Delegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit Delegate(QObject *parent = 0);
    Delegate(const QString &txt, QObject *parent = 0);

protected:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        QStyleOptionViewItem op(option);

        if (index.row()==2) {
            op.font.setBold(true);
            op.palette.setColor(QPalette::Normal, QPalette::Background, Qt::green);
            op.palette.setColor(QPalette::Normal, QPalette::Foreground, Qt::white);
        }
        QStyledItemDelegate::paint(painter, op, index);
    }

    //QSize sizeHint( const QStyleOptionViewItem &option,
                  //  const QModelIndex &index ) const;
    //QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
   // void setEditorData(QWidget * editor, const QModelIndex & index) const;
    //void setModelData(QWidget * editor, QAbstractItemModel * model, const QModelIndex & index) const;
    //void updateEditorGeometry(QWidget * editor, const QStyleOptionViewItem & option, const QModelIndex & index) const;

signals:

public slots:

};
*/

/////////////////////////
// END OF DELEGATE CLASS
/////////////////////////




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

    ui->user->setText(QString::number(auxCol));

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
    queryRes.exec("SELECT * FROM Seat_Reserved;");

    queryRes.last();
    ui->user->setText(queryRes.value(0).toString());



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

//void chairs::paintEvent(QPaintEvent *e)
//{
 //QPainter painter(this);
 //setBackgroundRole(QPalette::Blac);

//}


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



