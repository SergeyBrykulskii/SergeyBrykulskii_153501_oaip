#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

void MainWindow::func()
{
    int n = ui.lineEdit->text().toInt();

    if (n > 10000 || n < 1)
    {
        QMessageBox::warning(this, "Warning", "Incorrect input");
        return;
    }

    std::string* A = new std::string[10000];
    std::string* B = new std::string[10000];
    A[0] = "0";
    int counterB, counterA = 1, k = 1, counterBIN = 1, tmp;

    while (n >= counterBIN)
    {
        tmp = counterB = 0;
        for (int i = 0; i < counterA; ++i)
        {
            if (!k_bit(A[i], k))
            {
                A[tmp] = A[i];
                ++tmp;
            }
        }
        counterA = tmp;
        for (int i = 0; i < counterA; ++i)
        {
            B[i] = powstr(A[i], k - 1);
            ++counterB;
        }
        for (int i = 0; i < counterB; ++i)
        {
            A[counterA] = B[i];
            ++counterA;
        }
        counterBIN += counterB;
        ++k;
    }

    ui.textBrowser->setText(B[counterB - (counterBIN - n)].c_str());

    delete[] A;
    delete[] B;
}

bool MainWindow::k_bit(std::string str, const int& k)
{
    int bit, i = 0;
    int lenstr = str.length();
    for (; i != (k); ++i)
    {
        bit = (str[lenstr - 1] - '0') % 2;
        str[lenstr - 1] = str[lenstr - 1] - bit;
        for (int j = lenstr - 1; j >= 0; --j)
        {
            if ((str[j] - '0') % 2 == 0)
            {
                str[j] = (str[j] - '0') / 2 + '0';
            }
            else
            {
                str[j] = (str[j] - '0') / 2 + '0';
                if (j != lenstr - 1)
                {
                    str[j + 1] = str[j + 1] + 5;
                }
            }
        }
    }
    return(bit);
}

std::string deg = "1";

std::string MainWindow::powstr(const std::string& str, const int& k)
{
    deg = "1";
    if (k == 0)
    {
        return std::move(deg);
    }
    for (int i = 0; i < k; ++i)
    {
        deg += '0';
    }
    for (int i = deg.length() - 1, j = str.length() - 1; i >= 0 && j >= 0; --i, --j)
    {
        deg[i] = str[j];
    }
    return(std::move(deg));
}

void MainWindow::on_pushButton_clicked()
{   
    func();  
}