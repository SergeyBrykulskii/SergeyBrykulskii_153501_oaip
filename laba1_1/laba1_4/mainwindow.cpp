#include "mainwindow.h"

QString FIRMS[4]{ "Intel", "HP", "MSI", "ASUS"};
QString TYPE[5]{ "Processor", "Motherboard", "RAM", "Disk drive", "Case"};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.radioButtonStock->setChecked(true);
    ui.tableWidget;

    
    ui.tableWidget->setRowCount(0);
    ui.tableWidget->setColumnCount(5);

    QStringList headers;
    headers.append("Firm");
    headers.append("Type");
    headers.append("Model");
    headers.append("Price");
    headers.append("Is in stock");
    

    ui.tableWidget->setHorizontalHeaderLabels(headers);

    isInStock = false;
    price = 0; lowPrice = 0; topPrice = 0;
    sizeOfArr = 2;
    numOfCP = 0; 
    itemOfCP = new ComputerParts[sizeOfArr];
    //itemOfCP = (ComputerParts*)malloc(sizeOfArr * sizeof(ComputerParts));
}

MainWindow::~MainWindow()
{
    delete[] itemOfCP;
}
void MainWindow::on_OpenFile_clicked()
{
    FilePath = QFileDialog::getOpenFileName(this, "Choose file", "C:/", "(*.txt);");

    QFile file(FilePath);

    file.open(QFile::ReadOnly);
    
    QTextStream fin(&file);
    QString checkData = fin.readLine();
    fin.seek(0);
    file.close();

    numOfCP = 0;
    
    if (checkData != "Intel" && checkData != "HP" && checkData != "ASUS")
    {
        FilePath = "";
        QMessageBox::critical(this, "Warning", "Please, choose correct file");
    }
    else
    {
        file.open(QFile::ReadOnly);
        firm = fin.readLine();

        while (!firm.isEmpty())
        {

            type = fin.readLine();
            model = fin.readLine();
            price = fin.readLine().toDouble();
            isInStock = fin.readLine().toInt();

            itemOfCP[numOfCP] =  ComputerParts(firm, type, model, price, isInStock);
         
            if (numOfCP == sizeOfArr - 1)
            {
               //itemOfCP = (ComputerParts*)realloc(itemOfCP, (sizeOfArr *= 2) * sizeof(ComputerParts));
                ComputerParts* newItemOfCP = new ComputerParts[sizeOfArr];

                for (int i = 0; i <= numOfCP; i++)
                {
                    newItemOfCP[i] = itemOfCP[i];
                }
                delete[] itemOfCP;

                sizeOfArr *= 2;
                itemOfCP = new ComputerParts[sizeOfArr];

                for (int i = 0; i <= numOfCP; i++)
                {
                    itemOfCP[i] = newItemOfCP[i];
                }
                delete[] newItemOfCP;
            }
            
            numOfCP++;

            firm = fin.readLine();
        }
        firm = "";
        type = "";
        model = "";
        price = 0;
        isInStock = 0;

        fin.seek(0);
        file.close();
    }
}

void MainWindow::on_ShowInfo_clicked()
{
    if (FilePath == "")
    {
        QMessageBox::critical(this, "Warning", "Please, choose correct file");
    }
    else
    {
        int num = ui.tableWidget->rowCount();
        for (int i = 0; i < num; i++)
        {
            ui.tableWidget->removeRow(0);
        }

        for (int i = 0; i < numOfCP; i++)
        {
            ui.tableWidget->insertRow(ui.tableWidget->rowCount());
            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 0, new QTableWidgetItem(itemOfCP[i].returnFirm()));
            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 1, new QTableWidgetItem(itemOfCP[i].returnType()));
            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 2, new QTableWidgetItem(itemOfCP[i].returnModel()));
            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 3, new QTableWidgetItem(itemOfCP[i].returnPrice()));
            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 4, new QTableWidgetItem(itemOfCP[i].returnIsInStock()));
        }
    }
}

