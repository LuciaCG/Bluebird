#ifndef LEARN_H
#define LEARN_H

#include <QWidget>

namespace Ui {
class learn;
}

class learn : public QWidget
{
    Q_OBJECT

public:
    explicit learn(QWidget *parent = 0, int _row = 10);
    ~learn();

private:
    Ui::learn *ui;
    int row;
};

#endif // LEARN_H