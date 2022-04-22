#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	
    testExp[0] = Expression("a/(b-c)*(d+e)", "8.6", "3.4", "5.1", "0.3", "7.9");
    testExp[1] = Expression("(a+b)*(c-d)/e", "7.4", "3.6", "2.8", "9.5", "0.9");
    testExp[2] = Expression("a-(b+c*d)/e", "3.1", "5.4", "0.2", "9.6", "7.8");
    testExp[3] = Expression("a/b-((c+d)*e)", "1.2", "0.7", "9.3", "6.5", "8.4");
    testExp[4] = Expression("a*(b-c+d)/e", "9.7", "8.2", "3.6", "4.1", "0.5");
    testExp[5] = Expression("(a+b)*(c-d)/e", "0.8", "4.1", "7.9", "6.2", "3.5");
    testExp[6] = Expression("a*(b-c)/(d-e)", "1.6", "4.9", "5.7", "0.8", "2.3");
    testExp[7] = Expression("a/(b*(c+d))-e", "8.5", "0.3", "2.4", "7.9", "1.6");
    testExp[8] = Expression("((a+b/c-d))*e", "5.6", "7.4", "8.9", "3.1", "0.2");
    testExp[9] = Expression("a*(b+c)/(d-e)", "0.4", "2.3", "6.7", "5.8", "9.1");
    testExp[10] = Expression("a-(b/c*(d+e))", "5.6", "3.2", "0.9", "1.7", "4.8");
    testExp[11] = Expression("(a-b)/(c+d)*e", "0.3", "6.7", "8.4", "9.5", "1.2");
    testExp[12] = Expression("a/(b+c-d*e)", "7.6", "4.8", "3.5", "9.1", "0.2");
    testExp[13] = Expression("a*(b-c)/(d+e)", "0.5", "6.1", "8.9", "2.4", "7.3");
    testExp[14] = Expression("(a+b*c)/(d-e)", "9.1", "0.6", "2.4", "3.7", "8.5");
    num = 15;
	
    for (int i = 0; i < 15; i++)
    {
        ui.tableWidget->insertRow(ui.tableWidget->rowCount());
		
        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 0, new QTableWidgetItem(testExp[i].getExpression()));
        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 1, new QTableWidgetItem(testExp[i].getAValue()));
        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 2, new QTableWidgetItem(testExp[i].getBValue()));
        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 3, new QTableWidgetItem(testExp[i].getCValue()));
        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 4, new QTableWidgetItem(testExp[i].getDValue()));
        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 5, new QTableWidgetItem(testExp[i].getEValue()));
		ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 6, new QTableWidgetItem(testExp[i].getInfixExpression()));
    }                           
}
void MainWindow::on_Add_clicked()
{

    if (ui.Expression->text() == "")
    {
		QMessageBox::critical(this, "Error", "Expression is empty");
    }
		
    for (auto ch : ui.Expression->text())
    {
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '(' && ch != ')' && ch != 'a' && ch != 'b' && ch != 'c' && ch != 'd' && ch != 'e')
        {
			QMessageBox::critical(this, "Error", "Incorrect expression");
			return;
        }
    }
	
	if (ui.AValue->text()[0] == '.' || ui.BValue->text()[0] == '.' || ui.CValue->text()[0] == '.' || ui.DValue->text()[0] == '.' || ui.EValue->text()[0] == '.')
	{
		QMessageBox::critical(this, "Error", "Incorrect value");
		return;
	}
	
    ui.tableWidget->insertRow(ui.tableWidget->rowCount());
	ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 0, new QTableWidgetItem(ui.Expression->text()));
	ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 1, new QTableWidgetItem(ui.AValue->text()));
	ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 2, new QTableWidgetItem(ui.BValue->text()));
	ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 3, new QTableWidgetItem(ui.CValue->text()));
	ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 4, new QTableWidgetItem(ui.DValue->text()));
	ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 5, new QTableWidgetItem(ui.EValue->text()));

    
    testExp[num] = Expression(ui.Expression->text(), ui.AValue->text(), ui.BValue->text(), ui.CValue->text(), ui.DValue->text(), ui.EValue->text());
    ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 6, new QTableWidgetItem(testExp[num].getInfixExpression()));
	
    num++;
}

QString MainWindow::DtoQStr(double num)
{
	QString str;
	str.setNum(num);
	return str;
}
void MainWindow::on_Calculate_clicked()
{
    for (int i = 0; i < ui.tableWidget->rowCount(); i++)
	{
		ui.tableWidget->setItem(i, 7, new QTableWidgetItem(DtoQStr(testExp[i].getResult())));
	}
}