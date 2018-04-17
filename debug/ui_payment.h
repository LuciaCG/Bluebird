/********************************************************************************
** Form generated from reading UI file 'payment.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYMENT_H
#define UI_PAYMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_payment
{
public:
    QWidget *Body;
    QWidget *Header;
    QLabel *user;
    QPushButton *logout;
    QLabel *title;
    QLabel *clock;
    QLabel *connetion;
    QLabel *Test;

    void setupUi(QWidget *payment)
    {
        if (payment->objectName().isEmpty())
            payment->setObjectName(QStringLiteral("payment"));
        payment->resize(1051, 686);
        Body = new QWidget(payment);
        Body->setObjectName(QStringLiteral("Body"));
        Body->setGeometry(QRect(0, 0, 1051, 691));
        Body->setStyleSheet(QStringLiteral("background-color: #f8f8f8;"));
        Header = new QWidget(Body);
        Header->setObjectName(QStringLiteral("Header"));
        Header->setGeometry(QRect(0, 0, 1051, 111));
        Header->setStyleSheet(QLatin1String("background-color:#555555;\n"
"color:#000000;"));
        user = new QLabel(Header);
        user->setObjectName(QStringLiteral("user"));
        user->setGeometry(QRect(0, 0, 851, 91));
        user->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size:20pt;\n"
"font-weight:bold;"));
        logout = new QPushButton(Header);
        logout->setObjectName(QStringLiteral("logout"));
        logout->setGeometry(QRect(870, 0, 101, 40));
        logout->setStyleSheet(QLatin1String("background-color:#808080; color: #FFFFFF;\n"
"font-size: 21px;\n"
"border:3;"));
        title = new QLabel(Header);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(310, 10, 401, 101));
        title->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"text-align: center;\n"
"font-size:26pt;\n"
"font-weight:bold;"));
        clock = new QLabel(Header);
        clock->setObjectName(QStringLiteral("clock"));
        clock->setGeometry(QRect(10, 80, 171, 31));
        clock->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size: 21px;"));
        connetion = new QLabel(Header);
        connetion->setObjectName(QStringLiteral("connetion"));
        connetion->setGeometry(QRect(840, 30, 281, 101));
        connetion->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size: 21px;"));
        Test = new QLabel(Body);
        Test->setObjectName(QStringLiteral("Test"));
        Test->setGeometry(QRect(90, 210, 971, 131));

        retranslateUi(payment);

        QMetaObject::connectSlotsByName(payment);
    } // setupUi

    void retranslateUi(QWidget *payment)
    {
        payment->setWindowTitle(QApplication::translate("payment", "Form", 0));
        user->setText(QApplication::translate("payment", "<User Logged in>", 0));
        logout->setText(QApplication::translate("payment", "Logout", 0));
        title->setText(QApplication::translate("payment", "<html><head/><body><p align=\"center\">Seat Selection</p></body></html>", 0));
        clock->setText(QApplication::translate("payment", "TextLabel", 0));
        connetion->setText(QApplication::translate("payment", "Connection Status", 0));
        Test->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class payment: public Ui_payment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYMENT_H
