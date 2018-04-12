#include "chairs.h"
#include "ui_chairs.h"

#include <QSqlTableModel>
#include <QtWidgets>
#include <QSqlQuery>

////////////////////////////////////////////
// DELEGATE CLASS TO HELP WITH CELLS STYLES
////////////////////////////////////////////

#include <QStyledItemDelegate>

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


/////////////////////////
// END OF DELEGATE CLASS
/////////////////////////




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

    // get seats reserved
    QSqlQuery querySeat;
    querySeat.prepare(QString("SELECT * FROM Seat_Reserved WHERE screening = %1").arg(id));
    querySeat.exec();

    //Create table with all screen seats
    QSqlTableModel *model = new QSqlTableModel(this,firstDB);

    //Selecting the Table we want from DB
    model->setTable("Seats");
    model->select();
    ui->tableView3->setModel(model);


   //Delegate *delegate = new Delegate();
    //ui->tableView3->setItemDelegate(delegate);


    for (int i = capacity; i < model->rowCount(); i++){
        ui->tableView3->hideRow(i); // remove seats that dont exist
      //model->setData(index, QColor(Qt::green), Qt::BackgroundColorRole)
      //model->setData(model->index(i, 1), QVariant(QBrush(Qt::red)), Qt::BackgroundRole);
    }

    //Displaying the table in the Tableview
    ui->tableView3->setEditTriggers(QAbstractItemView::NoEditTriggers);
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




