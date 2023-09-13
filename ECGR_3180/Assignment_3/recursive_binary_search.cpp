#include <iostream>
#include <vector>

using namespace std;

int searchHelper(const vector<int>& v, int num, int left, int right){
    if(left > right){
        return -1;
    }

    int mid = left + (right - left) / 2; // Calculate the middle index.

    if(v[mid] == num){ // If the middle element is equal to the target, return its index.
        return mid;
    }

    if(v[mid] > num){ // If the middle element is greater than the target, search the left half.
        return searchHelper(v, num, left, mid - 1);
    }

    return searchHelper(v, num, mid + 1, right); // If the middle element is less than the target, search the right half.
}

int search(const vector<int>& v, int num){
    return searchHelper(v, num, 0, v.size() - 1);
}

int main(){
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 10}; //Test where num is not in list
    vector<int> v2{1, 2, 3, 7, 9}; // Test where num is in list
    vector<int> v3{9}; // Test where num is the only thing in list
    vector<int> v4{}; //Test where list is empty
    vector<int> v5{1, 2, 3, 9, 9}; //Test where num appears twice
    int num = 9;
    
    if(search(v1, num) != -1) cout << num << " is at index " << search(v1, num) << endl; //False
    else cout << num << " is not in the list" << endl;

    if(search(v2, num) != -1) cout << num << " is at index " << search(v2, num) << endl; //At index 4
    else cout << num << " is not in the list" << endl;

    if(search(v3, num) != -1) cout << num << " is at index " << search(v3, num) << endl; //At index 0
    else cout << num << " is not in the list" << endl;

    if(search(v4, num) != -1) cout << num << " is at index " << search(v4, num) << endl; //False
    else cout << num << " is not in the list" << endl;

    if(search(v5, num) != -1) cout << num << " is at index " << search(v5, num) << endl; //At index 3
    else cout << num << " is not in the list" << endl;

    return 0;
}