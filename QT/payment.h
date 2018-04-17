#ifndef PAYMENT_H
#define PAYMENT_H

#include <QMainWindow>
#include <QWidget>
#include <QtDebug>
#include <QFileInfo>
#include <QLCDNumber>
#include <QModelIndex>

namespace Ui {
class payment;
}

class payment : public QWidget
{
    Q_OBJECT

public:
    explicit payment(QWidget *parent = 0, QString _screen = "", int _id = 0, QString _user = "", int _ticketTotal = 0);
    ~payment();

private slots:

private:
    Ui::payment *ui;
    QString screen;
    int id;
    QString user;
    int ticketTotal;
};

#endif // PAYMENT_H
