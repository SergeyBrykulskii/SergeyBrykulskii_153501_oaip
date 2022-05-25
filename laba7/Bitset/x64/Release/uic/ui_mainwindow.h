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
    QLineEdit *bitset;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *All;
    QPushButton *Any;
    QPushButton *None;
    QPushButton *Size;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *getPos;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Flip;
    QPushButton *Set;
    QPushButton *Reset;
    QPushButton *Test;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *get;
    QPushButton *Make;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(880, 396);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        bitset = new QLineEdit(centralWidget);
        bitset->setObjectName(QStringLiteral("bitset"));
        bitset->setGeometry(QRect(60, 20, 761, 31));
        QFont font;
        font.setPointSize(12);
        bitset->setFont(font);
        bitset->setReadOnly(true);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 160, 781, 32));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        All = new QPushButton(widget);
        All->setObjectName(QStringLiteral("All"));
        QFont font1;
        font1.setPointSize(10);
        All->setFont(font1);

        horizontalLayout->addWidget(All);

        Any = new QPushButton(widget);
        Any->setObjectName(QStringLiteral("Any"));
        Any->setFont(font1);

        horizontalLayout->addWidget(Any);

        None = new QPushButton(widget);
        None->setObjectName(QStringLiteral("None"));
        None->setFont(font1);

        horizontalLayout->addWidget(None);

        Size = new QPushButton(widget);
        Size->setObjectName(QStringLiteral("Size"));
        Size->setFont(font1);

        horizontalLayout->addWidget(Size);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(50, 230, 781, 29));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        getPos = new QLineEdit(widget1);
        getPos->setObjectName(QStringLiteral("getPos"));
        getPos->setFont(font1);

        horizontalLayout_2->addWidget(getPos);

        widget2 = new QWidget(centralWidget);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(140, 280, 691, 32));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        Flip = new QPushButton(widget2);
        Flip->setObjectName(QStringLiteral("Flip"));
        Flip->setFont(font1);

        horizontalLayout_3->addWidget(Flip);

        Set = new QPushButton(widget2);
        Set->setObjectName(QStringLiteral("Set"));
        Set->setFont(font1);

        horizontalLayout_3->addWidget(Set);

        Reset = new QPushButton(widget2);
        Reset->setObjectName(QStringLiteral("Reset"));
        Reset->setFont(font1);

        horizontalLayout_3->addWidget(Reset);

        Test = new QPushButton(widget2);
        Test->setObjectName(QStringLiteral("Test"));
        Test->setFont(font1);

        horizontalLayout_3->addWidget(Test);

        widget3 = new QWidget(centralWidget);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(50, 90, 273, 32));
        horizontalLayout_4 = new QHBoxLayout(widget3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        get = new QLineEdit(widget3);
        get->setObjectName(QStringLiteral("get"));
        get->setFont(font1);

        horizontalLayout_4->addWidget(get);

        Make = new QPushButton(widget3);
        Make->setObjectName(QStringLiteral("Make"));
        Make->setFont(font1);

        horizontalLayout_4->addWidget(Make);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 880, 26));
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
        All->setText(QApplication::translate("MainWindowClass", "All", Q_NULLPTR));
        Any->setText(QApplication::translate("MainWindowClass", "Any", Q_NULLPTR));
        None->setText(QApplication::translate("MainWindowClass", "None", Q_NULLPTR));
        Size->setText(QApplication::translate("MainWindowClass", "Size", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindowClass", "Position:", Q_NULLPTR));
        Flip->setText(QApplication::translate("MainWindowClass", "Flip", Q_NULLPTR));
        Set->setText(QApplication::translate("MainWindowClass", "Set", Q_NULLPTR));
        Reset->setText(QApplication::translate("MainWindowClass", "Reset", Q_NULLPTR));
        Test->setText(QApplication::translate("MainWindowClass", "Test", Q_NULLPTR));
        get->setInputMask(QApplication::translate("MainWindowClass", "99999", Q_NULLPTR));
        Make->setText(QApplication::translate("MainWindowClass", "Make", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
