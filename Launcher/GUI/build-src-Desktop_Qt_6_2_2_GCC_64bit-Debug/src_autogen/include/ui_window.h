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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window
{
public:
    QWidget *TopBar;
    QLineEdit *lineEdit;
    QWidget *SideBar;
    QPushButton *MyAppsButton;
    QScrollArea *ApplicationScroller;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *window)
    {
        if (window->objectName().isEmpty())
            window->setObjectName(QString::fromUtf8("window"));
        window->resize(681, 665);
        window->setStyleSheet(QString::fromUtf8("background-color: rgb(119, 118, 123);"));
        TopBar = new QWidget(window);
        TopBar->setObjectName(QString::fromUtf8("TopBar"));
        TopBar->setGeometry(QRect(0, 0, 681, 51));
        TopBar->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 31, 49);"));
        lineEdit = new QLineEdit(TopBar);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(190, 10, 391, 26));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        SideBar = new QWidget(window);
        SideBar->setObjectName(QString::fromUtf8("SideBar"));
        SideBar->setGeometry(QRect(0, 50, 191, 621));
        SideBar->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 31, 49);"));
        MyAppsButton = new QPushButton(SideBar);
        MyAppsButton->setObjectName(QString::fromUtf8("MyAppsButton"));
        MyAppsButton->setEnabled(true);
        MyAppsButton->setGeometry(QRect(0, 70, 191, 51));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(23, 18, 18, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        MyAppsButton->setPalette(palette);
        MyAppsButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 11pt \"DejaVu Sans\";\n"
"background-color: rgb(23, 18, 18);\n"
"border-color: rgb(23, 18, 18);"));
        ApplicationScroller = new QScrollArea(window);
        ApplicationScroller->setObjectName(QString::fromUtf8("ApplicationScroller"));
        ApplicationScroller->setGeometry(QRect(190, 50, 391, 621));
        ApplicationScroller->setStyleSheet(QString::fromUtf8("background-color: rgb(94, 92, 100);"));
        ApplicationScroller->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 389, 619));
        ApplicationScroller->setWidget(scrollAreaWidgetContents);

        retranslateUi(window);

        QMetaObject::connectSlotsByName(window);
    } // setupUi

    void retranslateUi(QWidget *window)
    {
        window->setWindowTitle(QCoreApplication::translate("window", "window", nullptr));
        MyAppsButton->setText(QCoreApplication::translate("window", "My Applications", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window: public Ui_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
