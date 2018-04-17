/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *Body;
    QLabel *title_pwd;
    QLineEdit *Password;
    QPushButton *login;
    QLabel *warning;
    QLineEdit *Username;
    QLabel *title_user;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(1005, 680);
        Login->setFocusPolicy(Qt::StrongFocus);
        Login->setStyleSheet(QStringLiteral("background-color: #f8f8f8;"));
        Body = new QWidget(Login);
        Body->setObjectName(QStringLiteral("Body"));
        Body->setGeometry(QRect(-20, -10, 1291, 691));
        Body->setStyleSheet(QStringLiteral("background-color: #f8f8f8;"));
        title_pwd = new QLabel(Body);
        title_pwd->setObjectName(QStringLiteral("title_pwd"));
        title_pwd->setGeometry(QRect(310, 260, 531, 20));
        title_pwd->setStyleSheet(QStringLiteral("font-weight: bold;"));
        title_pwd->setTextInteractionFlags(Qt::NoTextInteraction);
        Password = new QLineEdit(Body);
        Password->setObjectName(QStringLiteral("Password"));
        Password->setGeometry(QRect(310, 290, 451, 41));
        Password->setEchoMode(QLineEdit::Password);
        login = new QPushButton(Body);
        login->setObjectName(QStringLiteral("login"));
        login->setGeometry(QRect(470, 350, 111, 51));
        warning = new QLabel(Body);
        warning->setObjectName(QStringLiteral("warning"));
        warning->setGeometry(QRect(320, 440, 531, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        warning->setFont(font);
        warning->setStyleSheet(QStringLiteral("font-weight: bold;"));
        warning->setTextInteractionFlags(Qt::NoTextInteraction);
        Username = new QLineEdit(Body);
        Username->setObjectName(QStringLiteral("Username"));
        Username->setGeometry(QRect(310, 210, 451, 41));
        title_user = new QLabel(Body);
        title_user->setObjectName(QStringLiteral("title_user"));
        title_user->setGeometry(QRect(310, 180, 531, 20));
        title_user->setStyleSheet(QStringLiteral("font-weight: bold;"));
        title_user->setTextInteractionFlags(Qt::NoTextInteraction);

        retranslateUi(Login);

        login->setDefault(true);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Log In - Till", 0));
        title_pwd->setText(QApplication::translate("Login", "Password", 0));
        login->setText(QApplication::translate("Login", "Log in", 0));
        warning->setText(QString());
        title_user->setText(QApplication::translate("Login", "User", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
