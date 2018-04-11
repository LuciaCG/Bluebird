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
    explicit chairs(QWidget *parent = 0, QString _time = "", int _id = 0);
    ~chairs();

private:
    Ui::chairs *ui;
    QString time;
    int id;
};

#endif // CHAIRS_H
