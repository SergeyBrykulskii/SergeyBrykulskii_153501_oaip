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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *File;
    QPushButton *Checker;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(800, 600);
        MainWindowClass->setMinimumSize(QSize(800, 600));
        MainWindowClass->setMaximumSize(QSize(800, 600));
        MainWindowClass->setStyleSheet(QLatin1String("colour:  rgb(0, 255, 0);\n"
"background-color: rgb(29, 29, 29);"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 30, 451, 501));
        textEdit->setStyleSheet(QLatin1String("background-color: rgb(11, 11, 11);\n"
"color: rgb(0, 255, 0);\n"
"border-color: rgb(0, 255, 0);"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(490, 40, 281, 81));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        File = new QPushButton(layoutWidget);
        File->setObjectName(QStringLiteral("File"));
        QFont font;
        font.setPointSize(11);
        File->setFont(font);
        File->setStyleSheet(QLatin1String("border-color: rgba(0, 255, 0, 200);\n"
"background-color: rgb(8, 8, 8);\n"
"color: rgb(0, 255, 0);"));

        verticalLayout->addWidget(File);

        Checker = new QPushButton(layoutWidget);
        Checker->setObjectName(QStringLiteral("Checker"));
        Checker->setFont(font);
        Checker->setStyleSheet(QLatin1String("border-color: rgb(0, 255, 0);\n"
"background-color: rgb(9, 9, 9);\n"
"color: rgb(0, 255, 0);"));

        verticalLayout->addWidget(Checker);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 26));
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
        File->setText(QApplication::translate("MainWindowClass", "Choose file", Q_NULLPTR));
        Checker->setText(QApplication::translate("MainWindowClass", "Check bracket sequemces", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
