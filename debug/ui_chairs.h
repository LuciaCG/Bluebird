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
    QWidget *Header;
    QLabel *user;
    QPushButton *logout;
    QLabel *title;
    QLabel *connetion;
    QLabel *clock;
    QTableView *tableView;
    QPushButton *back;
    QPushButton *selection;

    void setupUi(QWidget *chairs)
    {
        if (chairs->objectName().isEmpty())
            chairs->setObjectName(QStringLiteral("chairs"));
        chairs->resize(1006, 675);
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
        user->setGeometry(QRect(10, 10, 221, 31));
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
        connetion = new QLabel(Header);
        connetion->setObjectName(QStringLiteral("connetion"));
        connetion->setGeometry(QRect(870, 40, 281, 101));
        connetion->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size: 21px;"));
        clock = new QLabel(Header);
        clock->setObjectName(QStringLiteral("clock"));
        clock->setGeometry(QRect(10, 80, 171, 31));
        clock->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size: 21px;"));
        tableView = new QTableView(Body);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(140, 160, 641, 501));
        tableView->setMinimumSize(QSize(611, 501));
        tableView->setAutoFillBackground(false);
        tableView->setStyleSheet(QStringLiteral("QHeaderView::section { background-color:#555555; color:#FFFFFF; font-weight:bold;}"));
        tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        tableView->setSelectionBehavior(QAbstractItemView::SelectItems);
        tableView->setShowGrid(true);
        tableView->horizontalHeader()->setDefaultSectionSize(100);
        tableView->horizontalHeader()->setHighlightSections(true);
        tableView->horizontalHeader()->setMinimumSectionSize(50);
        tableView->horizontalHeader()->setStretchLastSection(false);
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setStretchLastSection(false);
        back = new QPushButton(Body);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(10, 160, 111, 41));
        selection = new QPushButton(Body);
        selection->setObjectName(QStringLiteral("selection"));
        selection->setGeometry(QRect(790, 190, 211, 81));

        retranslateUi(chairs);

        QMetaObject::connectSlotsByName(chairs);
    } // setupUi

    void retranslateUi(QWidget *chairs)
    {
        chairs->setWindowTitle(QApplication::translate("chairs", "Seats", 0));
        user->setText(QApplication::translate("chairs", "<User Logged in>", 0));
        logout->setText(QApplication::translate("chairs", "Logout", 0));
        title->setText(QApplication::translate("chairs", "<html><head/><body><p align=\"center\">Seat Selection</p></body></html>", 0));
        connetion->setText(QApplication::translate("chairs", "Connection Status", 0));
        clock->setText(QApplication::translate("chairs", "TextLabel", 0));
        back->setText(QApplication::translate("chairs", "Back", 0));
        selection->setText(QApplication::translate("chairs", "Select", 0));
    } // retranslateUi

};

namespace Ui {
    class chairs: public Ui_chairs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAIRS_H
