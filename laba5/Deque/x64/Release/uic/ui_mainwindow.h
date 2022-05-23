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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QListWidget *listWidget;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *push_back;
    QLineEdit *toBack;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *push_front;
    QLineEdit *toFront;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pop_back;
    QPushButton *pop_front;
    QPushButton *Size;
    QPushButton *Clear;
    QPushButton *Empty;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *getElem;
    QLineEdit *numOfEl;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(647, 644);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(20, 10, 241, 491));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(420, 170, 131, 16));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(310, 30, 273, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        push_back = new QPushButton(layoutWidget);
        push_back->setObjectName(QStringLiteral("push_back"));
        QFont font1;
        font1.setPointSize(10);
        push_back->setFont(font1);

        horizontalLayout->addWidget(push_back);

        toBack = new QLineEdit(layoutWidget);
        toBack->setObjectName(QStringLiteral("toBack"));
        toBack->setFont(font1);

        horizontalLayout->addWidget(toBack);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(310, 70, 271, 32));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        push_front = new QPushButton(layoutWidget1);
        push_front->setObjectName(QStringLiteral("push_front"));
        push_front->setFont(font1);

        horizontalLayout_2->addWidget(push_front);

        toFront = new QLineEdit(layoutWidget1);
        toFront->setObjectName(QStringLiteral("toFront"));
        toFront->setFont(font1);

        horizontalLayout_2->addWidget(toFront);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(310, 110, 271, 32));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pop_back = new QPushButton(layoutWidget2);
        pop_back->setObjectName(QStringLiteral("pop_back"));
        pop_back->setFont(font1);

        horizontalLayout_3->addWidget(pop_back);

        pop_front = new QPushButton(layoutWidget2);
        pop_front->setObjectName(QStringLiteral("pop_front"));
        pop_front->setFont(font1);

        horizontalLayout_3->addWidget(pop_front);

        Size = new QPushButton(centralWidget);
        Size->setObjectName(QStringLiteral("Size"));
        Size->setGeometry(QRect(310, 230, 93, 28));
        Size->setFont(font1);
        Clear = new QPushButton(centralWidget);
        Clear->setObjectName(QStringLiteral("Clear"));
        Clear->setGeometry(QRect(310, 290, 93, 28));
        Clear->setFont(font1);
        Empty = new QPushButton(centralWidget);
        Empty->setObjectName(QStringLiteral("Empty"));
        Empty->setGeometry(QRect(310, 260, 93, 28));
        Empty->setFont(font1);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(310, 190, 261, 31));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        getElem = new QPushButton(widget);
        getElem->setObjectName(QStringLiteral("getElem"));
        getElem->setFont(font1);

        horizontalLayout_4->addWidget(getElem);

        numOfEl = new QLineEdit(widget);
        numOfEl->setObjectName(QStringLiteral("numOfEl"));
        numOfEl->setFont(font1);

        horizontalLayout_4->addWidget(numOfEl);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 647, 26));
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
        label->setText(QApplication::translate("MainWindowClass", "Number of element:", Q_NULLPTR));
        push_back->setText(QApplication::translate("MainWindowClass", "Push_back", Q_NULLPTR));
        toBack->setInputMask(QApplication::translate("MainWindowClass", "9999", Q_NULLPTR));
        push_front->setText(QApplication::translate("MainWindowClass", "Push_front", Q_NULLPTR));
        toFront->setInputMask(QApplication::translate("MainWindowClass", "9999", Q_NULLPTR));
        pop_back->setText(QApplication::translate("MainWindowClass", "Pop_back", Q_NULLPTR));
        pop_front->setText(QApplication::translate("MainWindowClass", "Pop_front", Q_NULLPTR));
        Size->setText(QApplication::translate("MainWindowClass", "Get size", Q_NULLPTR));
        Clear->setText(QApplication::translate("MainWindowClass", "Clear", Q_NULLPTR));
        Empty->setText(QApplication::translate("MainWindowClass", "Is empty", Q_NULLPTR));
        getElem->setText(QApplication::translate("MainWindowClass", "Get element", Q_NULLPTR));
        numOfEl->setInputMask(QApplication::translate("MainWindowClass", "9999", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
