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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QTreeWidget *Tree;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Add;
    QLineEdit *lineEditAdd;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Delete;
    QLineEdit *lineEditDelete;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Find;
    QLineEdit *lineEditFind;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *Calculate;
    QLineEdit *idTask;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(822, 629);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Tree = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        Tree->setHeaderItem(__qtreewidgetitem);
        Tree->setObjectName(QStringLiteral("Tree"));
        Tree->setGeometry(QRect(20, 10, 791, 391));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 410, 341, 32));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Add = new QPushButton(widget);
        Add->setObjectName(QStringLiteral("Add"));
        QFont font;
        font.setPointSize(10);
        Add->setFont(font);

        horizontalLayout->addWidget(Add);

        lineEditAdd = new QLineEdit(widget);
        lineEditAdd->setObjectName(QStringLiteral("lineEditAdd"));
        lineEditAdd->setFont(font);

        horizontalLayout->addWidget(lineEditAdd);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(30, 450, 341, 32));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Delete = new QPushButton(widget1);
        Delete->setObjectName(QStringLiteral("Delete"));
        Delete->setFont(font);

        horizontalLayout_2->addWidget(Delete);

        lineEditDelete = new QLineEdit(widget1);
        lineEditDelete->setObjectName(QStringLiteral("lineEditDelete"));
        lineEditDelete->setFont(font);

        horizontalLayout_2->addWidget(lineEditDelete);

        widget2 = new QWidget(centralWidget);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(30, 490, 341, 31));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        Find = new QPushButton(widget2);
        Find->setObjectName(QStringLiteral("Find"));
        Find->setFont(font);

        horizontalLayout_3->addWidget(Find);

        lineEditFind = new QLineEdit(widget2);
        lineEditFind->setObjectName(QStringLiteral("lineEditFind"));
        lineEditFind->setFont(font);

        horizontalLayout_3->addWidget(lineEditFind);

        widget3 = new QWidget(centralWidget);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(30, 530, 781, 32));
        horizontalLayout_4 = new QHBoxLayout(widget3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        Calculate = new QPushButton(widget3);
        Calculate->setObjectName(QStringLiteral("Calculate"));
        Calculate->setFont(font);

        horizontalLayout_4->addWidget(Calculate);

        idTask = new QLineEdit(widget3);
        idTask->setObjectName(QStringLiteral("idTask"));
        idTask->setFont(font);
        idTask->setReadOnly(true);

        horizontalLayout_4->addWidget(idTask);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 822, 26));
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
        Add->setText(QApplication::translate("MainWindowClass", "Add element", Q_NULLPTR));
        Delete->setText(QApplication::translate("MainWindowClass", "Delete", Q_NULLPTR));
        Find->setText(QApplication::translate("MainWindowClass", "Find", Q_NULLPTR));
        Calculate->setText(QApplication::translate("MainWindowClass", "Calculate", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