void MainWindow::on_Add_clicked()
{
    if(FilePath.isEmpty())
        QMessageBox::critical(this, "Warning", "Please, choose file");

    if(firm.isEmpty())
        QMessageBox::critical(this, "Warning", "Please, choose firm");

    if(type.isEmpty())
        QMessageBox::critical(this, "Warning", "Please, choose type");

    QString checker;
    checker = ui.lineEditModel->text();

    QRegularExpression expr("^\\S{1,5}\$");
    QRegularExpressionMatch match = expr.match(checker);

    if (!match.hasMatch())
        QMessageBox::critical(this, "Warning", "Please, write right model(5 symbols)");
    else
        model = checker;

    checker = ui.lineEditPrice->text();

    QRegularExpression expr2("^[-+]?[0-9]{1,4}[.,]?[0-9]{0,2}(?:[eE][-+]?[0-9]{0,2})?$");
     match = expr2.match(checker);

    if (!match.hasMatch())
        QMessageBox::critical(this, "Warning", "Please, write right price");
    else
        price = checker.toDouble();

    if (price == 0)
    {
        QMessageBox::critical(this, "Warning", "Please, write right price");
    }
    if (!firm.isEmpty() && !type.isEmpty() && !model.isEmpty() && price != 0 && !FilePath.isEmpty())
    {
        itemOfCP[numOfCP] = ComputerParts(firm, type, model, price, isInStock);

        if (numOfCP == sizeOfArr - 1)
        {
            //itemOfCP = (ComputerParts*)realloc(itemOfCP, (sizeOfArr *= 2) * sizeof(ComputerParts));
            ComputerParts* newItemOfCP = new ComputerParts[sizeOfArr];

            for (int i = 0; i <= numOfCP; i++)
            {
                newItemOfCP[i] = itemOfCP[i];
            }
            delete[] itemOfCP;

            sizeOfArr *= 2;
            itemOfCP = new ComputerParts[sizeOfArr];

            for (int i = 0; i <= numOfCP; i++)
            {
                itemOfCP[i] = newItemOfCP[i];
            }
            delete[] newItemOfCP;
        }

        numOfCP++;

        QFile file(FilePath);

        file.open(QFile::Append);

        QTextStream fout(&file);
        
        fout << "\n" << firm << "\n" << type << "\n" << model << "\n" << price << "\n" << isInStock;

        file.close();

        ui.lineEditModel->setText("");
        ui.lineEditPrice->setText("");
        
    }

    firm = "";
    type = "";
    model = "";
    price = 0;
    isInStock = 0;
}

void MainWindow::on_Exit_clicked()
{
    close();
}

void MainWindow::on_comboBoxFirm_activated(int index)
{
    switch (index) {
    case 0: firm = "Intel";
        break;
    case 1: firm = "HP";
        break;
    case 2: firm = "ASUS";
    }
}

void MainWindow::on_comboBoxType_activated(int index)
{
    switch (index) {
    case 0: type = "Processor";
        break;
    case 1: type = "Motherboard";
        break;
    case 2: type = "Case";
    }
}

void MainWindow::on_radioButtonStock_clicked(bool checked)
{
    if (checked) isInStock = true;
}


void MainWindow::on_radioButtonNStock_clicked(bool checked)
{
    if (checked) isInStock = false;
}

