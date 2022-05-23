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

void MainWindow::on_MakeHashTable_clicked()
{
	
	if (flag == 1)
		return;
	flag++;
	srand(time(0));
	for (int i = 0; i < 30; i++)
	{
		int num = rand();
		ht.insert(num, num);
	}
	
	//QMessageBox::information(this, "", "Found"); 
	for (int i = 0; i < ht.getSize(); i < i++)
	{
		ui.listWidget->addItem(IntToQString(i + 1) + ")  " + ht.GetBucket(i));
	}
}

void MainWindow::on_FindMax_clicked()
{
	QMessageBox::information(this, "Index of bucket that contains max el", IntToQString(ht.findMax() + 1)); 
}