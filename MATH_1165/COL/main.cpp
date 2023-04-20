#include <iostream>

using namespace std;

int main(){
    int a1, term = 1;
    
    cout << "This program takes an input and applies the Collatz Sequence to it" << endl;
    cout << "The program will display the total length of the sequence and how many terms it took for the inputted number to reach 1." << endl;
    cout << "Enter a positive integer." << endl;
    cin >> a1;
    
    while(a1 != 1){
        //Determines if a1 is even
        if((a1 % 2) == 0){
            //Recursive formula for even input
            a1 = a1 / 2;
        }
        //Determines if a1 is odd
        else if((a1 % 2) == 1){
            //Recrusive formula for odd input
            a1 = (a1 * 3) + 1;
        }
        
        cout << a1 << endl;
        //Couts the amount of terms in a sequence 
        term++;
        
    }
    
    cout << "The sequence is made up of " << term << " term(s)." << endl;
    
    return 0;
}