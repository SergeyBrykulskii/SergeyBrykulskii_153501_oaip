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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *Expression;
    QLineEdit *AValue;
    QLineEdit *BValue;
    QLineEdit *CValue;
    QLineEdit *DValue;
    QLineEdit *EValue;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Add;
    QPushButton *Calculate;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(1150, 750);
        MainWindowClass->setMinimumSize(QSize(1150, 750));
        MainWindowClass->setMaximumSize(QSize(1150, 750));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        QFont font;
        font.setPointSize(11);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font);
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 0, 1051, 621));
        QFont font1;
        font1.setPointSize(10);
        tableWidget->setFont(font1);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 630, 781, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Expression = new QLineEdit(layoutWidget);
        Expression->setObjectName(QStringLiteral("Expression"));

        horizontalLayout->addWidget(Expression);

        AValue = new QLineEdit(layoutWidget);
        AValue->setObjectName(QStringLiteral("AValue"));

        horizontalLayout->addWidget(AValue);

        BValue = new QLineEdit(layoutWidget);
        BValue->setObjectName(QStringLiteral("BValue"));

        horizontalLayout->addWidget(BValue);

        CValue = new QLineEdit(layoutWidget);
        CValue->setObjectName(QStringLiteral("CValue"));

        horizontalLayout->addWidget(CValue);

        DValue = new QLineEdit(layoutWidget);
        DValue->setObjectName(QStringLiteral("DValue"));

        horizontalLayout->addWidget(DValue);

        EValue = new QLineEdit(layoutWidget);
        EValue->setObjectName(QStringLiteral("EValue"));

        horizontalLayout->addWidget(EValue);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(820, 630, 241, 33));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Add = new QPushButton(layoutWidget1);
        Add->setObjectName(QStringLiteral("Add"));
        Add->setFont(font);

        horizontalLayout_2->addWidget(Add);

        Calculate = new QPushButton(layoutWidget1);
        Calculate->setObjectName(QStringLiteral("Calculate"));
        Calculate->setFont(font);

        horizontalLayout_2->addWidget(Calculate);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 660, 151, 31));
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1150, 26));
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
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindowClass", "               Expression           ", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindowClass", "a", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindowClass", "b", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindowClass", "c", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindowClass", "d", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindowClass", "e", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindowClass", "Expression", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindowClass", "Result", Q_NULLPTR));
        AValue->setInputMask(QApplication::translate("MainWindowClass", "9999.999", Q_NULLPTR));
        BValue->setInputMask(QApplication::translate("MainWindowClass", "9999.999", Q_NULLPTR));
        CValue->setInputMask(QApplication::translate("MainWindowClass", "9999.999", Q_NULLPTR));
        DValue->setInputMask(QApplication::translate("MainWindowClass", "9999.999", Q_NULLPTR));
        EValue->setInputMask(QApplication::translate("MainWindowClass", "9999.999", Q_NULLPTR));
        Add->setText(QApplication::translate("MainWindowClass", "Add", Q_NULLPTR));
        Calculate->setText(QApplication::translate("MainWindowClass", "Calculate", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
