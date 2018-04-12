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
    explicit learn(QWidget *parent = 0, QString _name = "", int _id = 0);
    ~learn();

private slots:
    void on_pushButton_clicked();

private:
    Ui::learn *ui;
    QString name;
    int screen;
};

#endif // LEARN_H
