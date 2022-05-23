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
void MainWindow::on_push_clicked()
{
	QString str = ui.element->text();
	if (str == "")
	{
		QMessageBox::warning(this, "Warning", "Please enter an element");
		return;
	}
	
	queue.push(str.toInt());
	ui.element->clear();
	ui.listWidget->addItem(str);
	str = "";
}

void MainWindow::on_pop_clicked()
{
	if (queue.empty())
	{
		QMessageBox::warning(this, "Warning", "Queue is empty");
		return;
	}

	int x = queue.pop();
	
	ui.listWidget->takeItem(0);
	
	ui.showElement->setText(IntToQString(x));
}