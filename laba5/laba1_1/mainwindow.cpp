#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QFile file("C:\\Users\\Serxio\\Desktop\\QtProject\\laba5\\laba1_1\\mainwindow.cpp");

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Error", "File not found");
        return;
    }
	
    QTextStream in(&file);

    while (!in.atEnd()) { 
        QString line = in.readLine(); 
        ui.listWidget->addItem(line);
        list.push_back(line);
    }

    ui.infoLabel->setText("Enter numbers from 1 to " + QString::number(list.size()));
	
    file.close();
}

void MainWindow::on_Move_clicked()
{
    int firstLine = ui.firstLine->text().toInt();
    int lastLine = ui.lastLine->text().toInt();
    int position = ui.position->text().toInt();
	
    if (firstLine >= lastLine || lastLine > list.size() || lastLine == 0 || firstLine == 0 || position == 0 || position > list.size() + firstLine - lastLine || list.size() == lastLine - firstLine + 1)
    {
        ui.firstLine->clear();
		ui.lastLine->clear();
		ui.position->clear();
		QMessageBox::warning(this, "Warning", "Wrong input");
        return;
    }
	
    ui.listWidget->clear();

    list.moveBlock(firstLine - 1, lastLine - 1, position - 1);
	
    for (int i = 0; i < list.size(); i++)
    {
        ui.listWidget->addItem(list[i]);
        if (i >= position - 1 && i < position + lastLine - firstLine)
        {
			ui.listWidget->item(i)->setTextColor(Qt::red);
        }
    }
    
    ui.firstLine->clear();
    ui.lastLine->clear();
    ui.position->clear();
}