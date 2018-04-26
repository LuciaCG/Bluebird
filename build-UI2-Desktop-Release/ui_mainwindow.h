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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *Header;
    QLabel *user;
    QPushButton *logout;
    QLabel *title;
    QLabel *connection;
    QLabel *clock;
    QPushButton *select;
    QTableWidget *tableWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1005, 697);
        MainWindow->setFocusPolicy(Qt::StrongFocus);
        MainWindow->setWindowOpacity(1);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QStringLiteral("background-color: #f8f8f8;"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
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
        logout->setGeometry(QRect(890, 10, 101, 40));
        logout->setFocusPolicy(Qt::StrongFocus);
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
        connection = new QLabel(Header);
        connection->setObjectName(QStringLiteral("connection"));
        connection->setGeometry(QRect(830, 50, 341, 71));
        connection->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size: 21px;"));
        clock = new QLabel(Header);
        clock->setObjectName(QStringLiteral("clock"));
        clock->setGeometry(QRect(10, 80, 171, 31));
        clock->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size: 21px;"));
        select = new QPushButton(centralWidget);
        select->setObjectName(QStringLiteral("select"));
        select->setGeometry(QRect(780, 180, 211, 81));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(135, 141, 621, 511));
        tableWidget->setStyleSheet(QStringLiteral("QHeaderView::section { background-color:#555555; color:#FFFFFF; font-weight:bold;}"));
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setTabKeyNavigation(false);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->verticalHeader()->setVisible(false);
        MainWindow->setCentralWidget(centralWidget);
        select->raise();
        Header->raise();
        tableWidget->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Movies - Till", 0));
        user->setText(QApplication::translate("MainWindow", "<User Logged in>", 0));
        logout->setText(QApplication::translate("MainWindow", "Logout", 0));
        title->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Movies</p></body></html>", 0));
        connection->setText(QString());
        clock->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        select->setText(QApplication::translate("MainWindow", "Select", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
