<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++"/>
  <img src="https://img.shields.io/badge/IDE-Visual%20Studio-5C2D91?style=for-the-badge&logo=visualstudio&logoColor=white" alt="Visual Studio"/>
  <img src="https://img.shields.io/badge/Platform-Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white" alt="Windows"/>
  <img src="https://img.shields.io/badge/Problems-50+-success?style=for-the-badge" alt="50+ Problems"/>
</p>

<h1 align="center">🎓 05 - Algorithms & Problem-Solving Level 2</h1>

<p align="center">
  <strong>A comprehensive collection of C++ programming exercises, algorithms, and interactive projects designed to master fundamental programming concepts.</strong>
</p>

<p align="center">
  <a href="#-quick-start">Quick Start</a> •
  <a href="#-projects">Projects</a> •
  <a href="#-problem-sets">Problems</a> •
  <a href="#-learning-path">Learning Path</a> •
  <a href="#-author">Author</a>
</p>

---

## 📖 Overview

This repository serves as a structured learning path for C++ programming, featuring **50+ hands-on problems** and **2 complete game projects**. Each exercise is carefully designed to reinforce core programming concepts through practical application.

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
git clone https://github.com/Valkenan/Cours-5.git

# Navigate to the project
cd Cours-5

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

## 🎮 Projects

### 1. Math Quiz Game

<table>
<tr>
<td>

**🧮 Interactive Educational Quiz Game**

Challenge yourself with randomly generated math problems across multiple difficulty levels!

| Feature                  | Description                                            |
| ------------------------ | ------------------------------------------------------ |
| 📊 **Difficulty Levels** | Easy (1-10), Medium (11-50), Hard (51-100), Mixed      |
| ➕ **Operations**        | Addition, Subtraction, Multiplication, Division, Mixed |
| 🏆 **Scoring System**    | Tracks correct/incorrect answers with pass/fail result |
| 🔄 **Replayability**     | New questions generated each session                   |

```
📁 Math_Quiz_Game_Project/          → Base template
📁 Math_Quiz_Game_Project_Solve/    → Complete solution
```

</td>
</tr>
</table>

---

### 2. Rock-Paper-Scissors

<table>
<tr>
<td>

**✊✋✌️ Classic Game vs Computer AI**

Test your luck against a computer opponent in this timeless game!

| Feature               | Description                        |
| --------------------- | ---------------------------------- |
| 🎯 **Rounds**         | Configurable 1-10 rounds per game  |
| 🤖 **AI Opponent**    | Random computer choice generation  |
| 📈 **Score Tracking** | Real-time win/lose/draw statistics |
| 🏅 **Final Verdict**  | Declares ultimate winner           |

```
📁 Project_1_Rock-Paper-Scissors/        → Base template
📁 Project_1_Rock-Paper-Scissors_Solve/  → Complete solution
```

</td>
</tr>
</table>

---

## 📚 Problem Sets

A structured collection of **50 programming challenges** organized by topic and difficulty.

### 📋 Problem Index

<details>
<summary><b>🔢 Numbers & Mathematics (Problems #1-10)</b></summary>

| #   | Problem              | Concept                     | Difficulty |
| --- | -------------------- | --------------------------- | ---------- |
| 1   | Multiplication Table | Nested loops, formatting    | ⭐         |
| 2   | Prime Numbers        | Number theory, divisibility | ⭐⭐       |
| 3   | Perfect Numbers      | Sum of divisors             | ⭐⭐       |
| 4-9 | Number Operations    | Mathematical algorithms     | ⭐-⭐⭐    |
| 10  | Reverse Number       | Digit manipulation          | ⭐⭐       |

</details>

<details>
<summary><b>🔤 Patterns & Strings (Problems #11-20)</b></summary>

| #     | Problem            | Concept                        | Difficulty |
| ----- | ------------------ | ------------------------------ | ---------- |
| 11-14 | Input Validation   | Do-while loops, error handling | ⭐⭐       |
| 15    | Letter Pattern     | ASCII, nested loops            | ⭐⭐       |
| 16-19 | Control Structures | Conditionals, loops            | ⭐⭐       |
| 20    | Random Generation  | rand(), enums, character types | ⭐⭐⭐     |

</details>

<details>
<summary><b>⚙️ Functions & Structures (Problems #21-35)</b></summary>

| #     | Problem         | Concept                   | Difficulty |
| ----- | --------------- | ------------------------- | ---------- |
| 21-25 | Function Design | Parameters, return values | ⭐⭐       |
| 26-30 | Enumerations    | Custom types, switch      | ⭐⭐⭐     |
| 31-35 | Structures      | Data organization         | ⭐⭐⭐     |

</details>

<details>
<summary><b>🧠 Advanced Topics (Problems #36-50)</b></summary>

| #     | Problem          | Concept               | Difficulty |
| ----- | ---------------- | --------------------- | ---------- |
| 36-40 | Algorithm Design | Problem solving       | ⭐⭐⭐     |
| 41-45 | Complex Logic    | Multi-step algorithms | ⭐⭐⭐⭐   |
| 46-50 | Integration      | Combined concepts     | ⭐⭐⭐⭐   |

</details>

### 📁 Folder Structure

```
Problem #X/
├── Problem #X.cpp              # Source code with detailed comments
├── Problem #X.sln              # Visual Studio solution
├── Problem #X.vcxproj          # Project configuration
└── Problem #X.vcxproj.filters  # File organization
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
| **6. Integration**  | Complete projects             | Games    | 🟢     |

---

## 💻 Code Standards

All code follows consistent professional standards:

```cpp
#include <iostream>
#include <string>
using namespace std;

// Enumeration for type safety
enum enPrimNotPrime { Prime = 1, NotPrime = 2 };

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

| 📝 Problems | 🎮 Projects | 💻 Language |  📅 Updated  |
| :---------: | :---------: | :---------: | :----------: |
|   **50+**   |    **2**    |  **C++11**  | **Nov 2025** |

</p>

---

## 🛠️ Tech Stack

<p align="center">
  <img src="https://skillicons.dev/icons?i=cpp,visualstudio,windows,git" alt="Tech Stack"/>
</p>

---

## 🤝 Contributing

This is a personal learning repository. However, suggestions for improvements or alternative solutions are welcome!

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
