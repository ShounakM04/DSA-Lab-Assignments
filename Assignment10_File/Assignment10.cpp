#include <iostream>
#include <fstream>
using namespace std;

struct Student
{
    int roll_no;
    char name[15];
    int div;
    char addr[200];
};

class Mystdb
{
public:
    void addDatabase();           // Function to create a database
    void addStudentRecord();      // Function to add a student record
    void display();               // Function to display all records
    void searchRecord(int rn);    // Function to search a record
    void deleteRecord(int key);   // Function to delete a record
    void modifyRecord(int key);   // Function to modify a record
    void clearDatabase();         // Function to clear database
};

//******************* CREATE A DATABASE *******************
void Mystdb::addDatabase()
{
    int n;
    ofstream file;
    cout << "How many Students to add to the database: " << endl;
    cin >> n;
    file.open("std.txt", ios::out);
    for (int i = 0; i < n; i++)
    {
        Student stdrc;
        cout << "Enter Roll Number of Student: " << endl;
        cin >> stdrc.roll_no;
        cout << "Enter Name: " << endl;
        cin >> stdrc.name;
        cout << "Enter Division: " << endl;
        cin >> stdrc.div;
        cout << "Enter Address: " << endl;
        cin >> stdrc.addr;
        file << stdrc.name << " " << stdrc.roll_no << " " << stdrc.div << " " << stdrc.addr << endl;
    }
    file.close();
}

//******************* ADD STUDENT RECORD *******************
void Mystdb::addStudentRecord()
{
    ofstream file;
    file.open("std.txt", ios::app);
    Student stdrc;
    cout << "Enter Roll Number of Student: " << endl;
    cin >> stdrc.roll_no;
    cout << "Enter Name: " << endl;
    cin >> stdrc.name;
    cout << "Enter Division: " << endl;
    cin >> stdrc.div;
    cout << "Enter Address: " << endl;
    cin >> stdrc.addr;
    file << stdrc.name << " " << stdrc.roll_no << " " << stdrc.div << " " << stdrc.addr << endl;
}

//******************* DISPLAY *******************
void Mystdb::display()
{
    ifstream file;
    Student stdrc;
    file.open("std.txt", ios::in);
    while (file >> stdrc.name >> stdrc.roll_no >> stdrc.div >> stdrc.addr)
    {
        cout << "Student Roll No. : " << stdrc.roll_no << endl;
        cout << "Student Name : " << stdrc.name << endl;
        cout << "Student Division : " << stdrc.div << endl;
        cout << "Student Address : " << stdrc.addr << endl;
    }
    file.close();
}

//******************* SEARCH A RECORD *******************
void Mystdb::searchRecord(int rn)
{
    ifstream file;
    Student stdrc;
    file.open("std.txt", ios::in);
    while (file >> stdrc.name >> stdrc.roll_no >> stdrc.div >> stdrc.addr)
    {
        if (stdrc.roll_no == rn)
        {
            cout << "Found " << rn << endl;
            file.close();
            return;
        }
    }
    cout << "Not Found " << endl;
    file.close();
}

//******************* DELETE A RECORD *******************
void Mystdb::deleteRecord(int key)
{
    ifstream file;
    file.open("std.txt", ios::in);
    Student stdrc;
    ofstream temp;
    bool found = 0;
    temp.open("temp.txt", ios::out);
    while (file >> stdrc.name >> stdrc.roll_no >> stdrc.div >> stdrc.addr)
    {
        if (stdrc.roll_no != key)
        {
            temp << stdrc.name << " " << stdrc.roll_no << " " << stdrc.div << " " << stdrc.addr << endl;
        }
        else
        {
            found = 1;
        }
    }
    file.close();
    temp.close();
    remove("std.txt");
    rename("temp.txt", "std.txt");
    if (found)
    {
        cout << "Deleted : " << key << endl;
    }
    else
    {
        cout << "Element Not Found to Delete" << endl;
    }
}

//******************* MODIFY A RECORD *******************
void Mystdb::modifyRecord(int key)
{
    ifstream file;
    file.open("std.txt", ios::in);
    Student stdrc;
    ofstream temp;
    bool found = 0;
    temp.open("temp.txt", ios::out);
    while (file >> stdrc.name >> stdrc.roll_no >> stdrc.div >> stdrc.addr)
    {
        if (stdrc.roll_no == key)
        {
            cout << "Enter data to Modify " << endl;
            cout << "Enter Roll Number of Student: " << endl;
            cin >> stdrc.roll_no;
            cout << "Enter Name: " << endl;
            cin >> stdrc.name;
            cout << "Enter Division: " << endl;
            cin >> stdrc.div;
            cout << "Enter Address: " << endl;
            cin >> stdrc.addr;
            found = 1;
        }
        temp << stdrc.name << " " << stdrc.roll_no << " " << stdrc.div << " " << stdrc.addr << endl;
    }
    file.close();
    temp.close();
    remove("std.txt");
    rename("temp.txt", "std.txt");
    if (found)
    {
        cout << "Modified : " << key << endl;
    }
    else
    {
        cout << "Element Not Found to Modify" << endl;
    }
}

//******************* CLEAR DATABASE *******************
void Mystdb::clearDatabase()
{
    ofstream file;
    file.open("std.txt", ios::trunc);
    file.close();
}

//******************* MAIN *******************
int main()
{
    Mystdb s;
    int choice, rollNo;
    do
    {
        cout << "\n*** Student Database Management System ***\n";
        cout << "1. Add Students to Database\n";
        cout << "2. Add a Single Student Record\n";
        cout << "3. Display All Students\n";
        cout << "4. Search for a Student\n";
        cout << "5. Delete a Student Record\n";
        cout << "6. Modify a Student Record\n";
        cout << "7. Clear Database\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            s.addDatabase();
            break;
        case 2:
            s.display();
            break;
        case 3:
            cout << "Enter Roll Number to search: ";
            cin >> rollNo;
            s.searchRecord(rollNo);
            break;
        case 4:
            cout << "Enter Roll Number to delete: ";
            cin >> rollNo;
            s.deleteRecord(rollNo);
            break;
        case 5:
            cout << "Enter Roll Number to modify: ";
            cin >> rollNo;
            s.modifyRecord(rollNo);
            break;
        case 6:
            s.clearDatabase();
            cout << "Database cleared.\n";
            break;
        case 7:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 8);
    return 0;
}
