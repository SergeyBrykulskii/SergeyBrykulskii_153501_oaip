/********************************************************************************
** Form generated from reading UI file 'canvas.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANVAS_H
#define UI_CANVAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Canva
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Canva)
    {
        if (Canva->objectName().isEmpty())
            Canva->setObjectName(QStringLiteral("Canva"));
        Canva->resize(800, 600);
        centralwidget = new QWidget(Canva);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(5, 11, 781, 531));
        Canva->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Canva);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Canva->setMenuBar(menubar);
        statusbar = new QStatusBar(Canva);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Canva->setStatusBar(statusbar);

        retranslateUi(Canva);

        QMetaObject::connectSlotsByName(Canva);
    } // setupUi

    void retranslateUi(QMainWindow *Canva)
    {
        Canva->setWindowTitle(QApplication::translate("Canva", "MainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Canva: public Ui_Canva {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANVAS_H
