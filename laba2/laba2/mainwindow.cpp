#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
   
    
    ui.stackTable->setRowCount(0);
    ui.stackTable->setColumnCount(1);
}

void MainWindow::on_push_clicked()
{
    if (stack.get()->sizeofStack() > ui.stackTable->rowCount())
    {
        ui.stackTable->insertRow(ui.stackTable->rowCount());
        stack.get()->push(ui.stackTable->rowCount() - 1);
        ui.stackTable->setItem(ui.stackTable->rowCount() - 1, 0, new QTableWidgetItem("element of stack"));
    }
    else
    {
        QMessageBox::critical(this, "Warning", "Stack is full");

    }
}

void MainWindow::on_pop_clicked()
{
    if (stack.get()->getTop() > 0)
    {
        stack.get()->pop();
        ui.stackTable->removeRow(0);
    }
    else
    {
        QMessageBox::critical(this, "Warning", "Stack is empty");

    }
}