/********************************************************************************
** Form generated from reading UI file 'learn.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEARN_H
#define UI_LEARN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_learn
{
public:
    QWidget *Body;
    QWidget *Header_2;
    QLabel *lblTitle_5;
    QPushButton *btnHome_3;
    QLabel *lblTitle_6;
    QLabel *label_3;
    QLabel *clock_3;
    QTableView *tableView2;
    QPushButton *pushButton;

    void setupUi(QWidget *learn)
    {
        if (learn->objectName().isEmpty())
            learn->setObjectName(QStringLiteral("learn"));
        learn->resize(1050, 680);
        learn->setLayoutDirection(Qt::LeftToRight);
        learn->setStyleSheet(QStringLiteral("background-color: #f8f8f8;"));
        Body = new QWidget(learn);
        Body->setObjectName(QStringLiteral("Body"));
        Body->setGeometry(QRect(0, 0, 1005, 655));
        Body->setStyleSheet(QStringLiteral("background-color: #f8f8f8;"));
        Header_2 = new QWidget(Body);
        Header_2->setObjectName(QStringLiteral("Header_2"));
        Header_2->setGeometry(QRect(0, 0, 1051, 111));
        Header_2->setStyleSheet(QLatin1String("background-color:#555555;\n"
"color:#000000;"));
        lblTitle_5 = new QLabel(Header_2);
        lblTitle_5->setObjectName(QStringLiteral("lblTitle_5"));
        lblTitle_5->setGeometry(QRect(10, 10, 221, 31));
        lblTitle_5->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size:20pt;\n"
"font-weight:bold;"));
        btnHome_3 = new QPushButton(Header_2);
        btnHome_3->setObjectName(QStringLiteral("btnHome_3"));
        btnHome_3->setGeometry(QRect(870, 0, 101, 40));
        btnHome_3->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size: 21px;\n"
"border:0;"));
        lblTitle_6 = new QLabel(Header_2);
        lblTitle_6->setObjectName(QStringLiteral("lblTitle_6"));
        lblTitle_6->setGeometry(QRect(310, 10, 401, 101));
        lblTitle_6->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"text-align: center;\n"
"font-size:26pt;\n"
"font-weight:bold;"));
        label_3 = new QLabel(Header_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(870, 40, 281, 101));
        label_3->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size: 21px;"));
        clock_3 = new QLabel(Header_2);
        clock_3->setObjectName(QStringLiteral("clock_3"));
        clock_3->setGeometry(QRect(10, 80, 171, 31));
        clock_3->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size: 21px;"));
        tableView2 = new QTableView(Body);
        tableView2->setObjectName(QStringLiteral("tableView2"));
        tableView2->setGeometry(QRect(170, 150, 601, 341));
        tableView2->setStyleSheet(QStringLiteral("QHeaderView::section { background-color:#555555; color:#FFFFFF; font-weight:bold;}"));
        tableView2->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView2->horizontalHeader()->setHighlightSections(false);
        tableView2->verticalHeader()->setVisible(false);
        pushButton = new QPushButton(Body);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(790, 200, 211, 81));

        retranslateUi(learn);

        QMetaObject::connectSlotsByName(learn);
    } // setupUi

    void retranslateUi(QWidget *learn)
    {
        learn->setWindowTitle(QApplication::translate("learn", "Form", 0));
        lblTitle_5->setText(QApplication::translate("learn", "<User Logged in>", 0));
        btnHome_3->setText(QApplication::translate("learn", "Logout", 0));
        lblTitle_6->setText(QApplication::translate("learn", "<html><head/><body><p align=\"center\">Movies Screening</p></body></html>", 0));
        label_3->setText(QApplication::translate("learn", "Connection Status", 0));
        clock_3->setText(QApplication::translate("learn", "TextLabel", 0));
        pushButton->setText(QApplication::translate("learn", "Select", 0));
    } // retranslateUi

};

namespace Ui {
    class learn: public Ui_learn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEARN_H
