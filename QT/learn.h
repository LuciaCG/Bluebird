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
    explicit learn(QWidget *parent = 0, QString _name = "");
    ~learn();

private:
    Ui::learn *ui;
    QString name;
};

#endif // LEARN_H
