#include "mainwindow.h"

QString FIRMS[4]{ "Intel", "HP", "MSI", "ASUS"};
QString TYPE[5]{ "Processor", "Motherboard", "RAM", "Disk drive", "Case"};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.radioButtonStock->setChecked(true);
    ui.tableWidget;

    size = 1;
    ComputerParts* itemOfCP = new ComputerParts[size];
}

void MainWindow::on_OpenFile_clicked()
{
    FilePath = QFileDialog::getOpenFileName(this, "Choose file", "C:/", "(*.txt);");

    QFile file(FilePath);

    file.seek(0);
    file.open(QFile::ReadOnly);
    
    QTextStream fin(&file);
    QString checkData = fin.readLine();
    
    if (checkData != "Intel" && checkData != "HP" && checkData != "MSI" && checkData != "ASUS")
    {
        QMessageBox::critical(this, "Warning", "Please, choose correct file");
        FilePath = "";
    }
}

void MainWindow::on_ShowInfo_clicked()
{
    if (FilePath == "")
    {
        QMessageBox::critical(this, "Warning", "Please, choose correct file");
    }
    else
    {
        
    }
}

void MainWindow::on_Add_clicked()
{
    
}

void MainWindow::on_Exit_clicked()
{
    close();
}