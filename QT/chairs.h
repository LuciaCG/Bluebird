#ifndef CHAIRS_H
#define CHAIRS_H

#include <QWidget>

namespace Ui {
class chairs;
}

class chairs : public QWidget
{
    Q_OBJECT

public:
    explicit chairs(QWidget *parent = 0, QString _screen = "", int _id = 0);
    ~chairs();

private:
    Ui::chairs *ui;
    QString screen;
    int id;
};

#endif // CHAIRS_H
