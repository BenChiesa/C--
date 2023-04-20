#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Employee {
    public:
    Employee(string n, string title, double wage){
        setName(n);
        setJobTitle(title);
        setHourlyWage(wage);
    }
    
    void setName(string n){
        name = n;
    }
    
    string getName(){
        return name;
    }
    
    void setJobTitle(string title){
        jobTitle = title;
    }
    
    string getJobTitle(){
        return jobTitle;
    }
    
    void setHourlyWage(double wage){
        hourlyWage = wage;
    }
    
    double getHourlyWage(){
        return hourlyWage;
    }
    
    private:
    string name;
    string jobTitle;
    double hourlyWage;
};

int main(){
    int input;
    cout << "This program has 3 options to select." << endl;
    cout << "1. Prints the list of total employees." << endl;
    cout << "2. Calculates the total wages for the week." << endl;
    cout << "3. Exits the program." << endl;
    cin >> input;
    
    vector<Employee> employees;
    
    Employee e1("Bob", "Cashier", 15.00);
    Employee e2("Joe", "Supervisor", 20.00);
    Employee e3("John", "Intern", 0.00);
    Employee e4("Sara", "Manager", 25.00);
    Employee e5("Susan", "CEO", 50.00);
    
    employees.push_back(e1);
    employees.push_back(e2);
    employees.push_back(e3);
    employees.push_back(e4);
    employees.push_back(e5);
    
    switch(input){
        case 1:
            for(int i = 0; i < employees.size(); i++){
                cout << "Name: " << employees.at(i).getName() << endl;
                cout << "Job Title: " << employees.at(i).getJobTitle() << endl;
                cout << "Hourly Wage: " << employees.at(i).getHourlyWage() << endl;
                cout << "\n" << endl;
            }
            break;
        
        case 2:
            double totalWage, wage;
            int hoursWorked;
            for(int i = 0; i < employees.size(); i++){
                string tempName = employees.at(i).getName();
                double tempWage = employees.at(i).getHourlyWage();
                cout << "How many hours did " << tempName << " work?" << endl;
                cin >> hoursWorked;
                switch(hoursWorked){
                    case 0 ... 50:
                        wage = hoursWorked * tempWage;
                        totalWage = totalWage + wage;
                    break;
                    
                    default: 
                        cout << "Invalid Input" << endl;
                        cout << "How many hours did " << tempName << " work?" << endl;
                        cin >> hoursWorked;
                    break;
                }
            }
            cout << "The total amount of money spent on wages in a week is $" << totalWage << endl;
        break;
        
        case 3:
            exit(0);
        break;
        
        default:
            cout << "Invalid Input." << endl;
            cout << "1. Prints the list of total employees." << endl;
            cout << "2. Calculates the total wages for the week." << endl;
            cout << "3. Exits the program." << endl;
            cin >> input;
        break;
    }
    return 0;
}