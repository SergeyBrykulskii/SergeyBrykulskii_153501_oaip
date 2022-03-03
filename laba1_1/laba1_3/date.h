#pragma once

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QDateTime>
#include <QDate>
#include <QMessageBox>
#include <QTextStream>


class Date
{
public:
    Date(QString date = "", QString birthday = "");

    void setData(QString date, QString birthday);
    
    QString NextDay();
    QString PreviousDay();
    QString ReturnNumOfDays(int MonNum);

    int WeekNumber();

    int DaysTillYourBirthday();

    unsigned long long Duration(Date rhs);
    

    bool isLeapYear();

    bool isLeapYear(int year);
private:
    QString date, birthday;
    
};

