/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QListWidget *listWidget;
    QPushButton *Add;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Find;
    QLineEdit *getFind;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Remove;
    QLineEdit *getRemove;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(480, 710);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(20, 10, 431, 461));
        Add = new QPushButton(centralWidget);
        Add->setObjectName(QStringLiteral("Add"));
        Add->setGeometry(QRect(20, 500, 431, 31));
        QFont font;
        font.setPointSize(10);
        Add->setFont(font);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 550, 273, 32));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Find = new QPushButton(widget);
        Find->setObjectName(QStringLiteral("Find"));
        Find->setFont(font);

        horizontalLayout->addWidget(Find);

        getFind = new QLineEdit(widget);
        getFind->setObjectName(QStringLiteral("getFind"));
        getFind->setFont(font);

        horizontalLayout->addWidget(getFind);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(30, 590, 273, 32));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Remove = new QPushButton(widget1);
        Remove->setObjectName(QStringLiteral("Remove"));
        Remove->setFont(font);

        horizontalLayout_2->addWidget(Remove);

        getRemove = new QLineEdit(widget1);
        getRemove->setObjectName(QStringLiteral("getRemove"));
        getRemove->setFont(font);

        horizontalLayout_2->addWidget(getRemove);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 480, 26));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", Q_NULLPTR));
        Add->setText(QApplication::translate("MainWindowClass", "Add", Q_NULLPTR));
        Find->setText(QApplication::translate("MainWindowClass", "Find", Q_NULLPTR));
        getFind->setInputMask(QApplication::translate("MainWindowClass", "999", Q_NULLPTR));
        Remove->setText(QApplication::translate("MainWindowClass", "Remove", Q_NULLPTR));
        getRemove->setInputMask(QApplication::translate("MainWindowClass", "999", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
