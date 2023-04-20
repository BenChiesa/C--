#include <iostream>

using namespace std;

class Person{
  public:
  Person(string name, int ID){
      this->name = name;
      this->ID = ID;
  }
  void setName(string name){
      this->name = name;
  }
  
  string getName(){
      return name;
  }
  
 void setID(int ID){
      this->ID = ID;
  }
  
  int getID(){
      return ID;
  }
  
 void print(){
     cout << name << " " << ID << endl;
 }
  
  protected:
  string name;
  int ID;
};

class Student : public Person {
  public:
  Student(string name, int ID, double GPA) : Person(name, ID){
      this->GPA = GPA;
  }
  
  void setGPA(double GPA){
        if(GPA >= 0.0 && GPA <= 4.0){
            this->GPA = GPA;
        }
  }
  
  double getGPA(){
      return GPA;
  }
  
  void print(){
      cout << name << " " << ID << " " << GPA << endl;
  }
  
  private:
  double GPA;
    
};

class Faculty : public Person{
  public:
  Faculty(string name, int ID, double salary) : Person(name, ID){
        if(salary >= 0.0){
            this->salary = salary;
        }
  }
  
  double getSalary(){
      return salary;
  }
  
  void print(){
      cout << name << " " << ID << " " << salary << endl;
  }
  
  private:
    double salary;
};

int main(){
    
    Student s("Sam", 801650489, 2.8);
    Faculty f("Conrad", 800516492, 120000);
    
    s.print();
    f.print();
    
    
    return 0;
}