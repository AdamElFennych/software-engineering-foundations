#pragma once
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

namespace MyDateLib
{
bool isLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAYear(short Year) { return isLeapYear(Year) ? 366 : 365; }

short NumberOfHoursInAYear(short Year)
{
    return NumberOfDaysInAYear(Year) * 24;
}

int NumberOfMinutesInAYear(short Year)
{
    return NumberOfHoursInAYear(Year) * 60;
}

int NumberOfSecondsInAYear(short Year)
{
    return NumberOfMinutesInAYear(Year) * 60;
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12) return 0;

    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

short NumberOfHoursInAMonth(short Month, short Year)
{
    return NumberOfDaysInAMonth(Month, Year) * 24;
}

int NumberOfMinutesInAMonth(short Month, short Year)
{
    return NumberOfHoursInAMonth(Month, Year) * 60;
}

int NumberOfSecondsInAMonth(short Month, short Year)
{
    return NumberOfMinutesInAMonth(Month, Year) * 60;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return arrDayNames[DayOfWeekOrder];
}

string MonthShortName(short MonthNumber)
{
    string Months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                         "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return (Months[MonthNumber - 1]);
}

void PrintMonthCalendar(short Month, short Year)
{
    int NumberOfDays;
    int current = DayOfWeekOrder(1, Month, Year);
    NumberOfDays = NumberOfDaysInAMonth(Month, Year);

    printf("\n _______________%s_______________\n\n",
           MonthShortName(Month).c_str());
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int i;
    for (i = 0; i < current; i++) printf("     ");

    for (int j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d", j);
        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }
    printf("\n _________________________________\n");
}

void PrintYearCalendar(int Year)
{
    printf("\n _________________________________\n\n");
    printf(" Calendar - %d\n", Year);
    printf(" _________________________________\n");
    for (int i = 1; i <= 12; i++)
    {
        PrintMonthCalendar(i, Year);
    }
    return;
}

string NumberToText(int Number)
{
    if (Number == 0)
    {
        return "";
    }

    if (Number >= 1 && Number <= 19)
    {
        string arr[] = {"",        "One",       "Two",      "Three",
                        "Four",    "Five",      "Six",      "Seven",
                        "Eight",   "Nine",      "Ten",      "Eleven",
                        "Twelve",  "Thirteen",  "Fourteen", "Fifteen",
                        "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        return arr[Number] + " ";
    }

    if (Number >= 20 && Number <= 99)
    {
        string arr[] = {"",      "",      "Twenty",  "Thirty", "Forty",
                        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        return arr[Number / 10] + " " + NumberToText(Number % 10);
    }

    if (Number >= 100 && Number <= 199)
    {
        return "One Hundred " + NumberToText(Number % 100);
    }

    if (Number >= 200 && Number <= 999)
    {
        return NumberToText(Number / 100) + "Hundreds " +
               NumberToText(Number % 100);
    }

    if (Number >= 1000 && Number <= 1999)
    {
        return "One Thousand " + NumberToText(Number % 1000);
    }

    if (Number >= 2000 && Number <= 999999)
    {
        return NumberToText(Number / 1000) + "Thousands " +
               NumberToText(Number % 1000);
    }

    if (Number >= 1000000 && Number <= 1999999)
    {
        return "One Million " + NumberToText(Number % 1000000);
    }

    if (Number >= 2000000 && Number <= 999999999)
    {
        return NumberToText(Number / 1000000) + "Millions " +
               NumberToText(Number % 1000000);
    }

    if (Number >= 1000000000 && Number <= 1999999999)
    {
        return "One Billion " + NumberToText(Number % 1000000000);
    }
    else
    {
        return NumberToText(Number / 1000000000) + "Billions " +
               NumberToText(Number % 1000000000);
    }
}
}  // namespace MyDateLib