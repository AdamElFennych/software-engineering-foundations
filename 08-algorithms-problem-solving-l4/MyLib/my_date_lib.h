#pragma once
#pragma warning(disable : 4996)
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace MyDateLib
{
struct stDate
{
    short Year;
    short Month;
    short Day;
};
struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
};
enum enDateCompare
{
    Before = -1,
    Equal = 0,
    After = 1
};
// Forward declarations
bool isLeapYear(short Year);
short NumberOfDaysInAYear(short Year);
short NumberOfHoursInAYear(short Year);
int NumberOfMinutesInAYear(short Year);
int NumberOfSecondsInAYear(short Year);
short NumberOfDaysInAMonth(short Month, short Year);
short NumberOfHoursInAMonth(short Month, short Year);
int NumberOfMinutesInAMonth(short Month, short Year);
int NumberOfSecondsInAMonth(short Month, short Year);
short DayOfWeekOrder(short Day, short Month, short Year);
string DayShortName(short DayOfWeekOrder);
string MonthShortName(short MonthNumber);
void PrintMonthCalendar(short Month, short Year);
void PrintYearCalendar(int Year);
short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year);
stDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year);
stDate AddDaysToDate(stDate Date, int Days);
string NumberToText(int Number);
short ReadDay();
short ReadMonth();
short ReadYear();
stDate ReadFullDate();
bool IsLastDayInMonth(stDate Date);
bool IsLastMonthInYear(short Month);
bool IsDate1BeforeDate2(stDate Date1, stDate Date2);
bool IsDate1EqualDate2(stDate Date1, stDate Date2);
bool IsDate1AfterDate2(stDate Date1, stDate Date2);
void SwapDates(stDate& date1, stDate& date2);
int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false);
int GetDifferenceInDaysOptimized(stDate date1, stDate date2, bool EndDay = false);
stDate GetSystemDate();
stDate CorrectDateDay(stDate Date);
stDate IncreaseDateByOneDay(stDate Date);
stDate IncreaseDateByOneWeek(stDate Date);
stDate IncreaseDateByXWeeks(short Weeks, stDate Date);
stDate IncreaseDateByOneMonth(stDate Date);
stDate IncreaseDateByXDays(short Days, stDate Date);
stDate IncreaseDateByXMonths(short Months, stDate Date);
stDate IncreaseDateByOneYear(stDate Date);
stDate IncreaseDateByXYears(short Years, stDate Date);
stDate IncreaseDateByXYearsFaster(short Years, stDate Date);
stDate IncreaseDateByOneDecade(stDate Date);
stDate IncreaseDateByXDecades(short Decade, stDate Date);
stDate IncreaseDateByXDecadesFaster(short Decade, stDate Date);
stDate IncreaseDateByOneCentury(stDate Date);
stDate IncreaseDateByOneMillennium(stDate Date);
stDate DecreaseDateByOneDay(stDate Date);
stDate DecreaseDateByXDays(short Days, stDate Date);
stDate DecreaseDateByOneWeek(stDate Date);
stDate DecreaseDateByXWeeks(short Weeks, stDate Date);
stDate DecreaseDateByOneMonth(stDate Date);
stDate DecreaseDateByXMonths(short Months, stDate Date);
stDate DecreaseDateByOneYear(stDate Date);
stDate DecreaseDateByXYears(short Years, stDate Date);
stDate DecreaseDateByXYearsFaster(short Years, stDate Date);
stDate DecreaseDateByOneDecade(stDate Date);
stDate DecreaseDateByXDecades(short Decade, stDate Date);
stDate DecreaseDateByXDecadesFaster(short Decade, stDate Date);
stDate DecreaseDateByOneCentury(stDate Date);
stDate DecreaseDateByOneMillennium(stDate Date);
short DayOfWeekOrder(stDate Date);
bool IsEndOfWeek(stDate Date);
bool IsWeekEnd(stDate Date);
bool IsBusinessDay(stDate Date);
short DaysUntilTheEndOfWeek(stDate Date);
short DaysUntilTheEndOfMonth(stDate Date);
short DaysUntilTheEndOfYear(stDate Date);
short CalculateVacationDays(stDate DateFrom, stDate DateTo);
stDate CalculateVacationReturnDate(stDate startDate, int vacationDays);
enDateCompare CompareDates(stDate Date1, stDate Date2);
bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2);
stPeriod ReadPeriod();
int PeriodLengthInDays(stPeriod Period, bool IncludeEndDate = false);
bool isDateInPeriod(stDate Date, stPeriod Period);
int CountOverlapDays(stPeriod Period1, stPeriod Period2);
int CountOverlapDayOptimized(const MyDateLib::stPeriod& Period1, const MyDateLib::stPeriod& Period2);
bool IsValidDate(MyDateLib::stDate Date);
vector<string> SplitString(string S1, string Delim);
string DateToString(stDate Date);
stDate StringToDate(string DateString);
string ReadStringDate(string Message);
string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo);
string FormateDate(stDate Date, string DateFormat = "dd/mm/yyyy");
// Function implementations
bool isLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAYear(short Year)
{
    return isLeapYear(Year) ? 366 : 365;
}

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
    if (Month < 1 || Month > 12)
        return 0;

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
    // Gregorian:
    // 0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return arrDayNames[DayOfWeekOrder];
}

