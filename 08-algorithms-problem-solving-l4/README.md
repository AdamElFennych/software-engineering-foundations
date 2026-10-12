# Algorithms & Problem Solving - Level 4

[![C++](https://img.shields.io/badge/C++-17-blue.svg?style=flat&logo=cplusplus)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows-green.svg)](https://www.microsoft.com/windows)
[![IDE](https://img.shields.io/badge/IDE-Visual%20Studio-purple.svg?logo=visualstudio)](https://visualstudio.microsoft.com/)

A comprehensive collection of C++ algorithm problems and solutions focusing on **date manipulation**, **string processing**, and **practical applications**. This repository represents Level 4 of a structured learning path for mastering algorithms and problem-solving skills.

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Repository Structure](#repository-structure)
- [Problem Categories](#problem-categories)
- [Projects](#projects)
- [Custom Libraries](#custom-libraries)
- [Getting Started](#getting-started)
- [Prerequisites](#prerequisites)
- [Building and Running](#building-and-running)

## Overview

This repository contains **65+ algorithm problems** and **2 complete projects** that demonstrate practical implementations of:

- Date arithmetic and manipulation
- Calendar generation and display
- Time period calculations
- Vacation day calculations
- String processing utilities
- Number-to-text conversion
- Banking system operations
- ATM simulation

## Features

- ✅ **65+ Solved Problems** - Comprehensive solutions with clean, readable code
- ✅ **2 Complete Projects** - Bank Management System and ATM System
- ✅ **Reusable Libraries** - Custom date and string manipulation libraries
- ✅ **Visual Studio Solutions** - Ready-to-build project files (`.slnx`, `.vcxproj`)
- ✅ **Well-Documented Code** - Clear variable naming and logical structure

## Repository Structure

```
├── MyLib/                                          # Custom reusable libraries
│   ├── my_date_lib.h                              # Comprehensive date manipulation library
│   └── my_string_lib.h                            # String processing utilities
│
├── PROBLEM_01_NUMBER_TO_TEXT/                      # Number to English text conversion
├── PROBLEM_02_LEAP_YEAR/                           # Leap year detection
├── PROBLEM_03_LEAP_YEAR_ONE_LINE_OF_CODE/          # Optimized leap year (single line)
├── PROBLEM_04_..._IN_A_YEAR/                       # Time calculations for a year
├── PROBLEM_05_..._IN_A_MONTH/                      # Time calculations for a month
├── PROBLEM_06_..._SHORT_LOGIC/                     # Days in month (short logic)
├── PROBLEM_07_DAY_NAME/                            # Get day name from date
├── PROBLEM_08_MONTH_CALENDAR/                      # Generate monthly calendar
├── PROBLEM_09_YEAR_CALENDAR/                       # Generate full year calendar
├── PROBLEM_10_DAYS_FROM_THE_BEGINNING_OF_YEAR/     # Calculate day order in year
├── PROBLEM_11_DATE_FROM_DAY_ORDER_IN_A_YEAR/       # Get date from day order
├── PROBLEM_12_ADD_DAYS_TO_DATE/                    # Add days to a date
├── PROBLEM_13_DATE1_LESS_THAN_DATE2/               # Date comparison (less than)
├── PROBLEM_14_DATE1_EQUALS_TO_DATE2/               # Date comparison (equality)
├── PROBLEM_15_LAST_DAY_LAST_MONTH/                 # Last day/month detection
├── PROBLEM_16_INCREASE_DATE_BY_ONE_DAY/            # Increment date by one day
├── PROBLEM_17_DIFF_IN_DAYS/                        # Calculate difference in days
├── PROBLEM_18_YOUR_AGE_IN_DAYS/                    # Calculate age in days
├── PROBLEM_19_DIFF_IN_DAYS_NEGATIVE_DAYS/          # Handle negative day differences
├── PROBLEM_20_TO_32_INCREASE_DATE_PROBLEMS/        # Date increment operations
├── PROBLEM_33_TO_46_DECREASE_DATE_PROBLEMS/        # Date decrement operations
├── PROBLEM_47_TO_53_MORE_DATE_PROBLEMS/            # Advanced date operations
├── PROBLEM_54_CALCULATE_VACATION_DAYS/             # Calculate business vacation days
├── PROBLEM_55_CALCULATE_VACATION_RETURN_DATE/      # Calculate vacation return date
├── PROBLEM_56_IS_DATE1_AFTER_DATE2/                # Date comparison (after)
├── PROBLEM_57_COMPARE_DATE_FUNCTION/               # General date comparison
├── PROBLEM_58_IS_OVERLAP_PERIODS/                  # Check period overlap
├── PROBLEM_59_PERIOD_LENGTH_IN_DAYS/               # Calculate period length
├── PROBLEM_60_IS_DATE_WITHIN_PERIOD/               # Check if date in period
├── PROBLEM_61_COUNT_OVERLAP_DAYS/                  # Count overlapping days
├── PROBLEM_62_VALIDATE_DATE/                       # Date validation
├── PROBLEM_63_AND_64_READ_PRINT_DATE_STRING/       # Date string I/O
├── PROBLEM_65_FORMAT_DATE/                         # Custom date formatting
│
├── PROJECT_1_BANK_EXTENSION_2/                     # Complete Bank Management System
│   ├── ARCHITECTURE.md                            # System architecture documentation
│   ├── PROJECT_1_BANK_EXTENSION_2.cpp
│   └── Users.txt                                  # User data file
│
└── PROJECT_2_ATM_SYSTEM/                           # ATM Simulation System
    ├── PROJECT_2_ATM_SYSTEM.cpp
    └── Clients.txt                                # Client data file
```

## Problem Categories

### 📆 Date Manipulation Problems

| Problem Range | Description |
|---------------|-------------|
| 02-06 | Leap year detection, time unit calculations |
| 07-09 | Day names, calendar generation |
| 10-12 | Date ordering and day addition |
| 13-19 | Date comparison and difference calculations |
| 20-32 | Increment operations (day, week, month, year, decade, century, millennium) |
| 33-46 | Decrement operations (mirror of increment problems) |
| 47-53 | Business day detection, days until end of week/month/year |
| 54-55 | Vacation day calculations |
| 56-61 | Advanced comparisons, period overlap detection |
| 62-65 | Date validation, string conversion, formatting |

### 🔢 Number Processing

| Problem | Description |
|---------|-------------|
| 01 | Convert numbers to English text (up to billions) |

## Projects

### 🏦 Project 1: Bank Management System (Extension 2)

A comprehensive console-based bank management system featuring:

- **User Authentication** - Login with username/password validation
- **Client Management** - Full CRUD operations for client accounts
- **Transaction Processing** - Deposit, withdraw, and balance checking
- **User Management** - Admin controls for system users
- **Permission System** - Bitwise flag-based access control
- **File Persistence** - Data stored in delimited text files

**Key Features:**
- Role-based access control (7 distinct permissions)
- Protected admin account
- Real-time balance updates
- Audit-friendly data format

### 🏧 Project 2: ATM System

A simulated ATM interface providing:

- **Quick Withdraw** - Preset withdrawal amounts (20, 50, 100, 200, 400, 600, 800, 1000)
- **Normal Withdraw** - Custom amount withdrawal
- **Deposit** - Add funds to account
- **Balance Check** - View current balance
- **Session Management** - Secure login/logout flow

## Custom Libraries

### `my_date_lib.h`

A comprehensive date manipulation library providing:

```cpp
namespace MyDateLib {
    // Structures
    struct stDate { short Year, Month, Day; };
    struct stPeriod { stDate StartDate, EndDate; };
    
    // Core Functions
    bool isLeapYear(short Year);
    short NumberOfDaysInAMonth(short Month, short Year);
    short DayOfWeekOrder(short Day, short Month, short Year);
    
    // Date Arithmetic
    stDate IncreaseDateByOneDay(stDate Date);
    stDate DecreaseDateByOneDay(stDate Date);
    int GetDifferenceInDays(stDate Date1, stDate Date2);
    
    // Business Logic
    bool IsBusinessDay(stDate Date);
    short CalculateVacationDays(stDate DateFrom, stDate DateTo);
    
    // Formatting
    string FormateDate(stDate Date, string DateFormat = "dd/mm/yyyy");
}
```

### `my_string_lib.h`

String processing utilities including:

```cpp
namespace MyStringLib {
    string UpperFirstLetterOfEachWord(string S1);
    string LowerAllString(string S1);
    string InvertAllStringLettersCase(string S1);
    vector<string> SplitString(string S1, string Delim);
    string JoinString(vector<string> vString, string Delim);
    string Trim(string S1);
    string ReverseWordsInString(string S1);
    short CountVowels(string S1);
}
```

## Getting Started

### Prerequisites

- **Operating System:** Windows 10/11
- **IDE:** Visual Studio 2019 or later (with C++ Desktop Development workload)
- **C++ Standard:** C++17 or later

### Building and Running

1. **Clone the repository:**
   ```bash
   git clone https://github.com/Valkenan/08-Algorithms-Problem-Solving-Level-4.git
   cd 08-Algorithms-Problem-Solving-Level-4
   ```

2. **Open a solution file:**
   - Navigate to any problem or project directory
   - Open the `.slnx` file with Visual Studio

3. **Build and run:**
   - Press `Ctrl + F5` to build and run without debugging
   - Press `F5` to build and run with debugging

### Example: Running Problem 01

```bash
cd PROBLEM_01_NUMBER_TO_TEXT
# Open PROBLEM_01_NUMBER_TO_TEXT.slnx with Visual Studio
# Build and run
```

**Sample Output:**
```
Please enter Number? 1234567
One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven
```

## License

This project is intended for educational purposes. Feel free to use the code for learning and reference.

---

<div align="center">

**Happy Coding! 🚀**

*Part of the Algorithms & Problem Solving Learning Path*

</div>