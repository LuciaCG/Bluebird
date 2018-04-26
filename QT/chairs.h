#ifndef CHAIRS_H
#define CHAIRS_H

#include <QtWidgets>
#include <QSqlQuery>
#include <QtNetwork>


class Delegate : public QItemDelegate
 {
 Q_OBJECT
 public:
    int id;
    QNetworkReply * replyRes;
    QByteArray dataRes;
    QEventLoop eventLoop;
    QJsonArray arrayRes;

    Delegate(QWidget *parent = 0, int _id = 0) : QItemDelegate(parent) {
        id = _id;

        QNetworkAccessManager managerRes;
        QObject::connect(&managerRes, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

        QUrl urlRes("http://localhost:5000/seatreserved.json");

        QNetworkRequest requestRes(urlRes);
        replyRes = managerRes.get(requestRes);

        eventLoop.exec();

        if (replyRes->error() == QNetworkReply::NoError)
            dataRes = replyRes->readAll();


        QJsonDocument responseRes = QJsonDocument::fromJson(dataRes);
        QJsonObject stuffRes = responseRes.object();
        QJsonValue valueRes = stuffRes.value("reserved");
        arrayRes = valueRes.toArray();

    }

    ~Delegate(){
        delete replyRes;

    }

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        int i = 0;
        bool found = false;

        while (i < arrayRes.size() && !found){

            if (id == arrayRes[i].toObject().value("screening").toInt()){

                QString row = arrayRes[i].toObject().value("rowReservedID").toString();
                int aux = 0;

                if (row == "A")
                    aux = 0;
                else if (row == "B")
                    aux = 1;
                else if (row == "C")
                    aux = 2;
                else if (row == "D")
                    aux = 3;
                else if (row == "E")
                    aux = 4;
                else if (row == "F")
                    aux = 5;
                else if (row == "G")
                    aux = 6;

                if (index.row() == aux && index.column() == arrayRes[i].toObject().value("seatNumberReservedID").toInt() -1){
                    painter->fillRect(option.rect, QBrush(Qt::red));
                    found = true;
                }
            }
            i++;
        }

     }
 };



namespace Ui {
class chairs;
}

class chairs : public QWidget
{
    Q_OBJECT

public:
    explicit chairs(QWidget *parent = 0, QString _screenName = "", int _screenID = 0, QString _user = "",QString _movieTime = "",QString _movieName = "");
    ~chairs();

private slots:
    void on_logout_clicked();
    void on_back_clicked();
    void on_selection_clicked();
    double totalPrice();
   // bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::chairs *ui;
    QString screenName;
    int screenID;
    QString user;
    QString movieTime;
    QString movieName;


    double priceC, priceA, priceV, priceO;

    QNetworkReply * replyCap;
    QByteArray dataCap;

    QNetworkReply * replySeats;
    QByteArray dataSeats;

    QNetworkReply * replyRes;
    QByteArray dataRes;

    QNetworkReply * replyTickets;
    QByteArray dataTickets;

    bool connected;
    QEventLoop eventLoop;

};

#endif // CHAIRS_H
