#include <iostream>

using namespace std;

int main(){
    
    string name[1000];
    int id[1000];
    double gpa[1000];
    
    int currentIndex = 0;
    
    string tempName, tempId, tempGpa;
    
    do{
        cout << "Enter the student name" << endl;
        getline(cin, tempName);
        cout << "Enter the student id" << endl;
        getline(cin, tempId);
        cout << "Enter the student gpa" << endl;
        getline(cin, tempGpa);
        
        name[currentIndex] = tempName;
        id[currentIndex] = stoi(tempId);
        gpa[currentIndex] = stod(tempGpa);
        
        currentIndex++;
        cout << "Enter more student names? (y/n):" << endl;
        getline(cin, tempName);
    }while(tempName == "y");
    
    for(int i = 0; i < currentIndex; i++){
        cout << name[i] << endl;
        cout << id[i] << endl;
        cout << gpa[i] << endl;
    }
    
    return 0;
}