#ifndef LEARN_H
#define LEARN_H

#include <QStyledItemDelegate>

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
    void on_selection_clicked();
    void on_back_clicked();
    void on_logout_clicked();

private:
    Ui::learn *ui;
    QString name;
    int screen;
    QString user;
protected:
    void keyPressEvent(QKeyEvent* pe);
};

#endif // LEARN_H
