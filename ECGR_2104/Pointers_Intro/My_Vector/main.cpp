#include <iostream>
#include <string.h>

using namespace std;

bool verbose = false;

class MyVector{
    public:
    MyVector(){
        nextIdx = 0;
        arraySize = 3;
        a = new int[arraySize];
    }
    
    MyVector(const MyVector& rhs){
        if(verbose) cout << "Copy Constructor called!" << endl;
        nextIdx = rhs.nextIdx;
        arraySize = rhs.arraySize;
        
        a = new int[arraySize];
        for(int i = 0; i < nextIdx; i++){
            a[i] = rhs.at(i);
        }
    }
    
    ~MyVector(){
        if(verbose) cout << "Destructor called!" << endl;
        delete[] a;
    }
    
    void operator=(const MyVector& rhs){
        if(verbose) cout << "Assignment operator override called!" << endl;
        delete[] a;
        
        nextIdx = rhs.nextIdx;
        arraySize = rhs.arraySize;
        
        a = new int[arraySize];
        for(int i = 0; i < nextIdx; i++){
            a[i] = rhs.at(i);
        }
    }
    
    void push_back(int val){
        if(nextIdx == arraySize){
            if(verbose) cout << "Reallocating more space..." << endl;
            int* temp = new int[arraySize*2];
            for(int i = 0; i < arraySize; i++){
                temp[i] = a[i];
            }
            delete[] a;
            a = temp;
            arraySize = arraySize * 2;
        }
        
        a[nextIdx] = val;
        nextIdx++;
    }
    
    void pop_back(){
        nextIdx--;
    }
    
    int& at(int idx) const{
        return a[idx];
    }
    
    int size(){
        return nextIdx;
    }
    
    int* a;
    
    private:
    
    int nextIdx;
    int arraySize;
};


void makesProblem(){
    MyVector v;
    
    v.push_back(10);
    v.push_back(8);
    v.push_back(5);
    v.push_back(7);
    
    v.pop_back();
    v.pop_back();
    
    v.push_back(20);
    v.at(0) = 40;
    
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << endl;
    }
    
    MyVector v2;
    v2.push_back(10);
    v2.push_back(8);
    v2.push_back(5);
    v2.push_back(7);
    
    v2 = v;
    
    for(int i = 0; i < v2.size(); i++){
        cout << v2.at(i) << endl;
    }
    
    MyVector v3 = v;
    
    if(verbose) cout << "End of function call!" << endl;
}

int main(int argc, char* argv[]){
    
    cout << argc << endl;
    
    string str(argv[0]);
    
    for(int i = 0; i < argc; i++){
        if((argv[i])[0] == '-'){
            if((argv[i])[1] == 'v'){
                verbose = true;
            }
        }
        
        if(strcmp(argv[i],"--verbose") == 0){
            verbose = true;
        }
    }
    
    makesProblem();
    
    makesProblem();
    
    makesProblem();

    
    return 0;
}