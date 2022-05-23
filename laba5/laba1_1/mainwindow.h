#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "List.h"
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = Q_NULLPTR);

public slots:
	void on_Move_clicked();
	
private:
    QString FilePath;
	List<QString> list;
    Ui::MainWindowClass ui;
};
