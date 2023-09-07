#include <iostream>

using namespace std;

struct ListNode{
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    ListNode temp(0);
    ListNode* current = &temp;
    while(list1 && list2){
            if (list1->val < list2->val){
                current->next = list1;
                list1 = list1->next;
            } 
            else{
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        if(list1){
            current->next = list1;
        } 
        else if(list2){
            current->next = list2;
        }

        return temp.next; 
    }
};

void printList(ListNode* head){
    while(head){
        cout << head->val << "-";
        head = head->next;
    }
    cout << "null\n";
}

int main(){
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(mergedList);

    while (mergedList){
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}