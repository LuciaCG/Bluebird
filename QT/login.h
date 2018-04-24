#ifndef LOGIN_H
#define LOGIN_H

#include <QLCDNumber>
#include <QSqlQuery>
#include <QtNetwork>

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
    QNetworkReply * reply;
    bool connected;
    QByteArray data;

protected:
    void keyPressEvent(QKeyEvent* pe);
};

#endif // LOGIN_H
