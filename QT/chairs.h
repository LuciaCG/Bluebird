#ifndef CHAIRS_H
#define CHAIRS_H

#include <QtWidgets>
#include <QSqlQuery>

class Delegate : public QItemDelegate
 {
 Q_OBJECT
 public:
    int id;

    Delegate(QWidget *parent = 0, int _id = 0) : QItemDelegate(parent) {
        id = _id;
    }

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        QSqlDatabase firstDB = QSqlDatabase::addDatabase("QSQLITE");
        firstDB.setHostName("bluebird");
            //getting the relative path of the database
        QDir bluebird = QDir::current();
        bluebird.cdUp();
        QString database = bluebird.path();
        firstDB.setDatabaseName(database + "/app.db");
            //connecting
        firstDB.open();

        QSqlQuery queryRes;
        queryRes.prepare("SELECT * FROM seat__reserved WHERE screening = ?;");
        queryRes.addBindValue(id);
        queryRes.exec();

        bool found = false;
        while (queryRes.next() && !found){
            QString row = queryRes.value(1).toString();
            int col = queryRes.value(2).toInt();
            int row2 = 0;

            if (row == "A"){
                row2 = 0;
                }
            else if (row == "B"){
                row2 = 1;
                }
            else if (row == "C")
                row2 = 2;
            else if (row == "D")
                row2 = 3;
            else if (row == "E")
                row2 = 4;
            else if (row == "F")
                row2 = 5;
            else if (row == "G")
                row2 = 6;

            if (index.row() == row2 && index.column() == col -1){
                painter->fillRect(option.rect, QBrush(Qt::red));
                found = true;
            }
        }
     }
 };



namespace Ui {
class chairs;
}

class chairs : public QWidget
{
    Q_OBJECT

public:
    explicit chairs(QWidget *parent = 0, QString _screen = "", int _id = 0, QString _user = "");
    ~chairs();

private slots:
    void on_logout_clicked();
    void on_back_clicked();
    void on_selection_clicked();

private:
    Ui::chairs *ui;
    QString screen;
    int id;
    QString user;

};

#endif // CHAIRS_H
