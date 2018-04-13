/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableView *tableView;
    QWidget *Header;
    QLabel *user;
    QPushButton *logout;
    QLabel *title;
    QLabel *connection;
    QLabel *clock;
    QPushButton *select;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1005, 655);
        MainWindow->setWindowOpacity(1);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QStringLiteral("background-color: #f8f8f8;"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(160, 160, 611, 501));
        tableView->setMinimumSize(QSize(611, 501));
        tableView->setAutoFillBackground(false);
        tableView->setStyleSheet(QStringLiteral("QHeaderView::section { background-color:#555555; color:#FFFFFF; font-weight:bold;}"));
        tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->horizontalHeader()->setDefaultSectionSize(100);
        tableView->horizontalHeader()->setHighlightSections(false);
        tableView->horizontalHeader()->setMinimumSectionSize(50);
        tableView->horizontalHeader()->setStretchLastSection(false);
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setStretchLastSection(false);
        Header = new QWidget(centralWidget);
        Header->setObjectName(QStringLiteral("Header"));
        Header->setGeometry(QRect(0, 0, 1021, 111));
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
        logout->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size: 21px;\n"
"border:0;"));
        title = new QLabel(Header);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(310, 10, 401, 101));
        title->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"text-align: center;\n"
"font-size:26pt;\n"
"font-weight:bold;"));
        connection = new QLabel(Header);
        connection->setObjectName(QStringLiteral("connection"));
        connection->setGeometry(QRect(870, 40, 281, 101));
        connection->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size: 21px;"));
        clock = new QLabel(Header);
        clock->setObjectName(QStringLiteral("clock"));
        clock->setGeometry(QRect(10, 80, 171, 31));
        clock->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size: 21px;"));
        select = new QPushButton(centralWidget);
        select->setObjectName(QStringLiteral("select"));
        select->setGeometry(QRect(790, 180, 211, 81));
        MainWindow->setCentralWidget(centralWidget);
        select->raise();
        Header->raise();
        tableView->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Movies", 0));
        user->setText(QApplication::translate("MainWindow", "<User Logged in>", 0));
        logout->setText(QApplication::translate("MainWindow", "Logout", 0));
        title->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Movies Screening</p></body></html>", 0));
        connection->setText(QApplication::translate("MainWindow", "Connection Status", 0));
        clock->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        select->setText(QApplication::translate("MainWindow", "Select", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
