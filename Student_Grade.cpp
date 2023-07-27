#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    double grade;
};

int main() {
    std::vector<Student> students;
    std::string name;
    double grade;

    char choice;
    do {
        std::cout << "Enter student name: ";
        std::cin.ignore(); // Ignore newline character from previous input
        std::getline(std::cin, name);

        std::cout << "Enter student grade: ";
        std::cin >> grade;

        students.push_back({name, grade});

        std::cout << "Do you want to add another student? (Y/N): ";
        std::cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    double totalGrade = 0;
    double highestGrade = students[0].grade;
    double lowestGrade = students[0].grade;

    for (const auto& student : students) {
        totalGrade += student.grade;
        highestGrade = std::max(highestGrade, student.grade);
        lowestGrade = std::min(lowestGrade, student.grade);
    }

    double averageGrade = totalGrade / students.size();

    std::cout << "\nStudent Grades Summary:" << std::endl;
    for (const auto& student : students) {
        std::cout << "Name: " << student.name << "\tGrade: " << student.grade << std::endl;
    }

    std::cout << "\nAverage Grade: " << averageGrade << std::endl;
    std::cout << "Highest Grade: " << highestGrade << std::endl;
    std::cout << "Lowest Grade: " << lowestGrade << std::endl;

    return 0;
}
