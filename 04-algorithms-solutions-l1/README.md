<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++"/>
  <img src="https://img.shields.io/badge/IDE-Visual%20Studio-5C2D91?style=for-the-badge&logo=visualstudio&logoColor=white" alt="Visual Studio"/>
  <img src="https://img.shields.io/badge/Platform-Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white" alt="Windows"/>
  <img src="https://img.shields.io/badge/Problems-50+-success?style=for-the-badge" alt="50+ Problems"/>
</p>

<h1 align="center">🎓 04 - Algorithms & Problem-Solving Level 1</h1>

<p align="center">
  <strong>A comprehensive collection of C++ programming exercises designed to master fundamental programming concepts through hands-on practice.</strong>
</p>

<p align="center">
  <a href="#-quick-start">Quick Start</a> •
  <a href="#-problem-sets">Problems</a> •
  <a href="#-learning-path">Learning Path</a> •
  <a href="#-author">Author</a>
</p>

---

## 📖 Overview

This repository serves as a structured learning path for C++ programming, featuring **50 hands-on problems**. Each exercise is carefully designed to reinforce core programming concepts through practical application.

## 🚀 Quick Start

### Prerequisites

| Requirement   | Version | Notes                                 |
| ------------- | ------- | ------------------------------------- |
| Visual Studio | 2019+   | With C++ Desktop Development workload |
| Windows       | 10/11   | Primary development platform          |
| C++ Standard  | C++11+  | Supported by all projects             |

### Installation

```bash
# Clone the repository
git clone https://github.com/Valkenan/Cours-4.git

# Navigate to the project
cd Cours-4

# Open any .sln file in Visual Studio
```

### Build & Run

<table>
<tr>
<td width="50%">

**🖥️ Visual Studio**

1. Open `.sln` file
2. Press `Ctrl+Shift+B` to build
3. Press `F5` to run (debug) or `Ctrl+F5` (release)

</td>
<td width="50%">

**⌨️ Command Line**

```bash
# MSVC Compiler
cl /EHsc /Fe:program.exe "filename.cpp"

# GCC/MinGW
g++ -std=c++11 -o program "filename.cpp"
```

</td>
</tr>
</table>

---

## 📚 Problem Sets

A structured collection of **50 programming challenges** organized by topic and difficulty.

### 📋 Problem Index

