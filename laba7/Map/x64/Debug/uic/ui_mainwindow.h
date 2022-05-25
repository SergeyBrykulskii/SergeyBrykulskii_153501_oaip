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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QListWidget *listMap;
    QLabel *label;
    QLabel *label_2;
    QListWidget *listSet;
    QPushButton *InsertMap;
    QPushButton *InsertSet;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLineEdit *getKeyMap;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QLineEdit *getValueMap;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *RemoveMap;
    QLineEdit *getRemoveMap;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *FindMap;
    QLineEdit *getFindMap;
    QWidget *widget4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLineEdit *getKeySet;
    QWidget *widget5;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *FindSet;
    QLineEdit *getFindSet;
    QWidget *widget6;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *RemoveSet;
    QLineEdit *getRemoveSet;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(812, 745);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        listMap = new QListWidget(centralWidget);
        listMap->setObjectName(QStringLiteral("listMap"));
        listMap->setGeometry(QRect(20, 60, 321, 461));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 71, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(480, 20, 55, 16));
        label_2->setFont(font);
        listSet = new QListWidget(centralWidget);
        listSet->setObjectName(QStringLiteral("listSet"));
        listSet->setGeometry(QRect(470, 60, 311, 461));
        InsertMap = new QPushButton(centralWidget);
        InsertMap->setObjectName(QStringLiteral("InsertMap"));
        InsertMap->setGeometry(QRect(290, 560, 93, 28));
        QFont font1;
        font1.setPointSize(10);
        InsertMap->setFont(font1);
        InsertSet = new QPushButton(centralWidget);
        InsertSet->setObjectName(QStringLiteral("InsertSet"));
        InsertSet->setGeometry(QRect(600, 560, 93, 28));
        InsertSet->setFont(font1);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 530, 111, 61));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        verticalLayout->addWidget(label_3);

        getKeyMap = new QLineEdit(widget);
        getKeyMap->setObjectName(QStringLiteral("getKeyMap"));
        getKeyMap->setFont(font1);

        verticalLayout->addWidget(getKeyMap);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(160, 530, 121, 61));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        verticalLayout_2->addWidget(label_4);

        getValueMap = new QLineEdit(widget1);
        getValueMap->setObjectName(QStringLiteral("getValueMap"));
        getValueMap->setFont(font1);

        verticalLayout_2->addWidget(getValueMap);

        widget2 = new QWidget(centralWidget);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(30, 640, 251, 32));
        horizontalLayout = new QHBoxLayout(widget2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        RemoveMap = new QPushButton(widget2);
        RemoveMap->setObjectName(QStringLiteral("RemoveMap"));
        RemoveMap->setFont(font1);

        horizontalLayout->addWidget(RemoveMap);

        getRemoveMap = new QLineEdit(widget2);
        getRemoveMap->setObjectName(QStringLiteral("getRemoveMap"));

        horizontalLayout->addWidget(getRemoveMap);

        widget3 = new QWidget(centralWidget);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(30, 600, 251, 32));
        horizontalLayout_2 = new QHBoxLayout(widget3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        FindMap = new QPushButton(widget3);
        FindMap->setObjectName(QStringLiteral("FindMap"));
        FindMap->setFont(font1);

        horizontalLayout_2->addWidget(FindMap);

        getFindMap = new QLineEdit(widget3);
        getFindMap->setObjectName(QStringLiteral("getFindMap"));

        horizontalLayout_2->addWidget(getFindMap);

        widget4 = new QWidget(centralWidget);
        widget4->setObjectName(QStringLiteral("widget4"));
        widget4->setGeometry(QRect(480, 530, 101, 61));
        verticalLayout_3 = new QVBoxLayout(widget4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        verticalLayout_3->addWidget(label_5);

        getKeySet = new QLineEdit(widget4);
        getKeySet->setObjectName(QStringLiteral("getKeySet"));
        getKeySet->setFont(font1);

        verticalLayout_3->addWidget(getKeySet);

        widget5 = new QWidget(centralWidget);
        widget5->setObjectName(QStringLiteral("widget5"));
        widget5->setGeometry(QRect(480, 600, 241, 31));
        horizontalLayout_3 = new QHBoxLayout(widget5);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        FindSet = new QPushButton(widget5);
        FindSet->setObjectName(QStringLiteral("FindSet"));
        FindSet->setFont(font1);

        horizontalLayout_3->addWidget(FindSet);

        getFindSet = new QLineEdit(widget5);
        getFindSet->setObjectName(QStringLiteral("getFindSet"));
        getFindSet->setFont(font1);

        horizontalLayout_3->addWidget(getFindSet);

        widget6 = new QWidget(centralWidget);
        widget6->setObjectName(QStringLiteral("widget6"));
        widget6->setGeometry(QRect(480, 640, 241, 31));
        horizontalLayout_4 = new QHBoxLayout(widget6);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        RemoveSet = new QPushButton(widget6);
        RemoveSet->setObjectName(QStringLiteral("RemoveSet"));
        RemoveSet->setFont(font1);

        horizontalLayout_4->addWidget(RemoveSet);

        getRemoveSet = new QLineEdit(widget6);
        getRemoveSet->setObjectName(QStringLiteral("getRemoveSet"));
        getRemoveSet->setFont(font1);

        horizontalLayout_4->addWidget(getRemoveSet);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 812, 26));
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
        label->setText(QApplication::translate("MainWindowClass", "Map:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindowClass", "Set:", Q_NULLPTR));
        InsertMap->setText(QApplication::translate("MainWindowClass", "Insert", Q_NULLPTR));
        InsertSet->setText(QApplication::translate("MainWindowClass", "Insert", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindowClass", "Key:", Q_NULLPTR));
        getKeyMap->setInputMask(QApplication::translate("MainWindowClass", "999", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindowClass", "Value:", Q_NULLPTR));
        getValueMap->setInputMask(QString());
        RemoveMap->setText(QApplication::translate("MainWindowClass", "Remove", Q_NULLPTR));
        getRemoveMap->setInputMask(QApplication::translate("MainWindowClass", "999", Q_NULLPTR));
        FindMap->setText(QApplication::translate("MainWindowClass", "Find", Q_NULLPTR));
        getFindMap->setInputMask(QApplication::translate("MainWindowClass", "999", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindowClass", "Key:", Q_NULLPTR));
        FindSet->setText(QApplication::translate("MainWindowClass", "Find", Q_NULLPTR));
        getFindSet->setInputMask(QApplication::translate("MainWindowClass", "999", Q_NULLPTR));
        RemoveSet->setText(QApplication::translate("MainWindowClass", "Remove", Q_NULLPTR));
        getRemoveSet->setInputMask(QApplication::translate("MainWindowClass", "999", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
