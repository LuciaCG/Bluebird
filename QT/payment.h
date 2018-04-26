#ifndef PAYMENT_H
#define PAYMENT_H

#include <QLCDNumber>
#include <QtNetwork>

namespace Ui {
class payment;
}

class payment : public QWidget
{
    Q_OBJECT

public:
    explicit payment(QWidget *parent = 0, QString _screen = "", int _id = 0, QString _user = "", double _ticketTotal = 0,double _paid = 0,double _change = 0,QString _seatsSelected = "",QString _movieTime = "",QString _movieName = ""   );
    ~payment();

private slots:
    void on_back_clicked();
    void on_logout_clicked();
    void on_next_clicked();
    static void printQr();

private:
    Ui::payment *ui;
    QString screen;
    int id;
    QString user;
    double ticketTotal;
    double paid;
    double change;
    QString seatsSelected;
    QString movieTime;
    QString movieName;



    QNetworkReply * reply;
    QNetworkReply * reply1;

    bool connected;
    QByteArray data;
};

#endif // PAYMENT_H
