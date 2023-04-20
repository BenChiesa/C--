#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* previous;
};

class DoublyLinkedList{
  public:
  DoublyLinkedList();
  
  DoublyLinkedList(const DoublyLinkedList& dll);
  ~DoublyLinkedList();
  DoublyLinkedList& operator=(const DoublyLinkedList& dll);
  
  void push(int data);
  void insert(int data, int index);
  void pop();
  int size() const;
  void remove(int index);
  void print();
  int& at(int index) const;
  
  private:
  Node* head;
  Node* tail;
};

#endif