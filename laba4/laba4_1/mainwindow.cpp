#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}
QString intToQString(int num)
{
	QString str;
	str.setNum(num);
	return str;
}

QString vectorToText(Vector<int>& vec)
{
	QString str;
	for (int i = 0; i < vec.size(); i++)
	{
		str += intToQString(vec[i]);
		str += " ";
	}
	return str;
}
void MainWindow::on_pushBack_clicked()
{
    vec.push_back(ui.pushbackg->text().toInt());
    ui.textBrowser->setText(ui.textBrowser->toPlainText() + " " + ui.pushbackg->text());
    
    ui.size->setText(intToQString(vec.size()));
    ui.capacity->setText(intToQString(vec.capacity()));
}

void MainWindow::on_popBack_clicked()
{
	if (vec.size() == 0)
	{
		QMessageBox::critical(this, "Error", "Vector is empty");
		return;
	}
	
    vec.pop_back();

    ui.textBrowser->setText(vectorToText(vec));
		
    ui.size->setText(intToQString(vec.size()));
}

void MainWindow::on_sort_clicked()
{
	vec.sort();
	ui.textBrowser->setText(vectorToText(vec));
}

void MainWindow::on_reverse_clicked()
{
	vec.reverse();
	ui.textBrowser->setText(vectorToText(vec));
}

void MainWindow::on_swap_clicked()
{
	if (vec.size() == 0)
	{
		QMessageBox::critical(this, "Error", "Vector is empty");
		return;
	}
	
	int a = ui.num1->text().toInt();
	int b = ui.num2->text().toInt();
	
	if (a > vec.size() || b > vec.size())
	{
		QMessageBox::critical(this, "Error", "Index is out of range");
		return;
	}
	
	vec.swap(a - 1, b - 1);
	
	ui.textBrowser->setText(vectorToText(vec));
}

void MainWindow::on_insert_clicked()
{
	int index = ui.index->text().toInt();
	
	if (index > vec.size() || index < 0)
	{
		QMessageBox::critical(this, "Error", "Index is out of range");
		return;
	}

	int value = ui.insertg->text().toInt();
	
	vec.insert(index, value);
	
	ui.textBrowser->setText(vectorToText(vec));
	
	ui.size->setText(intToQString(vec.size()));
	ui.capacity->setText(intToQString(vec.capacity()));
}

void MainWindow::on_reserve_clicked()
{
	int capacity = ui.reserveg->text().toInt();
	
	vec.reserve(capacity);

	ui.capacity->setText(intToQString(vec.capacity()));
}

void MainWindow::on_erase_clicked()
{
	int index = ui.eraseg->text().toInt();

	if (index - 1 >= vec.size() || index < 1)
	{
		QMessageBox::critical(this, "Error", "Index is out of range");
		return;
	}

	vec.erase(index - 1);
	
	ui.textBrowser->setText(vectorToText(vec));
}

void MainWindow::on_clear_clicked()
{
	vec.clear();
	ui.textBrowser->setText("");
	ui.size->setText(intToQString(vec.size()));
	ui.capacity->setText(intToQString(vec.capacity()));
}

	