#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Employee {
private:
    int empId;
    char name[50];
    char designation[50];
    double salary;

public:
    void addEmployee() {
        ofstream file("employees.dat", ios::binary | ios::app);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }
        cout << "Enter Employee ID: ";
        cin >> empId;
        cout << "Enter Employee Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter Employee Designation: ";
        cin.getline(designation, 50);
        cout << "Enter Employee Salary: ";
        cin >> salary;

        file.write(reinterpret_cast<char*>(this), sizeof(Employee));

        file.close();
    }

void displayEmployee(int empId) {
        ifstream file("employees.dat", ios::binary);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }

        bool found = false;
        while (!file.eof()) {
            file.read(reinterpret_cast<char*>(this), sizeof(Employee));
            if (this->empId == empId) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "Employee ID: " << empId << endl;
            cout << "Name: " << name << endl;
            cout << "Designation: " << designation << endl;
            cout << "Salary: " << salary << endl;
        } else {
            cout << "Employee with ID " << empId << " not found." << endl;
        }

        file.close();
    }

    void deleteEmployee(int empId) {
        fstream file("employees.dat", ios::binary | ios::in | ios::out);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }

        Employee emp;
        bool found = false;
        while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
            if (emp.empId == empId) {
                found = true;
                break;
            }
        }

        if (found) {
            long pos = file.tellg();
            file.seekp(pos - sizeof(Employee));  
            Employee blankEmp;
            file.write(reinterpret_cast<char*>(&blankEmp), sizeof(Employee));  
            cout << "Employee with ID " << empId << " deleted successfully." << endl;
        } else {
            cout << "Employee with ID " << empId << " not found." << endl;
        }

        file.close();
    }


    
};

int main() {
    int choice;
    int empId;

    Employee emp;

    do {
        cout << "1. Add Employee" << endl;
        cout << "2. Display Employee" << endl;
        cout << "3. Delete Employee" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                emp.addEmployee();
                break;
            case 2:
                cout << "Enter Employee ID to display: ";
                cin >> empId;
                emp.displayEmployee(empId);
                break;
            case 3:
                cout << "Enter Employee ID to delete: ";
                cin >> empId;
                emp.deleteEmployee(empId);
                break;
            
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);
    return 0;
}




