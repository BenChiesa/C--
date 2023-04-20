#include <iostream>

using namespace std;

int main(){
    int a, b, d, temp1, temp2, r;
    
    cout << "Input 2 numbers to find the greatest common divisor between the two" << endl;
    cin >> a;
    cin >> b;
    
    //Makes sure that a is greater than b
    if(b > a){
        temp1 = a;
        temp2 = b;
        a = temp2;
        b = temp1;
        
    }
    
    //If two numbers that are the same are inputted, the program outputs the same number
    else if(a == b){
        cout << "The greatest common divisor between the two numbers is " << a <<"." << endl; 
        exit;
    }
    
    //Repeast the euclidean algorithm until the remainder equals 0
    do{
        d = a / b;
        r = a % b;
        a = b;
        b = r;
    }while(r != 0);
    
    cout << "The greatest common divisor between the two numbers is " << abs(a) << endl;
    
    return 0;
} 