string MonthShortName(short MonthNumber)
{
    string Months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return (Months[MonthNumber - 1]);
}

void PrintMonthCalendar(short Month, short Year)
{
    int current = DayOfWeekOrder(1, Month, Year);
    int NumberOfDays = NumberOfDaysInAMonth(Month, Year);

    printf("\n _______________%s_______________\n\n", MonthShortName(Month).c_str());
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int i;
    for (i = 0; i < current; i++)
        printf("     ");

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
}

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
    short TotalDays = 0;
    for (int i = 1; i <= Month - 1; i++)
    {
        TotalDays += NumberOfDaysInAMonth(i, Year);
    }
    TotalDays += Day;
    return TotalDays;
}

stDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
{
    stDate Date;
    short RemainingDays = DateOrderInYear;
    short MonthDays = 0;
    Date.Year = Year;
    Date.Month = 1;

    while (true)
    {
        MonthDays = NumberOfDaysInAMonth(Date.Month, Year);
        if (RemainingDays <= MonthDays)
        {
            Date.Day = RemainingDays;
            break;
        }
        RemainingDays -= MonthDays;
        Date.Month++;
    }
    return Date;
}

stDate AddDaysToDate(stDate Date, int Days)
{
    short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
    short MonthDays = 0;
    Date.Month = 1;

    while (true)
    {
        MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}

string NumberToText(int Number)
{
    if (Number == 0)
        return "";

    if (Number >= 1 && Number <= 19)
    {
        string arr[] = {"",         "One",     "Two",     "Three",     "Four",     "Five",    "Six",
                        "Seven",    "Eight",   "Nine",    "Ten",       "Eleven",   "Twelve",  "Thirteen",
                        "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        return arr[Number] + " ";
    }

    if (Number >= 20 && Number <= 99)
    {
        string arr[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        return arr[Number / 10] + " " + NumberToText(Number % 10);
    }

    if (Number >= 100 && Number <= 199)
        return "One Hundred " + NumberToText(Number % 100);

    if (Number >= 200 && Number <= 999)
        return NumberToText(Number / 100) + "Hundred " + NumberToText(Number % 100);

    if (Number >= 1000 && Number <= 1999)
        return "One Thousand " + NumberToText(Number % 1000);

    if (Number >= 2000 && Number <= 999999)
        return NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);

    if (Number >= 1000000 && Number <= 1999999)
        return "One Million " + NumberToText(Number % 1000000);

    if (Number >= 2000000 && Number <= 999999999)
        return NumberToText(Number / 1000000) + "Million " + NumberToText(Number % 1000000);

    if (Number >= 1000000000 && Number <= 1999999999)
        return "One Billion " + NumberToText(Number % 1000000000);

    return NumberToText(Number / 1000000000) + "Billion " + NumberToText(Number % 1000000000);
}

short ReadDay()
{
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}
short ReadMonth()
{
    short Month;
    cout << "\nPlease enter a Month? ";
    cin >> Month;
    return Month;
}
short ReadYear()
{
    short Year;
    cout << "\nPlease enter a Year? ";
    cin >> Year;
    return Year;
}
stDate ReadFullDate()
{
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

bool IsLastDayInMonth(stDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}
bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year)
               ? true
               : ((Date1.Year == Date2.Year)
                      ? (Date1.Month < Date2.Month ? true
                                                   : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false))
                      : false);
}
bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year)
               ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false)
               : false;
}
bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

