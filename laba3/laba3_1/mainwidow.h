#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwidow.h"

class MainWidow : public QMainWindow
{
    Q_OBJECT

public:
    MainWidow(QWidget *parent = Q_NULLPTR);

private:
    Ui::MainWidowClass ui;
};
