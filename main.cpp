#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Function to calculate CGPA
double calculateCGPA(const vector<int>& creditHours, const vector<double>& grades) {
    double totalGradePoints = 0;
    int totalCredits = 0;

    for (size_t i = 0; i < grades.size(); ++i) {
        totalGradePoints += grades[i] * creditHours[i];
        totalCredits += creditHours[i];
    }

    return totalCredits > 0 ? (totalGradePoints / totalCredits) : 0.0;
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<int> creditHours(numCourses);
    vector<double> grades(numCourses);

    for (int i = 0; i < numCourses; ++i) {
        cout << "Enter credit hours for course " << i + 1 << ": ";
        cin >> creditHours[i];
        cout << "Enter grade for course " << i + 1 << ": ";
        cin >> grades[i];
    }

    double cgpa = calculateCGPA(creditHours, grades);
    cout << "\nTotal Credits Earned: " << accumulate(creditHours.begin(), creditHours.end(), 0) << endl;
    cout << "CGPA: " << cgpa << endl;

    return 0;
}
