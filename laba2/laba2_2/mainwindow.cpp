#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.listTable->setRowCount(0);
    ui.listTable->setColumnCount(1);

}

void MainWindow::on_push_clicked()
{
    
    ui.listTable->insertRow(ui.listTable->rowCount());
    list.push_back(ui.listTable->rowCount() - 1);

    //QString = (list.getLength()).ToString();
    ui.listTable->setItem(ui.listTable->rowCount() - 1, 0, new QTableWidgetItem("list element"));
    
}

void MainWindow::on_pop_clicked()
{
    if (list.getLength() > 0)
    {
        list.pop_back();
        ui.listTable->removeRow(0);
    }
    else
    {
        QMessageBox::critical(this, "Warning", "List is empty");
    }
}
