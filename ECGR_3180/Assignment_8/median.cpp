#include <iostream>
#include <queue>
#include <vector>

const int MAX_VAL = 100;
const int NUM_ELEM = 15;

using namespace std;

// Helper function to print queue for debugging
template<typename T>
void printQueue(T& q) {
    T q_copy(q);
    while (!q_copy.empty()) {
        cout << q_copy.top() << " ";
        q_copy.pop();
    }
    cout << endl;
}

vector<double> findMedian(vector<int>& data) {
    priority_queue<int> max_heap; // Max-heap to store the smaller half of the numbers
    priority_queue<int, vector<int>, greater<int>> min_heap; // Min-heap to store the larger half of the numbers
    vector<double> res;

    for (int i = 0; i < data.size(); i++) {
        // Insert the element into the appropriate heap
        if (max_heap.empty() || data[i] < max_heap.top()) {
            max_heap.push(data[i]);
        } else {
            min_heap.push(data[i]);
        }

        // Balance the heaps
        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

        // Calculate and store the median
        if (max_heap.size() == min_heap.size()) {
            res.push_back((max_heap.top() + min_heap.top()) / 2.0);
        } else {
            res.push_back(max_heap.top());
        }
    }

    return res;
}

int main() {
    vector<int> data_stream = {5, 42, 29, 85, 95, 99, 2, 15};
    vector<double> median_stream = findMedian(data_stream);

    for (auto ele : median_stream) {
        cout << ele << " ";
    }

    cout << endl;
}
