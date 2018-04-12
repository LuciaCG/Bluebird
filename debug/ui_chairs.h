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
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chairs
{
public:
    QWidget *Body;
    QWidget *Header_2;
    QLabel *lblTitle_5;
    QPushButton *btnHome_3;
    QLabel *lblTitle_6;
    QLabel *label_3;
    QLabel *clock_3;
    QTableView *tableView3;

    void setupUi(QWidget *chairs)
    {
        if (chairs->objectName().isEmpty())
            chairs->setObjectName(QStringLiteral("chairs"));
        chairs->resize(1046, 686);
        chairs->setStyleSheet(QStringLiteral("background-color: #f8f8f8;"));
        Body = new QWidget(chairs);
        Body->setObjectName(QStringLiteral("Body"));
        Body->setGeometry(QRect(0, 0, 1051, 691));
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
        tableView3 = new QTableView(Body);
        tableView3->setObjectName(QStringLiteral("tableView3"));
        tableView3->setGeometry(QRect(220, 160, 611, 501));
        tableView3->setMinimumSize(QSize(611, 501));
        tableView3->setAutoFillBackground(false);
        tableView3->setStyleSheet(QStringLiteral("QHeaderView::section { background-color:#555555; color:#FFFFFF; font-weight:bold;}"));
        tableView3->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableView3->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableView3->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        tableView3->setSelectionBehavior(QAbstractItemView::SelectItems);
        tableView3->setShowGrid(true);
        tableView3->horizontalHeader()->setDefaultSectionSize(100);
        tableView3->horizontalHeader()->setHighlightSections(true);
        tableView3->horizontalHeader()->setMinimumSectionSize(50);
        tableView3->horizontalHeader()->setStretchLastSection(false);
        tableView3->verticalHeader()->setVisible(false);
        tableView3->verticalHeader()->setStretchLastSection(false);

        retranslateUi(chairs);

        QMetaObject::connectSlotsByName(chairs);
    } // setupUi

    void retranslateUi(QWidget *chairs)
    {
        chairs->setWindowTitle(QApplication::translate("chairs", "Form", 0));
        lblTitle_5->setText(QApplication::translate("chairs", "<User Logged in>", 0));
        btnHome_3->setText(QApplication::translate("chairs", "Logout", 0));
        lblTitle_6->setText(QApplication::translate("chairs", "<html><head/><body><p align=\"center\">Seat Selection</p></body></html>", 0));
        label_3->setText(QApplication::translate("chairs", "Connection Status", 0));
        clock_3->setText(QApplication::translate("chairs", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class chairs: public Ui_chairs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAIRS_H
