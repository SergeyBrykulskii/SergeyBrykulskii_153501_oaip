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
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *Left;
    QPushButton *Entered;
    QPushButton *OnStation;
    QPushButton *OnWay;
    QVBoxLayout *verticalLayout_2;
    QPushButton *File;
    QPushButton *Add;
    QPushButton *SearchByDestination;
    QPushButton *SearchByTime;
    QPushButton *Sort;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLineEdit *Number;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QComboBox *Type;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *Destination;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *Departure;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *Arrival;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(1034, 735);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(385, 11, 641, 451));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(420, 470, 601, 197));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Left = new QPushButton(layoutWidget);
        Left->setObjectName(QStringLiteral("Left"));
        QFont font;
        font.setPointSize(12);
        Left->setFont(font);

        verticalLayout->addWidget(Left);

        Entered = new QPushButton(layoutWidget);
        Entered->setObjectName(QStringLiteral("Entered"));
        Entered->setFont(font);

        verticalLayout->addWidget(Entered);

        OnStation = new QPushButton(layoutWidget);
        OnStation->setObjectName(QStringLiteral("OnStation"));
        OnStation->setFont(font);

        verticalLayout->addWidget(OnStation);

        OnWay = new QPushButton(layoutWidget);
        OnWay->setObjectName(QStringLiteral("OnWay"));
        OnWay->setFont(font);

        verticalLayout->addWidget(OnWay);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        File = new QPushButton(layoutWidget);
        File->setObjectName(QStringLiteral("File"));
        File->setFont(font);

        verticalLayout_2->addWidget(File);

        Add = new QPushButton(layoutWidget);
        Add->setObjectName(QStringLiteral("Add"));
        Add->setFont(font);

        verticalLayout_2->addWidget(Add);

        SearchByDestination = new QPushButton(layoutWidget);
        SearchByDestination->setObjectName(QStringLiteral("SearchByDestination"));
        SearchByDestination->setFont(font);

        verticalLayout_2->addWidget(SearchByDestination);

        SearchByTime = new QPushButton(layoutWidget);
        SearchByTime->setObjectName(QStringLiteral("SearchByTime"));
        SearchByTime->setFont(font);

        verticalLayout_2->addWidget(SearchByTime);

        Sort = new QPushButton(layoutWidget);
        Sort->setObjectName(QStringLiteral("Sort"));
        Sort->setFont(font);

        verticalLayout_2->addWidget(Sort);


        horizontalLayout->addLayout(verticalLayout_2);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 371, 331));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout_6->addWidget(label);

        Number = new QLineEdit(layoutWidget1);
        Number->setObjectName(QStringLiteral("Number"));
        Number->setFont(font);

        horizontalLayout_6->addWidget(Number);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_5->addWidget(label_2);

        Type = new QComboBox(layoutWidget1);
        Type->setObjectName(QStringLiteral("Type"));
        Type->setFont(font);

        horizontalLayout_5->addWidget(Type);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_4->addWidget(label_3);

        Destination = new QLineEdit(layoutWidget1);
        Destination->setObjectName(QStringLiteral("Destination"));

        horizontalLayout_4->addWidget(Destination);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_2->addWidget(label_5);

        Departure = new QLineEdit(layoutWidget1);
        Departure->setObjectName(QStringLiteral("Departure"));

        horizontalLayout_2->addWidget(Departure);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_3->addWidget(label_4);

        Arrival = new QLineEdit(layoutWidget1);
        Arrival->setObjectName(QStringLiteral("Arrival"));

        horizontalLayout_3->addWidget(Arrival);


        verticalLayout_3->addLayout(horizontalLayout_3);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1034, 26));
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
        Left->setText(QApplication::translate("MainWindowClass", "Left the station", Q_NULLPTR));
        Entered->setText(QApplication::translate("MainWindowClass", "Entered the station", Q_NULLPTR));
        OnStation->setText(QApplication::translate("MainWindowClass", "Show on station", Q_NULLPTR));
        OnWay->setText(QApplication::translate("MainWindowClass", "Show on the way", Q_NULLPTR));
        File->setText(QApplication::translate("MainWindowClass", "Open file", Q_NULLPTR));
        Add->setText(QApplication::translate("MainWindowClass", "Add", Q_NULLPTR));
        SearchByDestination->setText(QApplication::translate("MainWindowClass", "Search by destination", Q_NULLPTR));
        SearchByTime->setText(QApplication::translate("MainWindowClass", "Search by time", Q_NULLPTR));
        Sort->setText(QApplication::translate("MainWindowClass", "Sort", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindowClass", "Number of bus:", Q_NULLPTR));
        Number->setInputMask(QApplication::translate("MainWindowClass", "9999", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindowClass", "Type of bus:", Q_NULLPTR));
        Type->clear();
        Type->insertItems(0, QStringList()
         << QApplication::translate("MainWindowClass", "Sleeper bus", Q_NULLPTR)
         << QApplication::translate("MainWindowClass", "Party bus", Q_NULLPTR)
         << QApplication::translate("MainWindowClass", "Cargo-passenger", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("MainWindowClass", "Destination:", Q_NULLPTR));
        Destination->setInputMask(QApplication::translate("MainWindowClass", "AAAAAAAAAAA", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindowClass", "Departure time:", Q_NULLPTR));
        Departure->setInputMask(QApplication::translate("MainWindowClass", "99:99", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindowClass", "Arrival time", Q_NULLPTR));
        Arrival->setInputMask(QApplication::translate("MainWindowClass", "99:99", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
