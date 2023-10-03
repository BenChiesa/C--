/*
Leetcode Problem 242 - Valid Anagram
Given two strings s and t, return true if t is an anagram of s, and false
otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different
word or phrase,
typically using all the original letters exactly once.
Example 1:
Input: s = "anagram", t = "nagaram"
Output: true
Example 2:
Input: s = "rat", t = "car"
Output: false
Constraints:
1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
NOTE: Your code has to run in O(n) time where n is the number of letters.
Zero points for any non-O(n) algorithm.
*/
#include <iostream>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t);

int main(){
    string s = "anagram";
    string t = "nagaram";

    if(isAnagram(s, t)) cout << "True" << endl;
    else cout << "False" << endl;

    s = "rat";
    t = "car";

    if(isAnagram(s, t)) cout << "True" << endl;
    else cout << "False" << endl;

    s = "crow";
    t = "tree";

    if(isAnagram(s, t)) cout << "True" << endl;
    else cout << "False" << endl;

    s = "change";
    t = "change";

    if(isAnagram(s, t)) cout << "True" << endl;
    else cout << "False" << endl;

    s = "bat";
    t = "train";

    if(isAnagram(s, t)) cout << "True" << endl;
    else cout << "False" << endl;
}
bool isAnagram(string s, string t){
// Your code here
    if(size(s) != size(t)) return false;
    
    unordered_map<char, int> counter;

    for(char c: s) counter[c]++;
    
    for(char c : t){
        if(counter.find(c) == counter.end()) return false;
        counter[c]--;
    }

    return true;
}

