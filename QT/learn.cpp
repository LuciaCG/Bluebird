#include "learn.h"
#include "ui_learn.h"
#include "chairs.h"

#include <QSqlTableModel>

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
    ui->tableWidget->setFocus();

    QWidget::setTabOrder(ui->tableWidget, ui->selection);
    QWidget::setTabOrder(ui->selection, ui->logout);
    QWidget::setTabOrder(ui->logout, ui->back);

    QNetworkAccessManager manager;
    QEventLoop eventLoop;
    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QUrl url("http://localhost:5000/screens.json");

    QNetworkRequest request(url);
    reply = manager.get(request);

    eventLoop.exec();

    if (reply->error() != QNetworkReply::NoError)
        ui->connection->setText("Failed Connection");
    else {
        connected = true;
        data = reply->readAll();
    }

    QJsonDocument response = QJsonDocument::fromJson(data);

    QJsonObject stuff = response.object();

    QJsonValue value = stuff.value("screens");

    QJsonArray array = value.toArray();



    int auxCol = 2;
    ui->tableWidget->setColumnCount(auxCol);

    QStringList Headers;
    Headers << "Screen" <<"Times";
    ui->tableWidget->setHorizontalHeaderLabels(Headers);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    int aux = 0;
    for(int i = 0; i < array.size(); i++){
        if (array[i].toObject().value("movies_id").toInt() == screen){
            ui->tableWidget->insertRow(aux);
            ui->tableWidget->setItem(aux, 0, new QTableWidgetItem(array[i].toObject().value("screen_id").toString()));
            ui->tableWidget->setItem(aux, 1, new QTableWidgetItem(array[i].toObject().value("time").toString()));
            aux++;
        }
    }

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget->show();



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
    delete reply;
}

void learn::on_selection_clicked()
{
    QModelIndex index = ui->tableWidget->currentIndex();
    //check if time has been selected
    if ((ui->tableWidget->selectionModel()->isSelected(ui->tableWidget->currentIndex()))) {
        //check what screen has been selected
        int row = index.row();
        int id = 0;

        QString screenName = ui->tableWidget->model()->data(ui->tableWidget->model()->index(row,0)).toString();
        QString time = ui->tableWidget->model()->data(ui->tableWidget->model()->index(row,1)).toString();

        QJsonDocument response = QJsonDocument::fromJson(data);
        QJsonObject stuff = response.object();
        QJsonValue value = stuff.value("screens");
        QJsonArray array = value.toArray();
        int i = 0;
        while(i < array.size() ){
            if (array[i].toObject().value("screen_id").toString() == screenName
                    && array[i].toObject().value("time").toString() == time){
                id = (int)(array[i].toObject().value("id").toInt());
            }
            i++;
        }

        //send title to learn
        chairs *instance = new chairs(this, screenName, id, user);
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
        if (fw == ui->tableWidget || fw == ui->selection) on_selection_clicked();
        else if (fw == ui->logout) on_logout_clicked();
        else if (fw == ui->back) on_back_clicked();
    }
}
