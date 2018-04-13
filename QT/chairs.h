#ifndef CHAIRS_H
#define CHAIRS_H

#include <QWidget>
#include <QtGui>
#include <QtCore>
#include <QStyledItemDelegate>
namespace Ui {
class chairs;
}

class chairs : public QWidget
{
    Q_OBJECT

public:
    explicit chairs(QWidget *parent = 0, QString _screen = "", int _id = 0, QString _user = "");
    ~chairs();

private:
    Ui::chairs *ui;
    QString screen;
    int id;
    QString user;
};

#endif // CHAIRS_H
