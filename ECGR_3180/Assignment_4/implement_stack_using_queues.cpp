#include <iostream>
#include <queue>

using namespace std;

class MyStack{
    private:
        queue<int> q1;
        queue<int> q2;

    public:
        MyStack() {}

        void push(int x){
            q1.push(x);
        }

        int pop(){
            while(q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }

            int top_element = q1.front();
            q1.pop();

            swap(q1, q2);
            return top_element;
        }

        int top(){
            while(q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }
            int top_element = q1.front();

            q2.push(q1.front());
            q1.pop();

            swap(q1, q2);

            return top_element;
        }

        bool empty(){
            return q1.empty();
        }
};

int main(){
    MyStack stack;
    stack.push(1);
    stack.push(2);
    cout << stack.top() << endl;   
    cout << stack.pop() << endl;   
    cout << stack.empty() << endl; 
    return 0;
}