<details>
<summary><b>🔰 Basics & Functions (Problems #1-10)</b></summary>

| #   | Problem         | Concept                            | Difficulty |
| --- | --------------- | ---------------------------------- | ---------- |
| 1   | probleam1       | Print name using functions         | ⭐         |
| 2   | Problem2        | Read and display user name         | ⭐         |
| 3   | Problem3        | Odd/Even checker with enum         | ⭐⭐       |
| 4   | Problem4        | Job application with struct        | ⭐⭐       |
| 5   | probleam5       | Candidate evaluation               | ⭐⭐       |
| 6   | probleam6       | Full name builder (normal/reverse) | ⭐⭐       |
| 7   | probleam7       | Half number calculator             | ⭐         |
| 8   | probleam8       | Pass/Fail grade checker            | ⭐⭐       |
| 9   | probleam9       | Sum of 3 numbers (references)      | ⭐⭐       |
| 10  | add probleam 10 | Average calculator                 | ⭐⭐       |

</details>

<details>
<summary><b>📊 Control Structures (Problems #11-25)</b></summary>

| #     | Problem      | Concept                    | Difficulty |
| ----- | ------------ | -------------------------- | ---------- |
| 11    | Problem11    | Pass/Fail based on average | ⭐⭐       |
| 12-15 | Problem12-15 | Input validation           | ⭐⭐       |
| 16-20 | Problem16-20 | Loop structures            | ⭐⭐       |
| 21-25 | Problem21-25 | Conditional logic          | ⭐⭐⭐     |

</details>

<details>
<summary><b>🧮 Mathematical Operations (Problems #26-40)</b></summary>

| #     | Problem      | Concept                 | Difficulty |
| ----- | ------------ | ----------------------- | ---------- |
| 26-29 | Problem26-29 | Number operations       | ⭐⭐       |
| 30    | Problem30    | Factorial calculator    | ⭐⭐⭐     |
| 31-35 | Problem31-35 | Mathematical algorithms | ⭐⭐⭐     |
| 36-40 | Problem36-40 | Advanced calculations   | ⭐⭐⭐     |

</details>

<details>
<summary><b>🧠 Advanced Topics (Problems #41-50)</b></summary>

| #     | Problem      | Concept                          | Difficulty |
| ----- | ------------ | -------------------------------- | ---------- |
| 41-45 | Problem41-45 | Complex logic & algorithms       | ⭐⭐⭐⭐   |
| 46-49 | Problem46-49 | Integration of multiple concepts | ⭐⭐⭐⭐   |
| 50    | Problem50    | PIN-based login system           | ⭐⭐⭐⭐   |

</details>

### 📁 Folder Structure

```
ProblemX/
├── ProblemX.cpp              # Source code with detailed comments
├── ProblemX.sln              # Visual Studio solution
├── ProblemX.vcxproj          # Project configuration
└── ProblemX.vcxproj.filters  # File organization
```

---

## 🎯 Learning Path

### Skills Progression

| Stage               | Topics                        | Problems | Status |
| ------------------- | ----------------------------- | -------- | ------ |
| **1. Fundamentals** | Variables, operators, I/O     | #1-5     | 🟢     |
| **2. Control Flow** | Loops, conditionals, switches | #6-15    | 🟢     |
| **3. Functions**    | Parameters, returns, scope    | #16-25   | 🟢     |
| **4. Custom Types** | Enums, structs, type safety   | #26-35   | 🟢     |
| **5. Algorithms**   | Problem-solving strategies    | #36-50   | 🟢     |

---

## 💻 Code Standards

All code follows consistent professional standards:

```cpp
#include <iostream>
#include <string>
using namespace std;

// Enumeration for type safety
enum enPassFail { Pass = 1, Fail = 2 };

/**
 * @brief Reads a positive number from user input
 * @param Message Prompt message to display
 * @return Validated positive integer
 */
int ReadPositiveNumber(string Message) {
    int Number = 0;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

int main() {
    // Entry point with clear program flow
    return 0;
}
```

### ✅ Coding Conventions

| Convention               | Example                       |
| ------------------------ | ----------------------------- |
| **PascalCase** functions | `ReadPositiveNumber()`        |
| **Descriptive** names    | `NumberOfRightAnswers`        |
| **Input validation**     | Do-while loops for user input |
| **Enumerations**         | Type-safe constants           |
| **Comments**             | Purpose, parameters, returns  |

---

## 📊 Repository Statistics

<p align="center">

| 📝 Problems | 💻 Language |  📅 Updated  |
| :---------: | :---------: | :----------: |
|   **50**    |  **C++11**  | **Nov 2025** |

</p>

---

## 🛠️ Tech Stack

<p align="center">
  <img src="https://skillicons.dev/icons?i=cpp,visualstudio,windows,git" alt="Tech Stack"/>
</p>

---

## 📌 Notes

> Some folder names contain typos (e.g., `probleam` instead of `problem`, `add probleam 10`). These are preserved from the original structure but can be renamed for consistency.

---

## 🤝 Contributing

Contributions are welcome! Feel free to:

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/improvement`)
3. Commit changes (`git commit -m 'Add improvement'`)
4. Push to branch (`git push origin feature/improvement`)
5. Open a Pull Request

---

## 📄 License

This project is created for **educational purposes**.

---

## 👤 Author

<p align="center">
  <b>Valkenan</b><br/>
  <a href="https://github.com/Valkenan">
    <img src="https://img.shields.io/badge/GitHub-@Valkenan-181717?style=for-the-badge&logo=github" alt="GitHub"/>
  </a>
</p>

---

<p align="center">
  <sub>⭐ If this repository helped you learn C++, consider giving it a star!</sub>
</p>

<p align="center">
  <sub>Built with ❤️ for learning C++ programming</sub>
</p>
