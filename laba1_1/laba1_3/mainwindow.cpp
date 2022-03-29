#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.tableWidget->setRowCount(5);
    ui.tableWidget->setColumnCount(8);

    QStringList headers;
    headers.append("Date");
    headers.append("Difference between\n current and next");
    headers.append("Next day");
    headers.append("Previous day");
    headers.append("Number of week");
    headers.append("Leap year(yes/no)");
    headers.append("Till your bithday");
    headers.append("Duration");

    ui.tableWidget->setHorizontalHeaderLabels(headers);

    flag = 0;
    flag1 = 0;
}

void MainWindow::on_ChooseFile_clicked()
{
    FilePath = QFileDialog::getOpenFileName(this, "Выберите файл", "C:/", "(*.txt);");
    QFile file(FilePath);

    QRegularExpression expr1("^(((0[1-9]|[12][0-9]|3[01]).((0[13578]|1[02]))|((0[1-9]|[12][0-9]|30).(0[469]|11))|(0[1-9]|[1][0-9]|2[0-8]).(02)).([0-9]{3}[1-9]|[0-9]{2}[1-9][0-9]{1}|[0-9]{1}[1-9][0-9]{2}|[1-9][0-9]{3}))|(29.02.(([0-9]{2})(0[48]|[2468][048]|[13579][26])|((0[48]|[2468][048]|[3579][26])00)))$");


    //QRegularExpressionMatch match = expr.match(Birthday);
    QRegularExpressionMatch match1;
    file.open(QFile::ReadOnly);
    QTextStream fin(&file);
    QString s;
    while ((s = fin.readLine()) != "")
    {
        match1 = expr1.match(fin.readLine());

        if (!match1.hasMatch())
        {
            QMessageBox::critical(this, "Warning", "Please, choose correct file");
            flag1 = 1;
            break;
        }
        else
        {
            flag1 = 0;
        }
    }
}

void MainWindow::makeTable()
{
    Date* dates = new Date[20];

    QFile file(FilePath);

    file.open(QFile::ReadOnly);

    QTextStream fin(&file);
    QString data;

    for (int i = 1; i < ui.tableWidget->rowCount(); ++i) {
        data = fin.readLine();

        dates[i - 1].setData(data, Birthday);

        ui.tableWidget->setItem(i, 0, new QTableWidgetItem(data));
        data = "";
    }

    for (int i = 1; i < ui.tableWidget->rowCount(); ++i)
        for (int j = 1; j < ui.tableWidget->columnCount(); ++j) {
            data = "";

            if (j == 1) {
                if (i == ui.tableWidget->rowCount()) data = QString::number(dates[i - 1].Duration(dates[0]));
                else data = QString::number(dates[i - 1].Duration(dates[i]));
            }

            else if (j == 2) {
                data = dates[i - 1].NextDay();
            }

            else if (j == 3)
                data = dates[i - 1].PreviousDay();

            else if (j == 4)
                data = QString::number(dates[i - 1].WeekNumber());
            
            else if (j == 5) {
                data = "Yes";
                if (!dates[i - 1].isLeapYear())
                    data = "No";
            }

            else if (j == 6)
                data = QString::number(dates[i - 1].DaysTillYourBirthday());

            else if (j == 7)
                data = QString::number(dates[i - 1].Duration(Date("15.03.2021")));
            
            ui.tableWidget->setItem(i, j, new QTableWidgetItem(data));
        }
}

void MainWindow::on_add_clicked()
{
    Birthday = ui.lineEdit->text();

    //QRegularExpression expr("^\[0-3][0-9]\\.0[0-9]\\.\\d{4}\$");
    
    
    //QRegularExpression expr1("^\[0-3][0-9]\\.\[0-1][0-9]\\.\\d{4}\$");
    QRegularExpression expr1("^(((0[1-9]|[12][0-9]|3[01]).((0[13578]|1[02]))|((0[1-9]|[12][0-9]|30).(0[469]|11))|(0[1-9]|[1][0-9]|2[0-8]).(02)).([0-9]{3}[1-9]|[0-9]{2}[1-9][0-9]{1}|[0-9]{1}[1-9][0-9]{2}|[1-9][0-9]{3}))|(29.02.(([0-9]{2})(0[48]|[2468][048]|[13579][26])|((0[48]|[2468][048]|[3579][26])00)))$");
    
    
    //QRegularExpressionMatch match = expr.match(Birthday);
    QRegularExpressionMatch match1 = expr1.match(Birthday);

    if (/*!match.hasMatch() ||*/ !match1.hasMatch())
        QMessageBox::critical(this, "Warning", "Please, write right date\n**.**.****");
    else if (FilePath.isEmpty())
        QMessageBox::critical(this, "Warning", "Please, choose file");
    else {
       
        
        if (!flag1)
        {
            flag = 1;
            makeTable();
        }
    }
}

void MainWindow::on_ChangeData_clicked()
{
    if (flag == 0)
    {
        QMessageBox::critical(this, "Warning", "Please, add birthday");

    }
    else
    {
        QString newDate = ui.lineEdit_2->text();

        QRegularExpression expr("^(((0[1-9]|[12][0-9]|3[01]).((0[13578]|1[02]))|((0[1-9]|[12][0-9]|30).(0[469]|11))|(0[1-9]|[1][0-9]|2[0-8]).(02)).([0-9]{3}[1-9]|[0-9]{2}[1-9][0-9]{1}|[0-9]{1}[1-9][0-9]{2}|[1-9][0-9]{3}))|(29.02.(([0-9]{2})(0[48]|[2468][048]|[13579][26])|((0[48]|[2468][048]|[3579][26])00)))$");
        //QRegularExpression expr("^\[0-3][0-3]\\.\[0-1][0-2]\\.\\d{4}\$");
        QRegularExpressionMatch match2 = expr.match(newDate);

        if (!match2.hasMatch())
            QMessageBox::critical(this, "Warning", "Please, write right date\n**.**.****");
        else if (FilePath.isEmpty())
            QMessageBox::critical(this, "Warning", "Please, choose file");
        else {
            QFile file(FilePath);
        
            file.seek(0);
            file.open(QFile::ReadOnly);
            QTextStream fin(&file);

            match2 = expr.match(fin.readLine());

            if (!match2.hasMatch())
                QMessageBox::critical(this, "Warning", "Please, choose file");
            else
            {
                QFile newFile(FilePath);
                newFile.open(QFile::Append);

                QTextStream fout(&newFile);

                fout << '\n' << newDate;


                ui.tableWidget->insertRow(ui.tableWidget->rowCount());
                makeTable();
            
            }
        }
    }
}