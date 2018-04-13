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
    QLineEdit *Username;
    QLineEdit *Password;
    QPushButton *Login_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(1006, 706);
        Username = new QLineEdit(Login);
        Username->setObjectName(QStringLiteral("Username"));
        Username->setGeometry(QRect(240, 140, 451, 41));
        Password = new QLineEdit(Login);
        Password->setObjectName(QStringLiteral("Password"));
        Password->setGeometry(QRect(240, 210, 451, 41));
        Login_2 = new QPushButton(Login);
        Login_2->setObjectName(QStringLiteral("Login_2"));
        Login_2->setGeometry(QRect(420, 280, 91, 28));
        label_3 = new QLabel(Login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(270, 380, 531, 20));
        label_4 = new QLabel(Login);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(240, 110, 531, 20));
        label_5 = new QLabel(Login);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(240, 190, 531, 20));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", 0));
        Login_2->setText(QApplication::translate("Login", "PushButton", 0));
        label_3->setText(QApplication::translate("Login", "TextLabel", 0));
        label_4->setText(QApplication::translate("Login", "TextLabel", 0));
        label_5->setText(QApplication::translate("Login", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
