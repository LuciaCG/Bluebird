#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QMainWindow>
#include <QWidget>
#include <QtDebug>
#include <QFileInfo>
#include <QLCDNumber>
#include <QModelIndex>
#include <QSqlTableModel>
#include <QtWidgets>
#include <QSqlQuery>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_login_clicked();

private:
    Ui::Login *ui;
    QSqlDatabase firstDB;
};

#endif // LOGIN_H
