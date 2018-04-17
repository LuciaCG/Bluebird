#ifndef CHAIRS_H
#define CHAIRS_H

#include <QWidget>
#include <QtGui>
#include <QtCore>
#include <QStyledItemDelegate>
#include <QtWidgets>
#include <QSqlQuery>
#include <QSqlError>
#include <QTableWidget>
#include <QSpinBox>

#include <QItemDelegate>


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

        while (queryRes.next()){
            int row = queryRes.value(1).toInt();
            int col = queryRes.value(2).toInt();

            if (index.row() == row && index.column() == col)
                painter->fillRect(option.rect, QBrush(Qt::red));
        }
     };

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
