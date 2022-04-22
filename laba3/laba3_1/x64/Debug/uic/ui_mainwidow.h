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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidowClass
{
public:
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *flightNumber;
    QLineEdit *lineEditNumber;
    QHBoxLayout *horizontalLayout;
    QLabel *aircraftType;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *arrivalAirport;
    QLineEdit *lineEditAirport;
    QHBoxLayout *horizontalLayout_4;
    QLabel *departureTime;
    QLineEdit *lineEditTime;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QPushButton *File;
    QPushButton *Add;
    QPushButton *Delete;
    QPushButton *Sort;
    QVBoxLayout *verticalLayout_2;
    QPushButton *SearchByTime;
    QPushButton *SearchByNumber;
    QPushButton *SearchByAirport;
    QPushButton *Show;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWidowClass)
    {
        if (MainWidowClass->objectName().isEmpty())
            MainWidowClass->setObjectName(QStringLiteral("MainWidowClass"));
        MainWidowClass->resize(980, 708);
        QFont font;
        font.setPointSize(12);
        MainWidowClass->setFont(font);
        centralWidget = new QWidget(MainWidowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(430, 10, 531, 451));
        QFont font1;
        font1.setPointSize(9);
        tableWidget->setFont(font1);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 351, 301));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        flightNumber = new QLabel(layoutWidget);
        flightNumber->setObjectName(QStringLiteral("flightNumber"));
        flightNumber->setFont(font);

        horizontalLayout_2->addWidget(flightNumber);

        lineEditNumber = new QLineEdit(layoutWidget);
        lineEditNumber->setObjectName(QStringLiteral("lineEditNumber"));

        horizontalLayout_2->addWidget(lineEditNumber);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        aircraftType = new QLabel(layoutWidget);
        aircraftType->setObjectName(QStringLiteral("aircraftType"));

        horizontalLayout->addWidget(aircraftType);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        arrivalAirport = new QLabel(layoutWidget);
        arrivalAirport->setObjectName(QStringLiteral("arrivalAirport"));

        horizontalLayout_3->addWidget(arrivalAirport);

        lineEditAirport = new QLineEdit(layoutWidget);
        lineEditAirport->setObjectName(QStringLiteral("lineEditAirport"));

        horizontalLayout_3->addWidget(lineEditAirport);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        departureTime = new QLabel(layoutWidget);
        departureTime->setObjectName(QStringLiteral("departureTime"));

        horizontalLayout_4->addWidget(departureTime);

        lineEditTime = new QLineEdit(layoutWidget);
        lineEditTime->setObjectName(QStringLiteral("lineEditTime"));

        horizontalLayout_4->addWidget(lineEditTime);


        verticalLayout->addLayout(horizontalLayout_4);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(550, 490, 411, 151));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        File = new QPushButton(layoutWidget1);
        File->setObjectName(QStringLiteral("File"));
        QFont font2;
        font2.setPointSize(11);
        File->setFont(font2);

        verticalLayout_3->addWidget(File);

        Add = new QPushButton(layoutWidget1);
        Add->setObjectName(QStringLiteral("Add"));
        Add->setFont(font2);

        verticalLayout_3->addWidget(Add);

        Delete = new QPushButton(layoutWidget1);
        Delete->setObjectName(QStringLiteral("Delete"));
        Delete->setFont(font2);

        verticalLayout_3->addWidget(Delete);

        Sort = new QPushButton(layoutWidget1);
        Sort->setObjectName(QStringLiteral("Sort"));

        verticalLayout_3->addWidget(Sort);


        horizontalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        SearchByTime = new QPushButton(layoutWidget1);
        SearchByTime->setObjectName(QStringLiteral("SearchByTime"));
        SearchByTime->setFont(font2);

        verticalLayout_2->addWidget(SearchByTime);

        SearchByNumber = new QPushButton(layoutWidget1);
        SearchByNumber->setObjectName(QStringLiteral("SearchByNumber"));
        SearchByNumber->setFont(font2);

        verticalLayout_2->addWidget(SearchByNumber);

        SearchByAirport = new QPushButton(layoutWidget1);
        SearchByAirport->setObjectName(QStringLiteral("SearchByAirport"));
        SearchByAirport->setFont(font2);

        verticalLayout_2->addWidget(SearchByAirport);

        Show = new QPushButton(layoutWidget1);
        Show->setObjectName(QStringLiteral("Show"));

        verticalLayout_2->addWidget(Show);


        horizontalLayout_5->addLayout(verticalLayout_2);

        MainWidowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWidowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 980, 26));
        MainWidowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWidowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWidowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWidowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWidowClass->setStatusBar(statusBar);

        retranslateUi(MainWidowClass);

        QMetaObject::connectSlotsByName(MainWidowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWidowClass)
    {
        MainWidowClass->setWindowTitle(QApplication::translate("MainWidowClass", "MainWidow", Q_NULLPTR));
        flightNumber->setText(QApplication::translate("MainWidowClass", "Flight number:", Q_NULLPTR));
        lineEditNumber->setInputMask(QApplication::translate("MainWidowClass", "999", Q_NULLPTR));
        aircraftType->setText(QApplication::translate("MainWidowClass", "Aircraft type:", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWidowClass", "Airbus", Q_NULLPTR)
         << QApplication::translate("MainWidowClass", "Boeing", Q_NULLPTR)
         << QApplication::translate("MainWidowClass", "Superjet", Q_NULLPTR)
         << QApplication::translate("MainWidowClass", "Tupolev", Q_NULLPTR)
        );
        arrivalAirport->setText(QApplication::translate("MainWidowClass", "Arrival airport:", Q_NULLPTR));
        lineEditAirport->setInputMask(QApplication::translate("MainWidowClass", "AAAAAAAAAAAA", Q_NULLPTR));
        departureTime->setText(QApplication::translate("MainWidowClass", "Departure time:", Q_NULLPTR));
        lineEditTime->setInputMask(QApplication::translate("MainWidowClass", "99:99", Q_NULLPTR));
        File->setText(QApplication::translate("MainWidowClass", "Open file", Q_NULLPTR));
        Add->setText(QApplication::translate("MainWidowClass", "Add", Q_NULLPTR));
        Delete->setText(QApplication::translate("MainWidowClass", "Delete", Q_NULLPTR));
        Sort->setText(QApplication::translate("MainWidowClass", "Sort", Q_NULLPTR));
        SearchByTime->setText(QApplication::translate("MainWidowClass", "Search by time", Q_NULLPTR));
        SearchByNumber->setText(QApplication::translate("MainWidowClass", "Search by number", Q_NULLPTR));
        SearchByAirport->setText(QApplication::translate("MainWidowClass", "Search by airport", Q_NULLPTR));
        Show->setText(QApplication::translate("MainWidowClass", "Show List", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWidowClass: public Ui_MainWidowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDOW_H
