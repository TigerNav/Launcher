/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window
{
public:

    void setupUi(QWidget *window)
    {
        if (window->objectName().isEmpty())
            window->setObjectName(QString::fromUtf8("window"));
        window->resize(455, 600);

        retranslateUi(window);

        QMetaObject::connectSlotsByName(window);
    } // setupUi

    void retranslateUi(QWidget *window)
    {
        window->setWindowTitle(QCoreApplication::translate("window", "window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window: public Ui_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
