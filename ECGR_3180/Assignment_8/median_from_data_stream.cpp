#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num){
        if(max_heap.empty() || num <= max_heap.top()) max_heap.push(num);
        else min_heap.push(num);
    
        // Balance the heaps
        if(max_heap.size() > min_heap.size() + 1){
            min_heap.push(max_heap.top());
            max_heap.pop();
        } 
        else if(min_heap.size() > max_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian(){
        if(max_heap.size() == min_heap.size()) return (max_heap.top() + min_heap.top()) / 2.0;
        else return max_heap.top();
        
    }

private:
    priority_queue<int> max_heap; // Max-heap to store the smaller half
    priority_queue<int, vector<int>, greater<int>> min_heap; // Min-heap to store the larger half
};

int main(){
    MedianFinder medianFinder;
    medianFinder.addNum(1);    // arr = [1]
    medianFinder.addNum(2);    // arr = [1, 2]
    cout << medianFinder.findMedian() << endl; // return 1.5 (i.e., (1 + 2) / 2)
    medianFinder.addNum(3);    // arr[1, 2, 3]
    cout << medianFinder.findMedian() << endl; // return 2.0
    return 0;
}