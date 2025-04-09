#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class StudentsRecords
{
private:
    string roll, name;
    int marks;

public:
    void readStudents()
    {
        ifstream file("students.txt");
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }
        while (file >> roll >> name >> marks) {
            if (marks < 0 || marks > 100) {
                cout << "Invalid number Enter a number between 0 to 100." << endl;
            } else {
                cout << "Roll: " << roll << ", Name: " << name << ", Marks: " << marks << endl;
            }
        }
        file.close();
    }

    void addStudent()
    {
        ofstream file("students.txt", ios::app);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }
        string roll, name;
        int marks;
        cout << "Enter Roll No, Name, and Marks: ";
        cin >> roll >> name >> marks;
        if (marks < 0 || marks > 100) {
            cout << "Invalid marks! Must be between 0 and 100." << endl;
            return;
        }
        file << roll << " " << name << " " << marks << endl;
        file.close();
        cout << "Student record added successfully!" << endl;
    }
    void modifyStudent()
    {
        ifstream file("students.txt");
        if (!file) {
            cout << "Error opening file" << endl;
            return;
        }
        vector<pair<string, pair<string, int>>> students;
        string r, n;
        int m;
        while (file >> r >> n >> m) {
            students.push_back({r, {n, m}});
        }
        file.close();

        string rollNo;
        cout << "Enter Roll No of the student to modify: ";
        cin >> rollNo;

        bool found = false;
        for (auto &student : students) {
            if (student.first == rollNo) {
                cout << "Enter new Name and Marks: ";
                cin >> student.second.first >> student.second.second;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Student not found!" << endl;
            return;
        }

        ofstream outFile("students.txt");
        for (const auto &student : students) {
            outFile << student.first << " " << student.second.first << " " << student.second.second << endl;
        }
        outFile.close();
        cout << "Student record updated successfully!" << endl;
    }
};
class BookRecords
{
private:
    vector<string> books;

public:
    void readBooks()
    {
        ifstream file("books.txt");
        if (!file)
        {
            cout << "Error opening file!" << endl;
            return;
        }
         string book;
        while (getline(file, book)) {
            cout << "Book: " << book << endl;
        }
        file.close();
    }

    void addBooks()
    {
        cout << "Enter 10 book titles: " << endl;
        books.resize(10);
        cin.ignore();
        for (int i = 0; i < 10; i++) {
            cout << "Book " << i + 1 << ": ";
            getline(cin, books[i]);
        }
    }
    void saveBooksToFile(const string &filename)
    {
        ofstream file(filename);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }
        for (const auto &book : books) {
            file << book << endl;
        }
        file.close();
        cout << "Books saved successfully!" << endl;
    }
};

int main()
{
        StudentsRecords sr;
        BookRecords br;
        int choice;
        string filename, title;
        cout << "Enter your choice:" << endl;
        cout << "1. Read Students" << endl;
        cout << "2. Add Student" << endl;
        cout << "3. Modify"<<endl;
        cout<<  "4. Read Books" <<endl;
        cout << "5. Add Books" << endl;
        cout << "6. Save Books to File" << endl;
        cout << "8. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                sr.readStudents();
                break;
            case 2:
                sr.addStudent();
                break;
            case 3:
                sr.modifyStudent();
                break;
            case 4:
                br.readBooks();
                break;
            case 5:
                br.addBooks();
                break;
            case 6:
                cout << "Enter file name to save books: ";
                cin >> filename;
                br.saveBooksToFile(filename);
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice Please enter a number between 1 and 7." << endl;
        }


    return 0;
}

