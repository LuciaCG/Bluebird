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
    explicit learn(QWidget *parent = 0);
    ~learn();

private:
    Ui::learn *ui;
};

#endif // LEARN_H
