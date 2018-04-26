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
#include <QtWidgets/QTableWidget>
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
    QLabel *connection;
    QLabel *due;
    QPushButton *back;
    QTableWidget *tableWidget;
    QPushButton *next;

    void setupUi(QWidget *payment)
    {
        if (payment->objectName().isEmpty())
            payment->setObjectName(QStringLiteral("payment"));
        payment->resize(1004, 697);
        Body = new QWidget(payment);
        Body->setObjectName(QStringLiteral("Body"));
        Body->setGeometry(QRect(0, 0, 1005, 690));
        Body->setStyleSheet(QStringLiteral("background-color: #f8f8f8;"));
        Header = new QWidget(Body);
        Header->setObjectName(QStringLiteral("Header"));
        Header->setGeometry(QRect(0, 0, 1051, 111));
        Header->setStyleSheet(QLatin1String("background-color:#555555;\n"
"color:#000000;"));
        user = new QLabel(Header);
        user->setObjectName(QStringLiteral("user"));
        user->setGeometry(QRect(10, 10, 861, 101));
        user->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size:20pt;\n"
"font-weight:bold;"));
        logout = new QPushButton(Header);
        logout->setObjectName(QStringLiteral("logout"));
        logout->setGeometry(QRect(880, 10, 101, 40));
        logout->setStyleSheet(QLatin1String("background-color:#c0c0c0; color: #555555;\n"
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
        connection = new QLabel(Header);
        connection->setObjectName(QStringLiteral("connection"));
        connection->setGeometry(QRect(850, 60, 281, 61));
        connection->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size: 21px;"));
        logout->raise();
        title->raise();
        clock->raise();
        connection->raise();
        user->raise();
        due = new QLabel(Body);
        due->setObjectName(QStringLiteral("due"));
        due->setGeometry(QRect(300, 140, 271, 71));
        back = new QPushButton(Body);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(20, 180, 111, 41));
        tableWidget = new QTableWidget(Body);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(150, 130, 731, 531));
        tableWidget->setStyleSheet(QStringLiteral("QHeaderView::section { background-color:#555555; color:#FFFFFF; font-weight:bold;}"));
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setTabKeyNavigation(false);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        next = new QPushButton(Body);
        next->setObjectName(QStringLiteral("next"));
        next->setGeometry(QRect(20, 380, 111, 41));

        retranslateUi(payment);

        QMetaObject::connectSlotsByName(payment);
    } // setupUi

    void retranslateUi(QWidget *payment)
    {
        payment->setWindowTitle(QApplication::translate("payment", "Form", 0));
        user->setText(QApplication::translate("payment", "<User Logged in>", 0));
        logout->setText(QApplication::translate("payment", "Logout", 0));
        title->setText(QApplication::translate("payment", "<html><head/><body><p align=\"center\">Payment</p></body></html>", 0));
        clock->setText(QApplication::translate("payment", "TextLabel", 0));
        connection->setText(QString());
        due->setText(QString());
        back->setText(QApplication::translate("payment", "Back", 0));
        next->setText(QApplication::translate("payment", "New", 0));
    } // retranslateUi

};

namespace Ui {
    class payment: public Ui_payment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYMENT_H
