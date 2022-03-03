#include "date.h"

Date::Date(QString date, QString birthday) {
    this->date = date;
    this->birthday = birthday;
}

void Date::setData(QString date, QString birthday) {
    this->date = date;
    this->birthday = birthday;
}

bool Date::isLeapYear() {
    QString TempDate = date;
    TempDate.remove(0, 6);
    if (TempDate[0] == '0') TempDate.remove(0, 1);

    int year = TempDate.toInt();

    if (!(year % 4)) {
        if (!(year % 100)) {
            if (!(year % 400))
                return true;
        }
        else return true;
    }
    else return false;
}

// Check Leep Year
bool Date::isLeapYear(int year) {
    if (!(year % 4)) {
        if (!(year % 100)) {
            if (!(year % 400))
                return true;
        }
        else return true;
    }
    else return false;
}

// Return number of days in the month
QString Date::ReturnNumOfDays(int MonNum) {
    if (MonNum != 2)
    {
        if (MonNum == 4 || MonNum == 6 || MonNum == 9 || MonNum == 11)
            return "30";
        else 
            return "31";
    }
    else
    {
        if (isLeapYear()) return "29";
        else return "28";
    }
}

QString Date::NextDay() {
    QString day = date;
    day.remove(2, 8);
    if (day[0] == '0')
        day.remove(0, 1);

    QString month = date;
    month.remove(0, 3);
    month.remove(2, 5);

    if (month[0] == '0') 
        month.remove(0, 1);

    QString year = date;
    year.remove(0, 6);

    while (year[0] == '0')
        year.remove(0, 1);

    if (ReturnNumOfDays(month.toInt()) < "30") {
        if ((day == "29") || (day == "28" && !isLeapYear()))
            return QString("01.03." + year);
        else if (day == "28" && isLeapYear()) 
            return QString("29.02" + year);
        else 
            return QString(QString::number(day.toInt() + 1) + ".02." + year);
    }

    if (day == "31" && month == "12") 
        return QString("01.01." + QString::number(year.toInt() + 1));
    else if ((ReturnNumOfDays(month.toInt()) == "30" && day == "30") || (day == "31"))
        return QString("01." + QString::number(month.toInt() + 1) + "." + year);
    
    return QString(QString::number(day.toInt() + 1) + "." + month + "." + year);
}

QString Date::PreviousDay() {
    QString day = date;
    day.remove(2, 8);
    if (day[0] == '0') day.remove(0, 1);

    QString month = date;
    month.remove(0, 3);
    month.remove(2, 5);
    if (month[0] == '0') month.remove(0, 1);

    QString year = date;
    year.remove(0, 6);
    while (year[0] == '0')
        year.remove(0, 1);

    if (day == "1") {
        if (month == "1") 
            return QString("31.12." + QString::number(year.toInt() - 1));
        else 
            return QString(ReturnNumOfDays((month.toInt() - 1)) + "." + QString::number(month.toInt() - 1) + "." + year);
    }
    else return QString(QString::number(day.toInt() - 1) + "." + month + "." + year);
}


int Date::WeekNumber() {
    QString day = date;
    day.remove(2, 8);
    if (day[0] == '0') 
        day.remove(0, 1);


    return (day.toInt() + 6) / 7;;

}

int Date::DaysTillYourBirthday() {

    QString month = date;
    month.remove(0, 3); month.remove(2, 5);
    if (month[0] == '0') month.remove(0, 1);

    QString day = date;
    day.remove(2, 8);
    if (day[0] == '0') day.remove(0, 1);

    QString bdayMonth = birthday;
    bdayMonth.remove(0, 3); 
    bdayMonth.remove(2, 5);

    if (bdayMonth[0] == '0') 
        bdayMonth.remove(0, 1);

    QString bdayDay = birthday;
    bdayDay.remove(2, 8);

    if (bdayDay[0] == '0') 
        bdayDay.remove(0, 1);

    int Month = 0, daysInputDate = 0;

    while (Month++ != month.toInt())
    {
        daysInputDate += ReturnNumOfDays(Month).toInt();
    }
    
    int daysBday = 0;
    for (Month = 0; Month != bdayMonth.toInt(); ++Month)
        daysBday += ReturnNumOfDays(Month).toInt();

    daysBday += bdayDay.toInt();
    daysInputDate += day.toInt();

    int days = daysBday - daysInputDate;

    if (days < 0) 
        days = 365 + days;

    return days;
}

unsigned long long Date::Duration(Date rhs) {

    QString year = date;
    year.remove(0, 6);
    while (year[0] == '0')
        year.remove(0, 1);

    QString month = date;
    month.remove(0, 3); month.remove(2, 5);
    if (month[0] == '0') month.remove(0, 1);

    QString day = date;
    day.remove(2, 8);
    if (day[0] == '0') day.remove(0, 1);

    long long Days = 0;
    int Year = 0;

    while (Year++ != year.toInt())
    {
        if (isLeapYear(Year)) Days += 366;
        else Days += 365;
    }

    int Month = 0;

    while (Month++ != month.toInt())
    {
        Days += ReturnNumOfDays(Month).toInt();
    }

    Days += day.toInt();

    QString Rhsmonth = rhs.date;
    Rhsmonth.remove(0, 3); Rhsmonth.remove(2, 5);
    if (Rhsmonth[0] == '0') Rhsmonth.remove(0, 1);

    QString Rhsday = rhs.date;
    Rhsday.remove(2, 8);
    if (Rhsday[0] == '0') Rhsday.remove(0, 1);

    QString Rhsyear = rhs.date;
    Rhsyear.remove(0, 6);
    while (Rhsyear[0] == '0')
        Rhsyear.remove(0, 1);

    unsigned long long NextDateYear = 0;
    int NextYear = 0;
    for (NextYear = 0; NextYear != Rhsyear.toInt(); ++NextYear) {
        if (isLeapYear(NextYear)) NextDateYear += 366;
        else NextDateYear += 365;
    }

    for (Month = 0; Month != Rhsmonth.toInt(); ++Month)
        NextDateYear += ReturnNumOfDays(Month).toInt();

    NextDateYear += Rhsday.toInt();

    unsigned long long duretion = NextDateYear - Days;
    if (NextDateYear < Days)
        duretion = Days - NextDateYear;
    
    return duretion;
}