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
    QLabel *lblTitle;
    QPushButton *btnHome;
    QLabel *lblTitle_2;
    QLabel *label;
    QLabel *clock;
    QWidget *Header_2;
    QLabel *lblTitle_3;
    QPushButton *btnHome_2;
    QLabel *lblTitle_4;
    QLabel *label_2;
    QLabel *clock_2;
    QPushButton *BlackPanther_2;
    QPushButton *BlackPanther;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1019, 719);
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
        lblTitle = new QLabel(Header);
        lblTitle->setObjectName(QStringLiteral("lblTitle"));
        lblTitle->setGeometry(QRect(10, 10, 221, 31));
        lblTitle->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size:20pt;\n"
"font-weight:bold;"));
        btnHome = new QPushButton(Header);
        btnHome->setObjectName(QStringLiteral("btnHome"));
        btnHome->setGeometry(QRect(870, 0, 101, 40));
        btnHome->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size: 21px;\n"
"border:0;"));
        lblTitle_2 = new QLabel(Header);
        lblTitle_2->setObjectName(QStringLiteral("lblTitle_2"));
        lblTitle_2->setGeometry(QRect(310, 10, 401, 101));
        lblTitle_2->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"text-align: center;\n"
"font-size:26pt;\n"
"font-weight:bold;"));
        label = new QLabel(Header);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(870, 40, 281, 101));
        label->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size: 21px;"));
        clock = new QLabel(Header);
        clock->setObjectName(QStringLiteral("clock"));
        clock->setGeometry(QRect(10, 80, 171, 31));
        clock->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size: 21px;"));
        Header_2 = new QWidget(Header);
        Header_2->setObjectName(QStringLiteral("Header_2"));
        Header_2->setGeometry(QRect(0, 0, 1021, 111));
        Header_2->setStyleSheet(QLatin1String("background-color:#555555;\n"
"color:#000000;"));
        lblTitle_3 = new QLabel(Header_2);
        lblTitle_3->setObjectName(QStringLiteral("lblTitle_3"));
        lblTitle_3->setGeometry(QRect(10, 10, 221, 31));
        lblTitle_3->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size:20pt;\n"
"font-weight:bold;"));
        btnHome_2 = new QPushButton(Header_2);
        btnHome_2->setObjectName(QStringLiteral("btnHome_2"));
        btnHome_2->setGeometry(QRect(870, 0, 101, 40));
        btnHome_2->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size: 21px;\n"
"border:0;"));
        lblTitle_4 = new QLabel(Header_2);
        lblTitle_4->setObjectName(QStringLiteral("lblTitle_4"));
        lblTitle_4->setGeometry(QRect(310, 10, 401, 101));
        lblTitle_4->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"text-align: center;\n"
"font-size:26pt;\n"
"font-weight:bold;"));
        label_2 = new QLabel(Header_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(870, 40, 281, 101));
        label_2->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size: 21px;"));
        clock_2 = new QLabel(Header_2);
        clock_2->setObjectName(QStringLiteral("clock_2"));
        clock_2->setGeometry(QRect(10, 80, 171, 31));
        clock_2->setStyleSheet(QLatin1String("color: #FFFFFF;\n"
"font-size: 21px;"));
        BlackPanther_2 = new QPushButton(Header);
        BlackPanther_2->setObjectName(QStringLiteral("BlackPanther_2"));
        BlackPanther_2->setGeometry(QRect(780, 180, 211, 81));
        lblTitle->raise();
        btnHome->raise();
        lblTitle_2->raise();
        label->raise();
        clock->raise();
        BlackPanther_2->raise();
        Header_2->raise();
        BlackPanther = new QPushButton(centralWidget);
        BlackPanther->setObjectName(QStringLiteral("BlackPanther"));
        BlackPanther->setGeometry(QRect(780, 200, 211, 81));
        MainWindow->setCentralWidget(centralWidget);
        BlackPanther->raise();
        Header->raise();
        tableView->raise();
        lblTitle_4->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        lblTitle->setText(QApplication::translate("MainWindow", "<User Logged in>", 0));
        btnHome->setText(QApplication::translate("MainWindow", "Logout", 0));
        lblTitle_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Movies Screening</p></body></html>", 0));
        label->setText(QApplication::translate("MainWindow", "Connection Status", 0));
        clock->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        lblTitle_3->setText(QApplication::translate("MainWindow", "<User Logged in>", 0));
        btnHome_2->setText(QApplication::translate("MainWindow", "Logout", 0));
        lblTitle_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Movies Screening</p></body></html>", 0));
        label_2->setText(QApplication::translate("MainWindow", "Connection Status", 0));
        clock_2->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        BlackPanther_2->setText(QApplication::translate("MainWindow", "Select", 0));
        BlackPanther->setText(QApplication::translate("MainWindow", "Select", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
