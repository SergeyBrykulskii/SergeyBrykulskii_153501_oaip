#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

void MainWindow::on_File_clicked()
{
    FilePath = QFileDialog::getOpenFileName(this, "Choose file whis brackets", "C:/", "(*.txt);");

    QFile file(FilePath);

    file.open(QFile::ReadOnly);
    QTextStream fin(&file);
    ui.textEdit->setText(fin.readAll());
    file.close();
}

void MainWindow::on_Checker_clicked()
{
    MyStack<QChar> CheckerForBrackets(5000);
    QString textFromEdit = ui.textEdit->toPlainText();

    if (textFromEdit == "")
    {
        QMessageBox::critical(&msgBox, "Warning", "Empty text!\nPlease write something");
        return;
    }

    ushort x = 0, y = 1;
    for (auto ch : textFromEdit)
    {
        if (ch == "\n")
        {
            y++;
            x = 0;
        }
        x++;
        if (ch == '(' || ch == '[' || ch == '{')
        {
            CheckerForBrackets.push(ch, x, y);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (CheckerForBrackets.getTop() == 0)
            {
                QMessageBox::critical(&msgBox, "Error", "Extra closing bracket at position\ny: " + QString::number(y) + "  x:  " + QString::number(x));
                return;
            }
            
            QChar prevCh = CheckerForBrackets.pop();
            if (ch == ')' && prevCh != '(')
            {
                QMessageBox::critical(&msgBox, "Error", "Extra closing bracket at position\ny: " + QString::number(y) + "  x:  " + QString::number(x));
                return;
            }
            
            if (ch == ']' && prevCh != '[')
            {
                QMessageBox::critical(&msgBox, "Error", "Extra closing bracket at position\ny: " + QString::number(y) + "  x:  " + QString::number(x));
                return;
            }
            
            if (ch == '}' && prevCh != '{')
            {
                QMessageBox::critical(&msgBox, "Error", "Extra closing bracket at position\ny: " + QString::number(y) + "  x:  " + QString::number(x));
                return;
            }
        }
    }

    if (CheckerForBrackets.getTop() == 0)
        QMessageBox::information(&msgBox, "Success", "Success");
    else
    {
        x = CheckerForBrackets.getPos()[0].getPosX();
        y = CheckerForBrackets.getPos()[0].getPosY();
        QMessageBox::critical(&msgBox, "Error", "Extra opening bracket at position\ny: " + QString::number(y) + "  x:  " + QString::number(x));

    }
    
}
  