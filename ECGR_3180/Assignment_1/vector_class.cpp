#include <iostream>
#include <vector>

using namespace std;

class MyVector{
    public:
    MyVector(){
        nextIdx = 0;
        sz = 0;
        a = nullptr;
    }

    MyVector(int sz){
        a = new int[sz];
        nextIdx = 0;
    }

    MyVector(MyVector& vin){
        nextIdx = vin.nextIdx;
        sz = vin.sz;
            
        a = new int[sz];
        for(int i = 0; i < nextIdx; i++){
            a[i] = vin.at(i);
        }
    }

    void pushBack(int ele){
        if(nextIdx == sz){
            int* temp = new int[sz*2];
            for(int i = 0; i < sz; i++){
                temp[i] = a[i];
            }
            delete[] a;
            a = temp;
            sz = sz * 2;
        }
        
        a[nextIdx] = ele;
        nextIdx++;
    }

    void insert(int i, int ele){
        if (nextIdx >= sz) {
            int newsz = (sz == 0) ? 1 : sz * 2;
            int* newa = new int[newsz];
            for (int j = 0; j < i; ++j) {
                newa[j] = a[j];
            }
            newa[i] = ele;
            for (int j = i; j < nextIdx; ++j) {
                newa[j + 1] = a[j];
            }
            delete[] a;
            a = newa;
            sz = newsz;
        } 
        
        else {
            for (int j = nextIdx; j > i; --j) {
                a[j] = a[j - 1];
            }
            a[i] = ele;
        }
        ++nextIdx;
    }

    int at(int i){
        return a[i];
    }

    int& operator[](int i){
        return a[i];
    }

    void erase(int i){
        for (int j = i; j < nextIdx - 1; ++j) {
            a[j] = a[j + 1];
        }
        --nextIdx;
    }

    int size(){
        return nextIdx;
    }

    bool empty(){
        return nextIdx == 0;
    }

    ~MyVector(){
        delete[] a;
    }


    private: 
    int* a;
    int nextIdx;
    int sz;

};

int main(){
    MyVector vec1;      // 0 0
    vec1.pushBack(35);  // 35 0
    vec1.pushBack(22);  // 35 22
    vec1.pushBack(1);   // 35 22 1 0
    vec1.pushBack(24);  // 35 22 1 24
    vec1.pushBack(18);  // 35 22 1 24 18 0 0 0
    vec1.pushBack(16);  // 35 22 1 24 18 16 0 0
    vec1.insert(2, 555);// 35 22 55 1 24 18 16 0
    cout << "Element at index 2: " << vec1.at(2) << endl; // Should print 555
    vec1.erase(3);      // 35 22 55 24 18 16 0 0

    for (int i = 0; i < vec1.size(); i++) {
        cout << vec1[i] << " "; // Should print 35 22 555 18 16
    }
    cout << endl;

    return 0;
}