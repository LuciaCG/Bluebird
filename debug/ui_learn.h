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
    QLabel *user;
    QPushButton *logout;
    QLabel *title;
    QLabel *connetion;
    QLabel *clock;
    QTableView *tableView;
    QPushButton *selection;
    QPushButton *back;

    void setupUi(QWidget *learn)
    {
        if (learn->objectName().isEmpty())
            learn->setObjectName(QStringLiteral("learn"));
        learn->resize(1050, 680);
        learn->setLayoutDirection(Qt::LeftToRight);
        learn->setStyleSheet(QStringLiteral("background-color: #f8f8f8;"));
        Body = new QWidget(learn);
        Body->setObjectName(QStringLiteral("Body"));
        Body->setGeometry(QRect(0, 0, 1005, 675));
        Body->setStyleSheet(QStringLiteral("background-color: #f8f8f8;"));
        Header_2 = new QWidget(Body);
        Header_2->setObjectName(QStringLiteral("Header_2"));
        Header_2->setGeometry(QRect(0, 0, 1051, 111));
        Header_2->setStyleSheet(QLatin1String("background-color:#555555;\n"
"color:#000000;"));
        user = new QLabel(Header_2);
        user->setObjectName(QStringLiteral("user"));
        user->setGeometry(QRect(10, 10, 221, 31));
        user->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size:20pt;\n"
"font-weight:bold;"));
        logout = new QPushButton(Header_2);
        logout->setObjectName(QStringLiteral("logout"));
        logout->setGeometry(QRect(870, 0, 101, 40));
        logout->setStyleSheet(QLatin1String("background-color:#808080; color: #FFFFFF;\n"
"font-size: 21px;\n"
"border:3;"));
        title = new QLabel(Header_2);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(310, 0, 401, 101));
        title->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"text-align: center;\n"
"font-size:26pt;\n"
"font-weight:bold;"));
        connetion = new QLabel(Header_2);
        connetion->setObjectName(QStringLiteral("connetion"));
        connetion->setGeometry(QRect(870, 40, 281, 101));
        connetion->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size: 21px;"));
        clock = new QLabel(Header_2);
        clock->setObjectName(QStringLiteral("clock"));
        clock->setGeometry(QRect(10, 80, 171, 31));
        clock->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size: 21px;"));
        tableView = new QTableView(Body);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(170, 150, 601, 341));
        tableView->setStyleSheet(QStringLiteral("QHeaderView::section { background-color:#555555; color:#FFFFFF; font-weight:bold;}"));
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->horizontalHeader()->setHighlightSections(false);
        tableView->verticalHeader()->setVisible(false);
        selection = new QPushButton(Body);
        selection->setObjectName(QStringLiteral("selection"));
        selection->setGeometry(QRect(790, 200, 211, 81));
        back = new QPushButton(Body);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(20, 150, 131, 41));

        retranslateUi(learn);

        QMetaObject::connectSlotsByName(learn);
    } // setupUi

    void retranslateUi(QWidget *learn)
    {
        learn->setWindowTitle(QApplication::translate("learn", "Screenings", 0));
        user->setText(QApplication::translate("learn", "<User Logged in>", 0));
        logout->setText(QApplication::translate("learn", "Logout", 0));
        title->setText(QApplication::translate("learn", "<html><head/><body><p align=\"center\">Movies</p></body></html>", 0));
        connetion->setText(QApplication::translate("learn", "Connection Status", 0));
        clock->setText(QApplication::translate("learn", "TextLabel", 0));
        selection->setText(QApplication::translate("learn", "Select", 0));
        back->setText(QApplication::translate("learn", "Back", 0));
    } // retranslateUi

};

namespace Ui {
    class learn: public Ui_learn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEARN_H
