#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	

}

QString IntToQString(int num)
{
	QString str;
	str.setNum(num);
	return str;
}

void MainWindow::on_push_back_clicked()
{
	dq.push_back(ui.toBack->text().toInt());
	 
	ui.listWidget->addItem(ui.toBack->text());

	ui.toBack->clear();
}

void MainWindow::on_push_front_clicked()
{
	dq.push_front(ui.toFront->text().toInt());
	
	ui.listWidget->clear();
	for (auto it : dq)
	{
		ui.listWidget->addItem(IntToQString(it));
	}
		
	ui.toFront->clear();
}

void MainWindow::on_pop_back_clicked()
{
	if (dq.empty())
	{
		QMessageBox::warning(this, "Warning", "Deque is empty!");
	}
	else
	{
		dq.pop_back();
		ui.listWidget->takeItem(ui.listWidget->count() - 1);
	}
}

void MainWindow::on_pop_front_clicked()
{
	if (dq.empty())
	{
		QMessageBox::warning(this, "Warning", "Deque is empty!");
	}
	else
	{
		dq.pop_front();
		ui.listWidget->takeItem(0);
	}
}

void MainWindow::on_getElem_clicked()
{
	if (dq.empty())
	{
		QMessageBox::warning(this, "Warning", "Deque is empty!");
	}
	else if (ui.numOfEl->text().toInt() > dq.size() || ui.numOfEl->text().toInt() <= 0)
	{
		QMessageBox::warning(this, "Warning", "Wrong number!");
	}
	else
	{
		QMessageBox::information(this, "Elenment", IntToQString(dq[ui.numOfEl->text().toInt() - 1]));
	}
}

void MainWindow::on_clear_clicked()
{
	ui.listWidget->clear();
	dq.clear();
}

void MainWindow::on_Size_clicked()
{
	QMessageBox::information(this, "Size", IntToQString(dq.size()));
}

void MainWindow::on_Empty_clicked()
{
	if (dq.empty())
	{
		QMessageBox::information(this, "Empty", "Yes");
	}
	else
	{
		QMessageBox::information(this, "Empty", "No");
	}
}
