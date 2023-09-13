// Homework
/*
Write a short recursive C++ function that determines if a string s is a
palindrome, that is, it is equal to its reverse. For example, "racecar"
and "gohangasalamiimalasagnahog" are palindromes.
Note: Your implementation has to be recursive. Zero points for non-recursive code
even if it's correct.
*/
#include <iostream>
#include <string>

using namespace std;

bool isPalinHelper(string& s, int begin, int end) {
// Your code here
    if(s[begin] == s[end]){
        return true;
    }
    else{
        return false;
    }
    return isPalinHelper(s, begin + 1, end - 1);
}

bool isPalin(string& s) {
    return isPalinHelper(s, 0, s.size()-1);
}

int main() {
    string s1{"racecar"}; // Palindrome
    if(isPalin(s1)) cout << s1 << " is a palindrome" << endl;

    else cout << s1 << " is not a palindrome" <<  endl;

    string s2{"racecars"}; // Not a palindrome

    if(isPalin(s2)) cout << s2 << " is a palindrome" << endl;

    else cout << s2 << " is not a palindrome" <<  endl;

    string s3{"gohangasalamiimalasagnahog"};

    if(isPalin(s3)) cout << s3 << " is a palindrome" << endl;

    else cout << s3 << " is not a palindrome" <<  endl;

    string s4{"palestine"};

    if(isPalin(s4)) cout << s4 << " is a plindrome" << endl;

    else cout << s4 << " is not a palindrome" << endl;

    string s5{"gg"};

    if(isPalin(s5)) cout << s5 << " is a palindrome" << endl;

    else cout << s5 << " is not a palindrome" << endl;
}
