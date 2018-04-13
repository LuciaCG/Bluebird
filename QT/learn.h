#ifndef LEARN_H
#define LEARN_H
#include <QStyledItemDelegate>

#include <QWidget>

namespace Ui {
class learn;
}

class learn : public QWidget
{
    Q_OBJECT

public:
    explicit learn(QWidget *parent = 0, QString _name = "", int _id = 0, QString _user = "");
    ~learn();

private slots:
    void on_pushButton_clicked();

private:
    Ui::learn *ui;
    QString name;
    int screen;
    QString user;
};

#endif // LEARN_H
