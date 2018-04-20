#ifndef PAYMENT_H
#define PAYMENT_H

#include <QLCDNumber>

namespace Ui {
class payment;
}

class payment : public QWidget
{
    Q_OBJECT

public:
    explicit payment(QWidget *parent = 0, QString _screen = "", int _id = 0, QString _user = "", double _ticketTotal = 0,double _paid = 0,double _change = 0, QString _rowLetter = "", int columnNum = 0 );
    ~payment();

private slots:
    void on_back_clicked();
    void on_logout_clicked();
private:
    Ui::payment *ui;
    QString screen;
    int id;
    QString user;
    double ticketTotal;
    double paid;
    double change;
    QString rowLetter;
    int columnNum;
};

#endif // PAYMENT_H
