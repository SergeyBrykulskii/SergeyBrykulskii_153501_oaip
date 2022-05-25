#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

void MainWindow::on_InsertMap_clicked()
{
    int key;
    QString data;
	
	if (ui.getKeyMap->text() == "")
	{
		QMessageBox::critical(this, "Error", "Please enter a key");
		return;
	}
	
	if (ui.getValueMap->text() == "")
	{
		QMessageBox::critical(this, "Error", "Please enter a value");
		return;
	}
	
    key = ui.getKeyMap->text().toInt();
	
	data = ui.getValueMap->text();
	
	map.insert(map.getRoot(), key, data);
	
	ui.listMap->clear();
	
	for(auto it = map.begin(); it != map.end(); it++)
	{
		ui.listMap->addItem("Key: " + QString::number(it->first) + "  Data: " + it->second);
	}
	
	ui.getKeyMap->clear();
	ui.getValueMap->clear();
}

void MainWindow::on_FindMap_clicked()
{
	int key;
	
	if (ui.getFindMap->text() == "")
	{
		QMessageBox::critical(this, "Error", "Please enter a key");
		return;
	}

	key = ui.getFindMap->text().toInt();

	if (map.find(map.getRoot(), key) == nullptr)
	{
		QMessageBox::critical(this, "Error", "Key not found");
	}
	else
	{
		QMessageBox::information(this, "Success", "Key found");
	}
	
	ui.getFindMap->clear();
}

void MainWindow::on_RemoveMap_clicked()
{
	int key;
	
	if (ui.getRemoveMap->text() == "")
	{
		QMessageBox::critical(this, "Error", "Please enter a key");
		return;
	}

	key = ui.getRemoveMap->text().toInt();

	if (map.find(map.getRoot(), key) == nullptr)
	{
		QMessageBox::critical(this, "Error", "Key not found");
		ui.getRemoveMap->clear();
		return;
	}
	else
	{
		QMessageBox::information(this, "Success", "Key removed");
		map.remove(map.getRoot(), key);
	}
	
	ui.getRemoveMap->clear();
	
	ui.listMap->clear();
	
	for(auto it = map.begin(); it != map.end(); it++)
	{
		ui.listMap->addItem("Key: " + QString::number(it->first) + "  Data: " + it->second);
	}
}

void MainWindow::on_InsertSet_clicked()
{
	int key;
	
	if (ui.getKeySet->text() == "")
	{
		QMessageBox::critical(this, "Error", "Please enter a key");
		return;
	}
	
	key = ui.getKeySet->text().toInt();
	
	set.insert(set.getRoot(), key);
	
	ui.listSet->clear();
	
	for(auto it = set.begin(); it != set.end(); it++)
	{
		ui.listSet->addItem("Key: " + QString::number(*it));
	}
	
	ui.getKeySet->clear();
}

void MainWindow::on_FindSet_clicked()
{
	int key;
	
	if (ui.getFindSet->text() == "")
	{
		QMessageBox::critical(this, "Error", "Please enter a key");
		return;
	}

	key = ui.getFindSet->text().toInt();

	if (set.find(set.getRoot(), key) == nullptr)
	{
		QMessageBox::critical(this, "Error", "Key not found");
	}
	else
	{
		QMessageBox::information(this, "Success", "Key found");
	}
	
	ui.getFindSet->clear();
}

void MainWindow::on_RemoveSet_clicked()
{
	int key;
	
	if (ui.getRemoveSet->text() == "")
	{
		QMessageBox::critical(this, "Error", "Please enter a key");
		return;
	}

	key = ui.getRemoveSet->text().toInt();

	if (set.find(set.getRoot(), key) == nullptr)
	{
		QMessageBox::critical(this, "Error", "Key not found");
		ui.getRemoveSet->clear();
		return;
	}
	else
	{
		QMessageBox::information(this, "Success", "Key removed");
		set.remove(set.getRoot(), key);
	}
	
	ui.getRemoveSet->clear();
	
	ui.listSet->clear();
	
	for(auto it = set.begin(); it != set.end(); it++)
	{
		ui.listSet->addItem("Key: " + QString::number(*it));
	}
}
