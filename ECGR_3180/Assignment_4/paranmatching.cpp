/*
Write a function that returns if a string of paranthesis are matched.
You are required to use the STL stack datastructure in your code for O(n) time
complexity.
See 5.17 in the book for problem description and a stack based algorithm.
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// function to check if paranthesis are balanced
bool areParanthesisBalanced(string expr){
// Your code here
    stack<char> s;

    for(char ch : expr) {
        if(ch == '(' || ch == '[' || ch == '{') s.push(ch);
        else if (ch == ')' || ch == ']' || ch == '}'){
            if(s.empty()) return false; // No matching opening parenthesis
            
            char top = s.top();

            if((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{')) s.pop(); // Matching parentheses found, pop the stack
            
            else return false; // Mismatched parentheses
        }
    }
    // Check if the stack is empty at the end (all parentheses are matched)
    return s.empty();
}

// Test - DO NOT MODIFY
int main(){
    vector<string> parans = {"{()}[]", "[[", "))", "{[()]}", "({[])}"};
    for(auto expr : parans){
        if(areParanthesisBalanced(expr)) cout << "Balanced" << endl;

        else cout << "Not Balanced" << endl;
    }
    return 0;
}
