/********************************************************************************
** Form generated from reading UI file 'chairs.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAIRS_H
#define UI_CHAIRS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chairs
{
public:
    QWidget *Body;
    QWidget *Header;
    QLabel *user;
    QPushButton *logout;
    QLabel *title;
    QLabel *clock;
    QLabel *connection;
    QPushButton *back;
    QPushButton *selection;
    QTableWidget *tableWidget;
    QLabel *label_adult;
    QLabel *label_child;
    QLabel *label_oap;
    QLabel *label_vip;
    QSpinBox *Adult;
    QSpinBox *Child;
    QSpinBox *OAP;
    QSpinBox *VIP;
    QLabel *instruction1;
    QLabel *instruction2;
    QLabel *warning;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label;
    QLabel *price;

    void setupUi(QWidget *chairs)
    {
        if (chairs->objectName().isEmpty())
            chairs->setObjectName(QStringLiteral("chairs"));
        chairs->resize(1005, 690);
        chairs->setStyleSheet(QStringLiteral("background-color: #f8f8f8;"));
        Body = new QWidget(chairs);
        Body->setObjectName(QStringLiteral("Body"));
        Body->setGeometry(QRect(0, 0, 1005, 691));
        Body->setStyleSheet(QStringLiteral("background-color: #f8f8f8;"));
        Header = new QWidget(Body);
        Header->setObjectName(QStringLiteral("Header"));
        Header->setGeometry(QRect(0, 0, 1051, 111));
        Header->setStyleSheet(QLatin1String("background-color:#555555;\n"
"color:#000000;"));
        user = new QLabel(Header);
        user->setObjectName(QStringLiteral("user"));
        user->setGeometry(QRect(10, 0, 281, 61));
        user->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size:20pt;\n"
"font-weight:bold;"));
        logout = new QPushButton(Header);
        logout->setObjectName(QStringLiteral("logout"));
        logout->setGeometry(QRect(890, 10, 101, 41));
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
        connection->setGeometry(QRect(840, 30, 281, 101));
        connection->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size: 21px;"));
        clock->raise();
        title->raise();
        user->raise();
        connection->raise();
        logout->raise();
        back = new QPushButton(Body);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(10, 180, 111, 41));
        selection = new QPushButton(Body);
        selection->setObjectName(QStringLiteral("selection"));
        selection->setGeometry(QRect(780, 180, 211, 81));
        tableWidget = new QTableWidget(Body);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(140, 200, 621, 441));
        tableWidget->setAutoFillBackground(true);
        tableWidget->setStyleSheet(QStringLiteral(""));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::MultiSelection);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(0);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget->horizontalHeader()->setMinimumSectionSize(10);
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setCascadingSectionResizes(true);
        tableWidget->verticalHeader()->setDefaultSectionSize(100);
        tableWidget->verticalHeader()->setMinimumSectionSize(10);
        tableWidget->verticalHeader()->setStretchLastSection(false);
        label_adult = new QLabel(Body);
        label_adult->setObjectName(QStringLiteral("label_adult"));
        label_adult->setGeometry(QRect(140, 120, 141, 31));
        label_child = new QLabel(Body);
        label_child->setObjectName(QStringLiteral("label_child"));
        label_child->setGeometry(QRect(310, 120, 141, 31));
        label_oap = new QLabel(Body);
        label_oap->setObjectName(QStringLiteral("label_oap"));
        label_oap->setGeometry(QRect(140, 160, 141, 31));
        label_vip = new QLabel(Body);
        label_vip->setObjectName(QStringLiteral("label_vip"));
        label_vip->setGeometry(QRect(310, 160, 141, 31));
        Adult = new QSpinBox(Body);
        Adult->setObjectName(QStringLiteral("Adult"));
        Adult->setGeometry(QRect(200, 120, 50, 30));
        Child = new QSpinBox(Body);
        Child->setObjectName(QStringLiteral("Child"));
        Child->setGeometry(QRect(370, 120, 50, 30));
        OAP = new QSpinBox(Body);
        OAP->setObjectName(QStringLiteral("OAP"));
        OAP->setGeometry(QRect(200, 160, 50, 30));
        VIP = new QSpinBox(Body);
        VIP->setObjectName(QStringLiteral("VIP"));
        VIP->setGeometry(QRect(370, 160, 50, 30));
        instruction1 = new QLabel(Body);
        instruction1->setObjectName(QStringLiteral("instruction1"));
        instruction1->setGeometry(QRect(790, 350, 191, 41));
        instruction2 = new QLabel(Body);
        instruction2->setObjectName(QStringLiteral("instruction2"));
        instruction2->setGeometry(QRect(790, 380, 191, 41));
        warning = new QLabel(Body);
        warning->setObjectName(QStringLiteral("warning"));
        warning->setGeometry(QRect(790, 410, 191, 41));
        warning->setStyleSheet(QStringLiteral("color: red;"));
        doubleSpinBox = new QDoubleSpinBox(Body);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(560, 160, 72, 30));
        label = new QLabel(Body);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(460, 160, 171, 31));
        price = new QLabel(Body);
        price->setObjectName(QStringLiteral("price"));
        price->setGeometry(QRect(460, 120, 171, 31));
        label->raise();
        back->raise();
        selection->raise();
        tableWidget->raise();
        Header->raise();
        label_adult->raise();
        label_child->raise();
        label_oap->raise();
        label_vip->raise();
        Adult->raise();
        Child->raise();
        OAP->raise();
        VIP->raise();
        instruction1->raise();
        instruction2->raise();
        warning->raise();
        doubleSpinBox->raise();
        price->raise();

        retranslateUi(chairs);

        QMetaObject::connectSlotsByName(chairs);
    } // setupUi

    void retranslateUi(QWidget *chairs)
    {
        chairs->setWindowTitle(QApplication::translate("chairs", "Seats", 0));
        user->setText(QApplication::translate("chairs", "<User Logged in>", 0));
        logout->setText(QApplication::translate("chairs", "Logout", 0));
        title->setText(QApplication::translate("chairs", "<html><head/><body><p align=\"center\">Seat Selection</p></body></html>", 0));
        clock->setText(QApplication::translate("chairs", "TextLabel", 0));
        connection->setText(QString());
        back->setText(QApplication::translate("chairs", "Back", 0));
        selection->setText(QApplication::translate("chairs", "Select", 0));
        label_adult->setText(QApplication::translate("chairs", "ADULT", 0));
        label_child->setText(QApplication::translate("chairs", "CHILD", 0));
        label_oap->setText(QApplication::translate("chairs", "OAP", 0));
        label_vip->setText(QApplication::translate("chairs", "VIP", 0));
        instruction1->setText(QApplication::translate("chairs", "\342\200\242 Choose number of tickets", 0));
        instruction2->setText(QApplication::translate("chairs", "\342\200\242 Choose your seats", 0));
        warning->setText(QString());
        label->setText(QApplication::translate("chairs", "Amout paid", 0));
        price->setText(QApplication::translate("chairs", "To pay: ", 0));
    } // retranslateUi

};

namespace Ui {
    class chairs: public Ui_chairs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAIRS_H
