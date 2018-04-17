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
    QLabel *connetion;
    QPushButton *back;
    QPushButton *selection;
    QTableWidget *tableWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *Adult;
    QSpinBox *Child;
    QSpinBox *OAP;
    QSpinBox *VIP;

    void setupUi(QWidget *chairs)
    {
        if (chairs->objectName().isEmpty())
            chairs->setObjectName(QStringLiteral("chairs"));
        chairs->resize(1006, 680);
        chairs->setStyleSheet(QStringLiteral("background-color: #f8f8f8;"));
        Body = new QWidget(chairs);
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
        user->setGeometry(QRect(0, 10, 851, 91));
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
        logout->raise();
        clock->raise();
        title->raise();
        user->raise();
        connetion->raise();
        back = new QPushButton(Body);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(10, 160, 111, 41));
        selection = new QPushButton(Body);
        selection->setObjectName(QStringLiteral("selection"));
        selection->setGeometry(QRect(790, 190, 211, 81));
        tableWidget = new QTableWidget(Body);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(140, 300, 621, 361));
        tableWidget->setAutoFillBackground(true);
        tableWidget->setStyleSheet(QStringLiteral(""));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
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
        label = new QLabel(Body);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 119, 141, 31));
        label_2 = new QLabel(Body);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(420, 650, 101, 20));
        label_3 = new QLabel(Body);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 159, 141, 31));
        label_4 = new QLabel(Body);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(170, 199, 141, 31));
        label_5 = new QLabel(Body);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(170, 239, 141, 31));
        Adult = new QSpinBox(Body);
        Adult->setObjectName(QStringLiteral("Adult"));
        Adult->setGeometry(QRect(260, 120, 50, 30));
        Child = new QSpinBox(Body);
        Child->setObjectName(QStringLiteral("Child"));
        Child->setGeometry(QRect(260, 160, 50, 30));
        OAP = new QSpinBox(Body);
        OAP->setObjectName(QStringLiteral("OAP"));
        OAP->setGeometry(QRect(260, 200, 50, 30));
        VIP = new QSpinBox(Body);
        VIP->setObjectName(QStringLiteral("VIP"));
        VIP->setGeometry(QRect(260, 240, 50, 30));
        back->raise();
        selection->raise();
        tableWidget->raise();
        Header->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        Adult->raise();
        Child->raise();
        OAP->raise();
        VIP->raise();

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
        connetion->setText(QApplication::translate("chairs", "Connection Status", 0));
        back->setText(QApplication::translate("chairs", "Back", 0));
        selection->setText(QApplication::translate("chairs", "Select", 0));
        label->setText(QApplication::translate("chairs", "ADULT", 0));
        label_2->setText(QApplication::translate("chairs", "TextLabel", 0));
        label_3->setText(QApplication::translate("chairs", "CHILD", 0));
        label_4->setText(QApplication::translate("chairs", "OAP", 0));
        label_5->setText(QApplication::translate("chairs", "VIP", 0));
    } // retranslateUi

};

namespace Ui {
    class chairs: public Ui_chairs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAIRS_H
