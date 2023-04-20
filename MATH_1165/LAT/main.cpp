#include <iostream>

using namespace std;

int main(){
    double n = 1, routes, x, dimensions, r = 1;
    
    cout << "Enter the dimensions of the grid" << endl;
    cin >> dimensions;
    
    //The if statement creates the bounds for any integer n >= 1
    if(dimensions >= 1){
        //Since repetition is not allowed and order doesn't matter you can use the nCk formula
        x = dimensions * 2;
        //Factorial of the 2*nth term counting down to the nth term
        for(int i = x; i > dimensions; i--){
            n = i * n;
        }
        //Factorial of the nth term
        for(int i = dimensions; i > 0; i--){
            r = i * r;
        }
        //Dividing the factorial of n by the factorial of k
        routes = n / r;
        cout << "The total number of routes are " << routes << endl;
    }
    
    else{
        cout << "Dimensions of the grid are out of scope" << endl;
    }
    
    return 0;
}