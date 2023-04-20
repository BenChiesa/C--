#include "doubly_linked_list.h"

DoublyLinkedList::DoublyLinkedList(){
    head = NULL;
    tail = NULL;
}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& rhs){
    cout << "Copy constructor called!" << endl;
    head = nullptr;
    tail = nullptr;
    Node* temp = rhs.head;
    while(temp != NULL){
        push(temp->data);
        temp = temp->next;
    }
}

DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& rhs){
    if(this != &rhs){
        Node* temp = head;
        while(temp != NULL){
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        
        head = NULL;
        tail = NULL;
        
        temp = rhs.head;
        while(temp != NULL){
            push(temp->data);
            temp = temp->next;
        }
    }
    
    return *this;
}

DoublyLinkedList::~DoublyLinkedList(){
    cout << "Destructor called!" << endl;
    Node* temp = head;
    while(temp != nullptr){
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
}

void DoublyLinkedList::push(int data){
    cout << "Adding Data" << endl;
    if(head == nullptr){
        head = new Node;
        head->data = data;
        head->previous = nullptr;
        head->next = nullptr;
        tail = head;
        return;
    }
    
    Node* currentNode = tail;
    currentNode->next = new Node;
    currentNode->next->next = nullptr;
    currentNode->next->data = data;
    tail = currentNode->next;
}

void DoublyLinkedList::pop(){
    Node* currentNode = head;
    
    if(head == nullptr){
        return;
    }
    
    if(currentNode->next == nullptr){
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    
    while(currentNode->next->next != nullptr){
        tail = currentNode;
    }
    
    delete currentNode->next;
    currentNode->next = nullptr;
}

int DoublyLinkedList::size() const{
    cout << "Getting size" << endl;
    Node* temp = head;
    int count = 0;
    if(temp == nullptr){
        return count;
    }
    
    while(temp != nullptr){
        temp = temp->next;
        count++;
    }
    return count;
}

void DoublyLinkedList::print(){
    cout << "Printing List" << endl;
    Node* temp = head;
    if(head == nullptr){
        cout << "There is nothing in this list" << endl;
        return;
    }
    while(temp != tail){
        cout << temp << endl;
        temp = temp->next;
    }
    return;
}

int& DoublyLinkedList::at(int idx) const{
    cout << "Finding index" << endl;
    Node* currentNode = head;
    int i = 0;
    if(idx >= size()){
        cout << "THere is no data stored in the list" << endl;
    }
    while(i < idx){
        currentNode = currentNode->next;
        i++;
    }
    return currentNode->data;
}

void DoublyLinkedList::insert(int data, int idx){
    cout << "Inserting Data" << endl;
    if(idx > size()){
        return;
    }
    
    if(idx == 0){
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        newNode->previous = NULL;
        
        if(head != NULL){
            head->previous = newNode;
        }
        
        head = newNode;
        
        if(tail == NULL){
            tail = newNode;
        }
        
    }
    
    else if(idx == size()){
        push(data);
    }
    
    else{
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        newNode->previous = NULL;
        
        Node* temp = head;
        for(int i = 0; i < idx - 1; i++){
            temp = temp->next;
        }
        
        newNode->next = temp->next;
        newNode->previous = temp;
        temp->next->previous = newNode;
        temp->next = newNode;
        
    }
}

void DoublyLinkedList::remove(int idx){
    cout << "Removing data" << endl;
    if(idx >= size()){
        return;
    }
    
    if(idx == 0){
        Node* temp = head;
        head = head->next;
        head->previous = NULL;
        delete temp;
    }else if(idx == size() - 1){
        pop();
    }else{
        Node* temp = head;
        for(int i = 0; i < idx; i++){
            temp = temp->next;
        }
        
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
        delete temp;
    }
    
}