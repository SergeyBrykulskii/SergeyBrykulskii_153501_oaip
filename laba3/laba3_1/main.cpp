#include "mainwidow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidow w;
    w.show();
    return a.exec();
}
