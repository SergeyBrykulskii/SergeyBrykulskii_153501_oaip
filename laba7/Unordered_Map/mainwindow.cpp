#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

void MainWindow::on_Add_clicked()
{
	//srand(/*time(0)*/1);
    
	int num = rand();
	umap.insert(num, num);
	
	ui.listWidget->clear();
	
	for (int i = 0; i < umap.getSize(); i < i++)
	{
		QString str = "";
		str += QString::number(i + 1) + ") ";
		
		for (auto it = umap.getTable()[i].begin(); it != umap.getTable()[i].end(); it++)
		{
			str += " " + QString::number(it->second);
		}
		
		ui.listWidget->addItem(str);
	}
}

void MainWindow::on_Remove_clicked()
{
	if (ui.getRemove->text() == "")
	{
		QMessageBox::warning(this, "Warning", "Enter the number of the element to remove");
		return;
	}
	
	if (umap.getSize() == 0)
	{
		QMessageBox::warning(this, "Warning", "The table is empty");
		return;
	}
	
	umap.erase(ui.getRemove->text().toInt());

	ui.listWidget->clear();
	
	for (int i = 0; i < umap.getSize(); i < i++)
	{
		QString str = "";
		str += QString::number(i + 1) + ") ";
		
		for (auto it = umap.getTable()[i].begin(); it != umap.getTable()[i].end(); it++)
		{
			str += " " + QString::number(it->second);
		}
		
		ui.listWidget->addItem(str);
	}
	
	ui.getRemove->clear();
}

void MainWindow::on_Find_clicked()
{
	if (ui.getFind->text() == "")
	{
		QMessageBox::warning(this, "Warning", "Enter the number of the element to find");
		return;
	}
	
	if (umap.getSize() == 0)
	{
		QMessageBox::warning(this, "Warning", "The table is empty");
		return;
	}

	if (umap.find(ui.getFind->text().toInt()))
	{
		QMessageBox::information(this, "Information", "The element is found");
	}
	else
	{
		QMessageBox::warning(this, "Warning", "The element is not found");
	}

	ui.getFind->clear();
}
