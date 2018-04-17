/********************************************************************************
** Form generated from reading UI file 'receipts.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIPTS_H
#define UI_RECEIPTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Receipts
{
public:

    void setupUi(QWidget *Receipts)
    {
        if (Receipts->objectName().isEmpty())
            Receipts->setObjectName(QStringLiteral("Receipts"));
        Receipts->resize(400, 300);

        retranslateUi(Receipts);

        QMetaObject::connectSlotsByName(Receipts);
    } // setupUi

    void retranslateUi(QWidget *Receipts)
    {
        Receipts->setWindowTitle(QApplication::translate("Receipts", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Receipts: public Ui_Receipts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIPTS_H
