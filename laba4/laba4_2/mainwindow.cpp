#include "mainwindow.h"
#include "StringLib.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

String QStringToMyString(QString str)
{
	String myStr;
	char* cStr = new char[str.size() + 1];
	MyString::strcpy(cStr, str.toStdString().c_str());
	myStr = cStr;
	return myStr;
}

QString MyStringToQString(String str)
{
	QString qStr;
	char* cStr = new char[str.length() + 1];
	MyString::strcpy(cStr, str.c_str());
	std::string sstr = cStr;
	qStr = QString::fromStdString(sstr);
	return qStr;
}

QString CharToQString(char* str)
{
	QString qStr;
	std::string sstr = str;
	qStr = QString::fromStdString(sstr);	
	return qStr;
}
char* MyStringToChar(String str)
{
	char* cStr = new char[str.length() + 1];
	MyString::strcpy(cStr, str.c_str());
	return cStr;
}

QString intToQString(int num)
{
	QString qStr;
	std::string sstr = std::to_string(num);
	qStr = QString::fromStdString(sstr);
	return qStr;
}
QString size_tToQString(size_t num)
{
	QString qStr;
	std::string sstr = std::to_string(num);
	qStr = QString::fromStdString(sstr);
	return qStr;
}


void MainWindow::on_pushButton_clicked()
{
	String str1 = QStringToMyString(ui.lineEdit->text());
	String str2 = QStringToMyString(ui.lineEdit_2->text());
	
	if (str1.length() < 4 || str2.length() < 4)
	{
		QMessageBox::warning(this, "Warning", "The string must be longer than 3 characters");
		return;
	}
	
	ui.Length->setText(size_tToQString(str1.length()));
	ui.Length2->setText(size_tToQString(MyString::strlen(MyStringToChar(str1)) - 1));
	
	char* cstr1 = MyStringToChar(str1), * cstr2 = MyStringToChar(str2);

	ui.strcat->setText(CharToQString(strcat(cstr1, cstr2)));
	if (strcmp(cstr1, cstr2) == 1)
		ui.strcmp->setText("0");
	else 
		ui.strcmp->setText("-1");
	ui.strncmp->setText(intToQString(strncmp(cstr1, cstr2, 3)));
	
}