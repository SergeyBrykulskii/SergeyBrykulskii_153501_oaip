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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *OpenFile;
    QPushButton *ShowInfo;
    QPushButton *AddItem;
    QPushButton *Sort;
    QPushButton *Exit;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBoxFirm;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEditModel;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEditPrice;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *radioButtonStock;
    QRadioButton *radioButtonNStock;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(838, 668);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(420, 10, 411, 351));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(420, 370, 241, 191));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        OpenFile = new QPushButton(verticalLayoutWidget);
        OpenFile->setObjectName(QStringLiteral("OpenFile"));
        QFont font;
        font.setPointSize(10);
        OpenFile->setFont(font);

        verticalLayout->addWidget(OpenFile);

        ShowInfo = new QPushButton(verticalLayoutWidget);
        ShowInfo->setObjectName(QStringLiteral("ShowInfo"));
        ShowInfo->setFont(font);

        verticalLayout->addWidget(ShowInfo);

        AddItem = new QPushButton(verticalLayoutWidget);
        AddItem->setObjectName(QStringLiteral("AddItem"));
        AddItem->setFont(font);

        verticalLayout->addWidget(AddItem);

        Sort = new QPushButton(verticalLayoutWidget);
        Sort->setObjectName(QStringLiteral("Sort"));
        Sort->setFont(font);

        verticalLayout->addWidget(Sort);

        Exit = new QPushButton(verticalLayoutWidget);
        Exit->setObjectName(QStringLiteral("Exit"));
        Exit->setFont(font);

        verticalLayout->addWidget(Exit);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(26, 9, 371, 341));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        comboBoxFirm = new QComboBox(widget);
        comboBoxFirm->setObjectName(QStringLiteral("comboBoxFirm"));
        comboBoxFirm->setFont(font);

        horizontalLayout->addWidget(comboBoxFirm);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        horizontalLayout_3->addWidget(label_2);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setFont(font);

        horizontalLayout_3->addWidget(comboBox);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        horizontalLayout_2->addWidget(label_3);

        lineEditModel = new QLineEdit(widget);
        lineEditModel->setObjectName(QStringLiteral("lineEditModel"));

        horizontalLayout_2->addWidget(lineEditModel);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        horizontalLayout_4->addWidget(label_4);

        lineEditPrice = new QLineEdit(widget);
        lineEditPrice->setObjectName(QStringLiteral("lineEditPrice"));

        horizontalLayout_4->addWidget(lineEditPrice);


        verticalLayout_2->addLayout(horizontalLayout_4);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(30, 360, 361, 60));
        verticalLayout_3 = new QVBoxLayout(widget1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        verticalLayout_3->addWidget(label_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        radioButtonStock = new QRadioButton(widget1);
        radioButtonStock->setObjectName(QStringLiteral("radioButtonStock"));
        radioButtonStock->setFont(font);

        horizontalLayout_6->addWidget(radioButtonStock);

        radioButtonNStock = new QRadioButton(widget1);
        radioButtonNStock->setObjectName(QStringLiteral("radioButtonNStock"));
        radioButtonNStock->setFont(font);

        horizontalLayout_6->addWidget(radioButtonNStock);


        verticalLayout_3->addLayout(horizontalLayout_6);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 838, 26));
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
        OpenFile->setText(QApplication::translate("MainWindowClass", "Open file", Q_NULLPTR));
        ShowInfo->setText(QApplication::translate("MainWindowClass", "Show", Q_NULLPTR));
        AddItem->setText(QApplication::translate("MainWindowClass", "Add", Q_NULLPTR));
        Sort->setText(QApplication::translate("MainWindowClass", "Sort", Q_NULLPTR));
        Exit->setText(QApplication::translate("MainWindowClass", "Exit", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindowClass", "Firm:", Q_NULLPTR));
        comboBoxFirm->clear();
        comboBoxFirm->insertItems(0, QStringList()
         << QApplication::translate("MainWindowClass", "Intel", Q_NULLPTR)
         << QApplication::translate("MainWindowClass", "HP", Q_NULLPTR)
         << QApplication::translate("MainWindowClass", "MSI", Q_NULLPTR)
         << QApplication::translate("MainWindowClass", "ASUS", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("MainWindowClass", "Product type:", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindowClass", "Processor", Q_NULLPTR)
         << QApplication::translate("MainWindowClass", "Motherboard", Q_NULLPTR)
         << QApplication::translate("MainWindowClass", "Video card", Q_NULLPTR)
         << QApplication::translate("MainWindowClass", "Random Access Memory", Q_NULLPTR)
         << QApplication::translate("MainWindowClass", "Disk drive", Q_NULLPTR)
         << QApplication::translate("MainWindowClass", "Case", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("MainWindowClass", "Product model:    ", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindowClass", "Price:                  ", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindowClass", "Stock availability:", Q_NULLPTR));
        radioButtonStock->setText(QApplication::translate("MainWindowClass", "there's in stock", Q_NULLPTR));
        radioButtonNStock->setText(QApplication::translate("MainWindowClass", "there's not in stock", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
