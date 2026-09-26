# CodeAlpha — CGPA & GPA Calculator in C++

![Language](https://img.shields.io/badge/Language-C%2B%2B17-blue.svg)
![Internship](https://img.shields.io/badge/Internship-CodeAlpha-orange.svg)
![Status](https://img.shields.io/badge/Status-Completed-success.svg)

A robust, multi-semester **CGPA (Cumulative Grade Point Average) and GPA Calculator** built in modern C++ as part of the **CodeAlpha Internship (Task 1)**.

---

## 📌 Features
- **Multi-Semester Computation**: Calculate semester GPA for 1 to 12 semesters.
- **Credit-Weighted Calculation**: Accurately computes weighted grade points (`Grade Point × Credit Hours`).
- **Standard Grading Scales**: Supports 10-point university grading (`O`, `A+`, `A`, `B+`, `B`, `C+`, `C`, `D`, `F`) and 4.0 scale conversions.
- **Input Validation**: Rejects invalid grades and out-of-range numeric inputs.
- **Formatted Report Cards**: Displays cleanly formatted semester summary tables and cumulative academic standing.

---

## 🛠️ How to Compile and Run

### Prerequisites
- GCC / MinGW C++ Compiler (supporting C++17 or higher)

### Compile
```bash
g++ -std=c++17 -o Task1_CGPA_Calculator.exe Task1_CGPA_Calculator.cpp
```

### Run
```bash
./Task1_CGPA_Calculator.exe
```

---

## 💻 Sample Output
```
  ===================================================
          CGPA CALCULATOR - CodeAlpha Internship
  ===================================================
  Enter number of semesters: 1

  -- Semester 1 --------------------------
  Enter number of courses: 3

  Course 1: Data Structures | Grade: O  | Credits: 4
  Course 2: Algorithms      | Grade: A+ | Credits: 4
  Course 3: Database Systems| Grade: A  | Credits: 3

  ===================================================
               SEMESTER 1 REPORT CARD
  ===================================================
  Course Name           Grade   Credits   Grade Pts
  ---------------------------------------------------
  Data Structures       O       4         40.0
  Algorithms            A+      4         40.0
  Database Systems      A       3         27.0
  ---------------------------------------------------
  Total Credits: 11          Semester GPA: 9.73
  ===================================================

  *** YOUR CGPA : 9.73 ***
  Academic Standing: Outstanding! (Distinction)
```

---

## 👨‍💻 Author
**Om Mane**  
- GitHub: [@om-mane-coder](https://github.com/om-mane-coder)
- Internship: CodeAlpha
