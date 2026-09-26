/*
 * ============================================================
 *  CodeAlpha Internship - C++ Programming
 *  TASK 1: CGPA Calculator
 * ============================================================
 *  Description:
 *    - Takes input for the number of courses per semester.
 *    - For each course, inputs the grade and credit hours.
 *    - Calculates total credits and total grade points.
 *    - Computes semester GPA and overall CGPA.
 *    - Displays individual course grades and final CGPA.
 * ============================================================
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

struct Course {
    string name;
    string grade;
    int creditHours;
    double gradePoint;
};

struct Semester {
    int semesterNumber;
    vector<Course> courses;
    double gpa;
    int totalCredits;
    double totalGradePoints;
};

double gradeToPoint(const string& grade) {
    if (grade == "O"  || grade == "A+") return 10.0;
    if (grade == "A")  return 9.0;
    if (grade == "B+") return 8.0;
    if (grade == "B")  return 7.0;
    if (grade == "C+") return 6.0;
    if (grade == "C")  return 5.0;
    if (grade == "D")  return 4.0;
    if (grade == "F")  return 0.0;
    return -1.0;
}

void displayGradeScale() {
    cout << "\n";
    cout << "  +--------+---------------+\n";
    cout << "  | Grade  | Grade Points  |\n";
    cout << "  +--------+---------------+\n";
    cout << "  | O / A+ |     10.0      |\n";
    cout << "  | A      |      9.0      |\n";
    cout << "  | B+     |      8.0      |\n";
    cout << "  | B      |      7.0      |\n";
    cout << "  | C+     |      6.0      |\n";
    cout << "  | C      |      5.0      |\n";
    cout << "  | D      |      4.0      |\n";
    cout << "  | F      |      0.0      |\n";
    cout << "  +--------+---------------+\n\n";
}

void displaySemesterReport(const Semester& sem) {
    cout << "\n  ===================================================\n";
    cout << "               SEMESTER " << sem.semesterNumber << " REPORT CARD\n";
    cout << "  ===================================================\n";
    cout << "  " << left << setw(22) << "Course Name"
         << setw(8) << "Grade" << setw(10) << "Credits" << "Grade Pts\n";
    cout << "  ---------------------------------------------------\n";

    for (const auto& c : sem.courses) {
        cout << "  " << left << setw(22) << c.name.substr(0, 21)
             << setw(8) << c.grade
             << setw(10) << c.creditHours
             << fixed << setprecision(1) << (c.gradePoint * c.creditHours) << "\n";
    }

    cout << "  ---------------------------------------------------\n";
    cout << "  Total Credits: " << sem.totalCredits
         << "          Semester GPA: " << fixed << setprecision(2) << sem.gpa << "\n";
    cout << "  ===================================================\n";
}

int getValidInt(const string& prompt, int minVal, int maxVal) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= minVal && value <= maxVal) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "  [!] Please enter a number between " << minVal << " and " << maxVal << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    cout << "\n  ===================================================\n";
    cout << "          CGPA CALCULATOR - CodeAlpha Internship\n";
    cout << "  ===================================================\n";

    displayGradeScale();

    int numSemesters = getValidInt("  Enter number of semesters: ", 1, 12);

    vector<Semester> semesters;
    double cumGradePoints = 0.0;
    int cumCredits = 0;

    for (int s = 1; s <= numSemesters; s++) {
        Semester sem;
        sem.semesterNumber = s;
        sem.totalCredits = 0;
        sem.totalGradePoints = 0.0;

        cout << "\n  -- Semester " << s << " --------------------------\n";
        int numCourses = getValidInt("  Enter number of courses: ", 1, 15);

        for (int c = 1; c <= numCourses; c++) {
            Course course;
            cout << "\n  Course " << c << ":\n";
            cout << "    Course Name  : ";
            getline(cin, course.name);

            while (true) {
                cout << "    Grade        : ";
                getline(cin, course.grade);
                transform(course.grade.begin(), course.grade.end(),
                          course.grade.begin(), ::toupper);
                course.gradePoint = gradeToPoint(course.grade);
                if (course.gradePoint >= 0) break;
                cout << "    [!] Invalid grade. Use: O, A+, A, B+, B, C+, C, D, F\n";
            }

            course.creditHours = getValidInt("    Credit Hours : ", 1, 10);
            sem.courses.push_back(course);
            sem.totalCredits += course.creditHours;
            sem.totalGradePoints += (course.gradePoint * course.creditHours);
        }

        sem.gpa = (sem.totalCredits > 0) ? (sem.totalGradePoints / sem.totalCredits) : 0.0;
        semesters.push_back(sem);
        cumCredits += sem.totalCredits;
        cumGradePoints += sem.totalGradePoints;

        displaySemesterReport(sem);
    }

    double cgpa = (cumCredits > 0) ? (cumGradePoints / cumCredits) : 0.0;

    cout << "\n  ===================================================\n";
    cout << "               CUMULATIVE CGPA SUMMARY\n";
    cout << "  ===================================================\n";

    for (const auto& sem : semesters) {
        cout << "  Semester " << setw(2) << sem.semesterNumber
             << ":  GPA = " << fixed << setprecision(2) << setw(5) << sem.gpa
             << "  |  Credits: " << setw(3) << sem.totalCredits << "\n";
    }

    cout << "  ---------------------------------------------------\n";
    cout << "  Total Credits Earned : " << cumCredits << "\n";
    cout << "  Total Grade Points   : " << fixed << setprecision(1) << cumGradePoints << "\n";
    cout << "\n  *** YOUR CGPA : " << fixed << setprecision(2) << cgpa << " ***\n\n";

    cout << "  Academic Standing: ";
    if (cgpa >= 9.0)      cout << "Outstanding! (Distinction)\n";
    else if (cgpa >= 8.0) cout << "Excellent! (First Class with Distinction)\n";
    else if (cgpa >= 7.0) cout << "Very Good (First Class)\n";
    else if (cgpa >= 6.0) cout << "Good (Second Class)\n";
    else if (cgpa >= 5.0) cout << "Average (Pass)\n";
    else if (cgpa >= 4.0) cout << "Below Average (Pass)\n";
    else                  cout << "Failed. Please consult your academic advisor.\n";

    cout << "\n  Thank you for using CGPA Calculator!\n";
    cout << "  -- CodeAlpha Internship --\n\n";
    return 0;
}
