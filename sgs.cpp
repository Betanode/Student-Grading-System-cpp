#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Student {
    string name;
    int id;
    vector<int> scores;
    float average;
};

vector<Student> students;

// Function to add a new student
void addStudent() {
    Student newStudent;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, newStudent.name);
    cout << "Enter student ID: ";
    cin >> newStudent.id;
    students.push_back(newStudent);
    cout << "Student added successfully!" << endl;
}

// Function to display all students
void displayStudents() {
    if (students.empty()) {
        cout << "No students found." << endl;
        return;
    }

    cout << "ID\tName" << endl;
    for (const auto& student : students) {
        cout << student.id << "\t" << student.name << endl;
    }
}

// Function to enter scores for a student
void enterScores() {
    int id;
    cout << "Enter student ID: ";
    cin >> id;

    for (auto& student : students) {
        if (student.id == id) {
            cout << "Enter exam scores (enter -1 to stop): ";
            int score;
            while (cin >> score && score != -1) {
                student.scores.push_back(score);
            }
            return;
        }
    }

    cout << "Student not found." << endl;
}

// Function to calculate the average grade for each student
void calculateAverage() {
    for (auto& student : students) {
        if (student.scores.empty()) {
            student.average = 0.0;
        } else {
            float sum = 0.0;
            for (const auto& score : student.scores) {
                sum += score;
            }
            student.average = sum / student.scores.size();
        }
    }

    cout << "Averages calculated successfully!" << endl;
}

// Function to generate grade reports for all students
void generateGradeReports() {
    if (students.empty()) {
        cout << "No students found." << endl;
        return;
    }

    cout << "ID\tName\tAverage" << endl;
    for (const auto& student : students) {
        cout << student.id << "\t" << student.name << "\t" << fixed << setprecision(2) << student.average << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "Student Grading System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Enter Scores" << endl;
        cout << "4. Calculate Average" << endl;
        cout << "5. Generate Grade Reports" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                enterScores();
                break;
            case 4:
                calculateAverage();
                break;
            case 5:
                generateGradeReports();
                break;
            case 6:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }
}
