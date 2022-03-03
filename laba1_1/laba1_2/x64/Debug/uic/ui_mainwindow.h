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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *Triangle;
    QRadioButton *Square;
    QRadioButton *Rhombus;
    QRadioButton *Rectengle;
    QRadioButton *Hexagon;
    QRadioButton *Star;
    QRadioButton *Circle;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *Square_2;
    QLabel *label_2;
    QLineEdit *Perimeter;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushRight;
    QPushButton *pushLeft;
    QPushButton *pushUp;
    QPushButton *pushDown;
    QPushButton *ZoomIn;
    QPushButton *ZoomOut;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushRotationR;
    QPushButton *pushRotationL;
    QPushButton *Canva;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(875, 683);
        QFont font;
        font.setPointSize(10);
        MainWindowClass->setFont(font);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 0, 681, 421));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(700, 10, 151, 341));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Triangle = new QRadioButton(layoutWidget);
        Triangle->setObjectName(QStringLiteral("Triangle"));
        Triangle->setFont(font);

        verticalLayout->addWidget(Triangle);

        Square = new QRadioButton(layoutWidget);
        Square->setObjectName(QStringLiteral("Square"));
        Square->setFont(font);

        verticalLayout->addWidget(Square);

        Rhombus = new QRadioButton(layoutWidget);
        Rhombus->setObjectName(QStringLiteral("Rhombus"));
        Rhombus->setFont(font);

        verticalLayout->addWidget(Rhombus);

        Rectengle = new QRadioButton(layoutWidget);
        Rectengle->setObjectName(QStringLiteral("Rectengle"));
        Rectengle->setFont(font);

        verticalLayout->addWidget(Rectengle);

        Hexagon = new QRadioButton(layoutWidget);
        Hexagon->setObjectName(QStringLiteral("Hexagon"));
        Hexagon->setFont(font);

        verticalLayout->addWidget(Hexagon);

        Star = new QRadioButton(layoutWidget);
        Star->setObjectName(QStringLiteral("Star"));
        Star->setFont(font);

        verticalLayout->addWidget(Star);

        Circle = new QRadioButton(layoutWidget);
        Circle->setObjectName(QStringLiteral("Circle"));

        verticalLayout->addWidget(Circle);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 530, 461, 89));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        Square_2 = new QLineEdit(layoutWidget1);
        Square_2->setObjectName(QStringLiteral("Square_2"));

        horizontalLayout->addWidget(Square_2);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        Perimeter = new QLineEdit(layoutWidget1);
        Perimeter->setObjectName(QStringLiteral("Perimeter"));

        horizontalLayout->addWidget(Perimeter);

        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(560, 440, 295, 133));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushRight = new QPushButton(gridLayoutWidget);
        pushRight->setObjectName(QStringLiteral("pushRight"));
        QFont font1;
        font1.setPointSize(15);
        pushRight->setFont(font1);

        gridLayout->addWidget(pushRight, 1, 2, 1, 1);

        pushLeft = new QPushButton(gridLayoutWidget);
        pushLeft->setObjectName(QStringLiteral("pushLeft"));
        pushLeft->setEnabled(true);
        pushLeft->setFont(font1);

        gridLayout->addWidget(pushLeft, 1, 0, 1, 1);

        pushUp = new QPushButton(gridLayoutWidget);
        pushUp->setObjectName(QStringLiteral("pushUp"));
        pushUp->setFont(font1);

        gridLayout->addWidget(pushUp, 0, 1, 1, 1);

        pushDown = new QPushButton(gridLayoutWidget);
        pushDown->setObjectName(QStringLiteral("pushDown"));
        pushDown->setFont(font1);

        gridLayout->addWidget(pushDown, 2, 1, 1, 1);

        ZoomIn = new QPushButton(centralWidget);
        ZoomIn->setObjectName(QStringLiteral("ZoomIn"));
        ZoomIn->setGeometry(QRect(270, 450, 93, 28));
        QFont font2;
        font2.setPointSize(9);
        ZoomIn->setFont(font2);
        ZoomOut = new QPushButton(centralWidget);
        ZoomOut->setObjectName(QStringLiteral("ZoomOut"));
        ZoomOut->setGeometry(QRect(270, 490, 93, 28));
        ZoomOut->setFont(font2);
        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 450, 186, 65));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushRotationR = new QPushButton(layoutWidget2);
        pushRotationR->setObjectName(QStringLiteral("pushRotationR"));
        pushRotationR->setFont(font2);

        verticalLayout_2->addWidget(pushRotationR);

        pushRotationL = new QPushButton(layoutWidget2);
        pushRotationL->setObjectName(QStringLiteral("pushRotationL"));
        pushRotationL->setFont(font2);

        verticalLayout_2->addWidget(pushRotationL);

        Canva = new QPushButton(centralWidget);
        Canva->setObjectName(QStringLiteral("Canva"));
        Canva->setGeometry(QRect(730, 370, 93, 28));
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 875, 26));
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
        Triangle->setText(QApplication::translate("MainWindowClass", "\320\242\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", Q_NULLPTR));
        Square->setText(QApplication::translate("MainWindowClass", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202", Q_NULLPTR));
        Rhombus->setText(QApplication::translate("MainWindowClass", "\320\240\320\276\320\274\320\261", Q_NULLPTR));
        Rectengle->setText(QApplication::translate("MainWindowClass", "\320\237\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", Q_NULLPTR));
        Hexagon->setText(QApplication::translate("MainWindowClass", "\320\250\320\265\321\201\321\202\320\270\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", Q_NULLPTR));
        Star->setText(QApplication::translate("MainWindowClass", "\320\227\320\262\320\265\320\267\320\264\320\260", Q_NULLPTR));
        Circle->setText(QApplication::translate("MainWindowClass", "\320\232\321\200\321\203\320\263", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindowClass", "\320\237\320\273\320\276\321\211\320\260\320\264\321\214:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindowClass", "\320\237\320\265\321\200\320\270\320\274\320\265\321\202\321\200:", Q_NULLPTR));
        pushRight->setText(QApplication::translate("MainWindowClass", "\341\220\205", Q_NULLPTR));
        pushLeft->setText(QApplication::translate("MainWindowClass", "\341\220\212", Q_NULLPTR));
        pushUp->setText(QApplication::translate("MainWindowClass", "\341\220\203", Q_NULLPTR));
        pushDown->setText(QApplication::translate("MainWindowClass", "\341\220\201", Q_NULLPTR));
        ZoomIn->setText(QApplication::translate("MainWindowClass", "\320\243\320\262\320\265\320\273\320\270\321\207\320\265\320\275\320\270\320\265", Q_NULLPTR));
        ZoomOut->setText(QApplication::translate("MainWindowClass", "\320\243\320\274\320\265\320\275\321\214\321\210\320\265\320\275\320\270\320\265", Q_NULLPTR));
        pushRotationR->setText(QApplication::translate("MainWindowClass", "\320\222\321\200\320\260\321\211\320\260\321\202\321\214 \320\277\320\276 \321\207\320\260\321\201\320\276\320\262\320\276\320\271", Q_NULLPTR));
        pushRotationL->setText(QApplication::translate("MainWindowClass", "\320\222\321\200\320\260\321\211\320\260\321\202\321\214 \320\277\321\200\320\276\321\202\320\270\320\262 \321\207\320\260\321\201\320\276\320\262\320\276\320\271", Q_NULLPTR));
        Canva->setText(QApplication::translate("MainWindowClass", "\320\240\320\270\321\201\320\276\320\262\320\260\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