void SwapDates(MyDateLib::stDate& date1, MyDateLib::stDate& date2)
{
    MyDateLib::stDate temp = date1;
    date1 = date2;
    date2 = temp;
}
int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay)
{
    int Days = 0;
    short SawpFlagValue = 1;

    if (!IsDate1BeforeDate2(Date1, Date2))
    {
        // Swap Dates
        SwapDates(Date1, Date2);
        SawpFlagValue = -1;
    }

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
}
int GetDifferenceInDaysOptimized(MyDateLib::stDate date1, MyDateLib::stDate date2, bool EndDay)
{
    short SawpFlagValue = 1;
    if (!MyDateLib::IsDate1BeforeDate2(date1, date2))
    {
        SwapDates(date1, date2);
        short SawpFlagValue = -1;
    }
    short d1 = MyDateLib::NumberOfDaysFromTheBeginingOfTheYear(date1.Day, date1.Month, date1.Year);
    short d2 = MyDateLib::NumberOfDaysFromTheBeginingOfTheYear(date2.Day, date2.Month, date2.Year);
    short d3 = d2 - d1;
    int total_days = 0;
    while (date1.Year < date2.Year)
    {
        total_days += MyDateLib::NumberOfDaysInAYear(date1.Year);
        date1.Year++;
    }
    return (EndDay) ? (total_days + d3 + 1) * SawpFlagValue : (total_days + d3) * SawpFlagValue;
}

stDate GetSystemDate()
{
    stDate Date;
    time_t t = time(0);
    tm* now = localtime(&t);
    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;
    return Date;
}

stDate CorrectDateDay(stDate Date)
{
    short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > DaysInMonth)
    {
        Date.Day = DaysInMonth;
    }
    return Date;
}

stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
    for (int i = 1; i <= 7; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

stDate IncreaseDateByXWeeks(short Weeks, stDate Date)
{
    for (short i = 1; i <= Weeks; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}

stDate IncreaseDateByOneMonth(stDate Date)
{
    if (Date.Month == 12)
    {
        Date.Month = 1;
        Date.Year++;
    }
    else
    {
        Date.Month++;
    }

    return CorrectDateDay(Date);
}

stDate IncreaseDateByXDays(short Days, stDate Date)
{
    for (short i = 1; i <= Days; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

stDate IncreaseDateByXMonths(short Months, stDate Date)
{
    for (short i = 1; i <= Months; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
    Date.Year++;
    return CorrectDateDay(Date);
}

stDate IncreaseDateByXYears(short Years, stDate Date)
{
    for (short i = 1; i <= Years; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}

stDate IncreaseDateByXYearsFaster(short Years, stDate Date)
{
    Date.Year += Years;
    return CorrectDateDay(Date);
}

stDate IncreaseDateByOneDecade(stDate Date)
{
    Date.Year += 10;
    return CorrectDateDay(Date);
}

stDate IncreaseDateByXDecades(short Decade, stDate Date)
{
    for (short i = 1; i <= Decade * 10; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}

stDate IncreaseDateByXDecadesFaster(short Decade, stDate Date)
{
    Date.Year += Decade * 10;
    return CorrectDateDay(Date);
}

stDate IncreaseDateByOneCentury(stDate Date)
{
    Date.Year += 100;
    return CorrectDateDay(Date);
}

stDate IncreaseDateByOneMillennium(stDate Date)
{
    Date.Year += 1000;
    return CorrectDateDay(Date);
}

stDate DecreaseDateByOneDay(stDate Date)
{
    if (Date.Day == 1)
    {
        if (Date.Month == 1)
        {
            Date.Month = 12;
            Date.Day = 31;
            Date.Year--;
        }
        else
        {
            Date.Month--;
            Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
        }
    }
    else
    {
        Date.Day--;
    }
    return Date;
}

stDate DecreaseDateByXDays(short Days, stDate Date)
{
    for (short i = 1; i <= Days; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{
    for (int i = 1; i <= 7; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

stDate DecreaseDateByXWeeks(short Weeks, stDate Date)
{
    for (short i = 1; i <= Weeks; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
    if (Date.Month == 1)
    {
        Date.Month = 12;
        Date.Year--;
    }
    else
    {
        Date.Month--;
    }
    return CorrectDateDay(Date);
}

stDate DecreaseDateByXMonths(short Months, stDate Date)
{
    for (short i = 1; i <= Months; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
    Date.Year--;
    return CorrectDateDay(Date);
}

stDate DecreaseDateByXYears(short Years, stDate Date)
{
    for (short i = 1; i <= Years; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

stDate DecreaseDateByXYearsFaster(short Years, stDate Date)
{
    Date.Year -= Years;
    return CorrectDateDay(Date);
}

stDate DecreaseDateByOneDecade(stDate Date)
{
    Date.Year -= 10;
    return CorrectDateDay(Date);
}

stDate DecreaseDateByXDecades(short Decade, stDate Date)
{
    for (short i = 1; i <= Decade * 10; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

stDate DecreaseDateByXDecadesFaster(short Decade, stDate Date)
{
    Date.Year -= Decade * 10;
    return CorrectDateDay(Date);
}

stDate DecreaseDateByOneCentury(stDate Date)
{
    Date.Year -= 100;
    return CorrectDateDay(Date);
}

stDate DecreaseDateByOneMillennium(stDate Date)
{
    Date.Year -= 1000;
    return CorrectDateDay(Date);
}

short DayOfWeekOrder(stDate Date)
{
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

bool IsEndOfWeek(stDate Date)
{
    return DayOfWeekOrder(Date) == 6;
}

bool IsWeekEnd(stDate Date)
{
    // Weekends are Fri and Sat
    short DayIndex = DayOfWeekOrder(Date);
    return (DayIndex == 5 || DayIndex == 6);
}

bool IsBusinessDay(stDate Date)
{
    return !IsWeekEnd(Date);
}

short DaysUntilTheEndOfWeek(stDate Date)
{
    return 6 - DayOfWeekOrder(Date);
}

short DaysUntilTheEndOfMonth(stDate Date)
{
    stDate EndOfMonthDate;
    EndOfMonthDate.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
    EndOfMonthDate.Month = Date.Month;
    EndOfMonthDate.Year = Date.Year;
    return GetDifferenceInDaysOptimized(Date, EndOfMonthDate, true);
}

short DaysUntilTheEndOfYear(stDate Date)
{
    stDate EndOfYearDate;
    EndOfYearDate.Day = 31;
    EndOfYearDate.Month = 12;
    EndOfYearDate.Year = Date.Year;
    return GetDifferenceInDaysOptimized(Date, EndOfYearDate, true);
}
short CalculateVacationDays(stDate DateFrom, stDate DateTo)
{
    short DaysCount = 0;
    while (IsDate1BeforeDate2(DateFrom, DateTo))
    {
        if (IsBusinessDay(DateFrom))
            DaysCount++;
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }
    return DaysCount;
}
stDate CalculateVacationReturnDate(stDate startDate, int vacationDays)
{
    stDate returnDate = startDate;
    while (vacationDays > 0)
    {
        if (IsBusinessDay(returnDate))
        {
            vacationDays--;
        }
        returnDate = IncreaseDateByOneDay(returnDate);
    }
    while (!IsBusinessDay(returnDate))
    {
        returnDate = IncreaseDateByOneDay(returnDate);
    }
    return returnDate;
}
enDateCompare CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;
    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;

    return enDateCompare::After;
}
bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
{
    if (CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Before ||
        CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After)
        return false;
    else
        return true;
}
stPeriod ReadPeriod()
{
    stPeriod Period;
    cout << "\nEnter Start Date:\n";
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date:\n";
    Period.EndDate = ReadFullDate();
    return Period;
}
int PeriodLengthInDays(stPeriod Period, bool IncludeEndDate)
{
    return GetDifferenceInDaysOptimized(Period.StartDate, Period.EndDate, IncludeEndDate);
}
bool isDateInPeriod(stDate Date, stPeriod Period)
{
    return !(CompareDates(Date, Period.StartDate) == enDateCompare::Before ||
             CompareDates(Date, Period.EndDate) == enDateCompare::After);
}
int CountOverlapDays(stPeriod Period1, stPeriod Period2)
{
    int Period1Length = PeriodLengthInDays(Period1, true);
    int Period2Length = PeriodLengthInDays(Period2, true);
    int OverlapDays = 0;

    if (!IsOverlapPeriods(Period1, Period2))
        return 0;

    if (Period1Length < Period2Length)
    {
        while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
        {
            if (isDateInPeriod(Period1.StartDate, Period2))
                OverlapDays++;
            Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
        }
    }
    else
    {
        while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
        {
            if (isDateInPeriod(Period2.StartDate, Period1))
                OverlapDays++;
            Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
        }
    }
    return OverlapDays;
}
int CountOverlapDayOptimized(const MyDateLib::stPeriod& Period1, const MyDateLib::stPeriod& Period2)
{
    if (!MyDateLib::IsOverlapPeriods(Period1, Period2))
    {
        return 0;
    }
    int OverlapDays = 0;
    MyDateLib::stDate StartDate =
        (MyDateLib::CompareDates(Period1.StartDate, Period2.StartDate) == MyDateLib::enDateCompare::After)
            ? Period1.StartDate
            : Period2.StartDate;
    MyDateLib::stDate EndDate =
        (MyDateLib::CompareDates(Period1.EndDate, Period2.EndDate) == MyDateLib::enDateCompare::Before)
            ? Period1.EndDate
            : Period2.EndDate;
    OverlapDays = MyDateLib::GetDifferenceInDaysOptimized(StartDate, EndDate, true);
    return OverlapDays;
}
bool IsValidDate(MyDateLib::stDate Date)
{
    return (Date.Month > 0 && Date.Month < 13) &&
           (Date.Day > 0 && Date.Day <= MyDateLib::NumberOfDaysInAMonth(Date.Month, Date.Year));
}
vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable

    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }
    return vString;
}

string DateToString(stDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

stDate StringToDate(string DateString)
{
    stDate Date;
    vector<string> vDate;
    vDate = SplitString(DateString, "/");
    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);
    return Date;
}

string ReadStringDate(string Message)
{
    string DateString;
    cout << Message;
    getline(cin >> ws, DateString);
    return DateString;
}
string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
{
    short pos = S1.find(StringToReplace);
    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
        pos = S1.find(StringToReplace); // find next
    }
    return S1;
}
string FormateDate(stDate Date, string DateFormat)
{
    string FormattedDateString = "";
    FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));
    return FormattedDateString;
}
} // namespace MyDateLib
