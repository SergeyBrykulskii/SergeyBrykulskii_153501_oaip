/********************************************************************************
** Form generated from reading UI file 'mainwidow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDOW_H
#define UI_MAINWIDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidowClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWidowClass)
    {
        if (MainWidowClass->objectName().isEmpty())
            MainWidowClass->setObjectName(QStringLiteral("MainWidowClass"));
        MainWidowClass->resize(600, 400);
        menuBar = new QMenuBar(MainWidowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        MainWidowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWidowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWidowClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MainWidowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWidowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWidowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWidowClass->setStatusBar(statusBar);

        retranslateUi(MainWidowClass);

        QMetaObject::connectSlotsByName(MainWidowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWidowClass)
    {
        MainWidowClass->setWindowTitle(QApplication::translate("MainWidowClass", "MainWidow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWidowClass: public Ui_MainWidowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDOW_H
