#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL){}
};

bool hasCycle(Node *head){
    if(!head || !head->next) return false;
    
    Node *slow = head;
    Node *fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

int main(){
    Node *head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(-4);
    head->next->next->next->next = new Node(1); 

    if (hasCycle(head)) {
        cout << "The linked list has a cycle." << endl;
    } else {
        cout << "The linked list does not have a cycle." << endl;
    }

    delete head->next->next->next->next;
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(-4);
    head->next->next->next->next = head->next; 

    if (hasCycle(head)) {
        cout << "The linked list has a cycle." << endl;
    } else {
        cout << "The linked list does not have a cycle." << endl;
    }

    delete head->next->next->next->next;
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;
}