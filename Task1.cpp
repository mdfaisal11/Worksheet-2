#include <iostream>
using namespace std;
class Student
{
    string name;
    int marks[3];

public:
    void getData()
{
        cout << "Enter student name: "<<endl;
        cin >> name;
        cout << "Enter marks for 3 subjects: "<<endl;
        for (int i = 0; i < 3; i++) {
            cin >> marks[i];
            if (marks[i] < 0 || marks[i] > 100) {
                cout << "Invalid mark! Must be between 0 and 100"<<endl;
            }
        }
    }

    void calculateResult()
    {
        int total = marks[0] + marks[1] + marks[2];
        float avg = total / 3.0;
        char grade;
        if (avg >= 90)
            grade = 'A+';
        else if (avg >= 80)
            grade = 'A';
        else if (avg >= 70)
            grade = 'B+';
        else if (avg >= 60)
            grade = 'B';
        else if (avg >= 50)
            grade = 'C+';
        else if (avg >= 40)
            grade = 'C';
        else
            grade = 'F';

        cout << "Student: " << name << endl;
        cout << "Total Marks: " << total << endl;
        cout << "Average Marks: " << avg << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    Student s1;
    s1.getData();
    s1.calculateResult();

    return 0;
}