void MainWindow::on_Search_clicked()
{
    if (FilePath.isEmpty())
        QMessageBox::critical(this, "Warning", "Please, choose file");
    else 
    {
        QString checker;
        checker = ui.lineEditModel->text();

        QRegularExpression expr("^\\S{0,5}\$");
        QRegularExpressionMatch match = expr.match(checker);

        if (!match.hasMatch())
            QMessageBox::critical(this, "Warning", "Please, write right model(5 symbols)");
        else
            model = checker;

        if (firm.isEmpty() && type.isEmpty() && model.isEmpty())
        {
            QMessageBox::critical(this, "Warning", "Please, write one of the characteristics\n(firm, type or model)");
        }
        else
        {
            int num = ui.tableWidget->rowCount();
            for (int i = 0; i < num; i++)
            {
                ui.tableWidget->removeRow(0);
            }
            if (!firm.isEmpty())
            {
                for (int i = 0; i < numOfCP; i++)
                {
                    if (firm == itemOfCP[i].returnFirm())
                    {
                        ui.tableWidget->insertRow(ui.tableWidget->rowCount());
                        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 0, new QTableWidgetItem(itemOfCP[i].returnFirm()));
                        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 1, new QTableWidgetItem(itemOfCP[i].returnType()));
                        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 2, new QTableWidgetItem(itemOfCP[i].returnModel()));
                        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 3, new QTableWidgetItem(itemOfCP[i].returnPrice()));
                        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 4, new QTableWidgetItem(itemOfCP[i].returnIsInStock()));
                    }
                }
            }

            if (!type.isEmpty())
            {
                for (int i = 0; i < numOfCP; i++)
                {
                    if (type == itemOfCP[i].returnType())
                    {
                        ui.tableWidget->insertRow(ui.tableWidget->rowCount());
                        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 0, new QTableWidgetItem(itemOfCP[i].returnFirm()));
                        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 1, new QTableWidgetItem(itemOfCP[i].returnType()));
                        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 2, new QTableWidgetItem(itemOfCP[i].returnModel()));
                        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 3, new QTableWidgetItem(itemOfCP[i].returnPrice()));
                        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 4, new QTableWidgetItem(itemOfCP[i].returnIsInStock()));
                    }
                }
            }

            if (!model.isEmpty())
            {
                for (int i = 0; i < numOfCP; i++)
                {
                    if (model == itemOfCP[i].returnModel())
                    {
                        ui.tableWidget->insertRow(ui.tableWidget->rowCount());
                        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 0, new QTableWidgetItem(itemOfCP[i].returnFirm()));
                        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 1, new QTableWidgetItem(itemOfCP[i].returnType()));
                        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 2, new QTableWidgetItem(itemOfCP[i].returnModel()));
                        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 3, new QTableWidgetItem(itemOfCP[i].returnPrice()));
                        ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 4, new QTableWidgetItem(itemOfCP[i].returnIsInStock()));
                    }
                }
                ui.lineEditModel->setText("");
            }
        }
    }
    firm = "";
    type = "";
    model = "";
}

void MainWindow::Sort()
{
    if (FilePath.isEmpty())
        QMessageBox::critical(this, "Warning", "Please, choose file");
    else
    {
        int t1 = 0, t2 = 0, t3 = 0;
        for (int i = 0; i <= numOfCP; i++)
        {
            if (itemOfCP[i].returnType() == "Processor")
                t1++;

            if (itemOfCP[i].returnType() == "Motherboard")
                t2++;

            if (itemOfCP[i].returnType() == "Case")
                t3++;
        }

        ComputerParts* sort1 = new ComputerParts[t1];
        ComputerParts* sort2 = new ComputerParts[t2];
        ComputerParts* sort3 = new ComputerParts[t3];

        int j = 0, z = 0, k = 0;
        for (int i = 0; i < numOfCP; i++)
        {
            if (itemOfCP[i].returnType() == "Processor")
                sort1[j++] = itemOfCP[i];
            else if (itemOfCP[i].returnType() == "Motherboard")
                sort2[z++] = itemOfCP[i];
            else if (itemOfCP[i].returnType() == "Case")
                sort3[k++] = itemOfCP[i];
        }

        ComputerParts temp;
        for (int i = 0; i < t1 - 1; i++)
        {
            for (int j = i + 1; j < t1; j++)
            {
                if (sort1[i].returnPrice().toDouble() < sort1[j].returnPrice().toDouble())
                {
                    temp = sort1[i];
                    sort1[i] = sort1[j];
                    sort1[j] = temp;
                }
            }
        }
        for (int i = 0; i < t2 - 1; i++)
        {
            for (int j = i + 1; j < t2; j++)
            {
                if (sort2[i].returnPrice().toDouble() < sort2[j].returnPrice().toDouble())
                {
                    temp = sort2[i];
                    sort2[i] = sort2[j];
                    sort2[j] = temp;
                }
            }
        }
        for (int i = 0; i < t3 - 1; i++)
        {
            for (int j = i + 1; j < t3; j++)
            {
                if (sort3[i].returnPrice().toDouble() < sort3[j].returnPrice().toDouble())
                {
                    temp = sort3[i];
                    sort3[i] = sort3[j];
                    sort3[j] = temp;
                }
            }
        }

        for (int i = 0; i < t1; i++)
        {
            itemOfCP[i] = sort1[i];
        }
        for (int i = t1, j = 0; j < t2; i++, j++)
        {
            itemOfCP[i] = sort2[j];
        }
        for (int i = t1 + t2, j = 0; j < t3; i++, j++)
        {
            itemOfCP[i] = sort3[j];
        }

        delete[] sort1;
        delete[] sort2;
        delete[] sort3;
    }
}

