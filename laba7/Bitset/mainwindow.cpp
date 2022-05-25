#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

void MainWindow::on_Make_clicked()
{
    int num;
	
	if (ui.get->text() == "")
	{
		QMessageBox::critical(this, "Error", "Please enter a number");
		return;
	}
	
	num = ui.get->text().toInt();
	
	bitset = num;
	
	ui.bitset->setText(QString::fromStdString(bitset.to_string()));

	ui.get->clear();
}

void MainWindow::on_All_clicked()
{
	if (ui.bitset->text() == "")
	{
		QMessageBox::critical(this, "Error", "Please enter a number");
		return;
	}
	
	if (bitset.all())
	{
		QMessageBox::information(this, "All", "All bits are 1");
	}
	else
	{
		QMessageBox::information(this, "All", "Not all bits are 1");
	}
}

void MainWindow::on_Any_clicked()
{
	if (ui.bitset->text() == "")
	{
		QMessageBox::critical(this, "Error", "Please enter a number");
		return;
	}
	
	if (bitset.any())
	{
		QMessageBox::information(this, "Any", "At least one bit is 1");
	}
	else
	{
		QMessageBox::information(this, "Any", "No bits are 1");
	}
}

void MainWindow::on_None_clicked()
{
	if (ui.bitset->text() == "")
	{
		QMessageBox::critical(this, "Error", "Please enter a number");
		return;
	}
	
	if (bitset.none())
	{
		QMessageBox::information(this, "None", "No bits are 1");
	}
	else
	{
		QMessageBox::information(this, "None", "At least one bit is 1");
	}
}

void MainWindow::on_Size_clicked()
{
	if (ui.bitset->text() == "")
	{
		QMessageBox::critical(this, "Error", "Please enter a number");
		return;
	}
	
	QMessageBox::information(this, "Size", "The size of the bitset is " + QString::number(bitset.size()));
}

void MainWindow::on_Flip_clicked()
{
	if (ui.bitset->text() == "")
	{
		QMessageBox::critical(this, "Error", "Please enter a number");
		return;
	}
	
	if (ui.getPos->text() == "")
	{
		bitset.flip();
		ui.bitset->clear();
		ui.bitset->setText(QString::fromStdString(bitset.to_string()));
	}
	else
	{
		if (ui.getPos->text().toInt() > bitset.size())
		{
			QMessageBox::critical(this, "Error", "Please enter a valid position");
			return;
		}
		
		bitset.flip(ui.getPos->text().toInt());
		ui.bitset->clear();
		ui.bitset->setText(QString::fromStdString(bitset.to_string()));
	}
}

void MainWindow::on_Set_clicked()
{
	if (ui.bitset->text() == "")
	{
		QMessageBox::critical(this, "Error", "Please enter a number");
		return;
	}

	if (ui.getPos->text() == "")
	{
		bitset.set();
		ui.bitset->clear();
		ui.bitset->setText(QString::fromStdString(bitset.to_string()));
	}
	else
	{
		if (ui.getPos->text().toInt() > bitset.size())
		{
			QMessageBox::critical(this, "Error", "Please enter a valid position");
			return;
		}

		bitset.set(ui.getPos->text().toInt());
		ui.bitset->clear();
		ui.bitset->setText(QString::fromStdString(bitset.to_string()));
	}
}

void MainWindow::on_Reset_clicked()
{
	if (ui.bitset->text() == "")
	{
		QMessageBox::critical(this, "Error", "Please enter a number");
		return;
	}

	if (ui.getPos->text() == "")
	{
		bitset.reset();
		ui.bitset->clear();
		ui.bitset->setText(QString::fromStdString(bitset.to_string()));
	}
	else
	{
		if (ui.getPos->text().toInt() > bitset.size())
		{
			QMessageBox::critical(this, "Error", "Please enter a valid position");
			return;
		}

		bitset.reset(ui.getPos->text().toInt());
		ui.bitset->clear();
		ui.bitset->setText(QString::fromStdString(bitset.to_string()));
	}
}

void MainWindow::on_Test_clicked()
{
	if (ui.bitset->text() == "")
	{
		QMessageBox::critical(this, "Error", "Please enter a number");
		return;
	}
	
	if (ui.getPos->text() == "")
	{
		QMessageBox::critical(this, "Error", "Please enter a position");
		return;
	}
	
	if (ui.getPos->text().toInt() > bitset.size())
	{
		QMessageBox::critical(this, "Error", "Please enter a valid position");
		return;
	}
	
	if (bitset.test(ui.getPos->text().toInt()))
	{
		QMessageBox::information(this, "Test", "The bit at position " + QString::number(ui.getPos->text().toInt()) + " is 1");
	}
	else
	{
		QMessageBox::information(this, "Test", "The bit at position " + QString::number(ui.getPos->text().toInt()) + " is 0");
	}
}