void MainWindow::on_Sort_clicked()
{
    Sort();
}


void MainWindow::on_Equipment_clicked()
{

    if (FilePath.isEmpty())
        QMessageBox::critical(this, "Warning", "Please, choose file");
    else
    {
        QString checker;
        checker = ui.Low->text();

        QRegularExpression expr("^[-+]?[0-9]{1,4}[.,]?[0-9]{0,2}(?:[eE][-+]?[0-9]{0,2})?$");
        QRegularExpressionMatch match = expr.match(checker);

        if (!match.hasMatch())
            QMessageBox::critical(this, "Warning", "Please, write right low price");
        else
            lowPrice = checker.toDouble();
        

        checker = ui.Top->text();

        match = expr.match(checker);

        if (!match.hasMatch())
            QMessageBox::critical(this, "Warning", "Please, write right top price");
        else
            topPrice = checker.toDouble();

        if (topPrice != 0)
        {
            Sort();

            int t1 = 0, t2 = 0, t3 = 0;
            for (int i = 0; i <= numOfCP; i++)
            {
                if (itemOfCP[i].returnType() == "Processor")
                    t1++;

                if (itemOfCP[i].returnType() == "Motherboard")
                    t2++;

                if (itemOfCP[i].returnType() == "Case")
                    t3++;
            }

            ComputerParts* sort1 = new ComputerParts[t1];
            ComputerParts* sort2 = new ComputerParts[t2];
            ComputerParts* sort3 = new ComputerParts[t3];

            int nj = 0, nz = 0, nk = 0;
            for (int i = 0; i < numOfCP; i++)
            {
                if (itemOfCP[i].returnType() == "Processor")
                    sort1[nj++] = itemOfCP[i];
                else if (itemOfCP[i].returnType() == "Motherboard")
                    sort2[nz++] = itemOfCP[i];
                else if (itemOfCP[i].returnType() == "Case")
                    sort3[nk++] = itemOfCP[i];
            }

            int num = ui.tableWidget->rowCount();
            for (int i = 0; i < num; i++)
            {
                ui.tableWidget->removeRow(0);
            }

            for (int i = 0; i < t1; i++)
            {
                for (int j = 0; j < t2; j++)
                {
                    for (int k = 0; k < t3; k++)
                    {
                        if (lowPrice < sort1[i].returnPrice().toDouble() + sort2[j].returnPrice().toDouble() + sort3[k].returnPrice().toDouble()
                            && sort1[i].returnPrice().toDouble() + sort2[j].returnPrice().toDouble() + sort3[k].returnPrice().toDouble() < topPrice)
                        {
                            ui.tableWidget->insertRow(ui.tableWidget->rowCount());
                            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 0, new QTableWidgetItem(sort1[i].returnFirm()));
                            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 1, new QTableWidgetItem(sort1[i].returnType()));
                            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 2, new QTableWidgetItem(sort1[i].returnModel()));
                            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 3, new QTableWidgetItem(sort1[i].returnPrice()));
                            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 4, new QTableWidgetItem(sort1[i].returnIsInStock()));

                            ui.tableWidget->insertRow(ui.tableWidget->rowCount());
                            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 0, new QTableWidgetItem(sort2[j].returnFirm()));
                            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 1, new QTableWidgetItem(sort2[j].returnType()));
                            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 2, new QTableWidgetItem(sort2[j].returnModel()));
                            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 3, new QTableWidgetItem(sort2[j].returnPrice()));
                            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 4, new QTableWidgetItem(sort2[j].returnIsInStock()));

                            ui.tableWidget->insertRow(ui.tableWidget->rowCount());
                            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 0, new QTableWidgetItem(sort3[k].returnFirm()));
                            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 1, new QTableWidgetItem(sort3[k].returnType()));
                            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 2, new QTableWidgetItem(sort3[k].returnModel()));
                            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 3, new QTableWidgetItem(sort3[k].returnPrice()));
                            ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 4, new QTableWidgetItem(sort3[k].returnIsInStock()));

                            ui.tableWidget->insertRow(ui.tableWidget->rowCount());
                        }
                    }
                }
            }
        }
    }
}

