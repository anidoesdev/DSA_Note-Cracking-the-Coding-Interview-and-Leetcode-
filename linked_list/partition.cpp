#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* partition(ListNode* head,int partition){
    ListNode* before = new ListNode(0);
    ListNode* beforeHead = before;
    ListNode* after = new ListNode(0);
    ListNode* afterHead = after;

    while(head != NULL){
        if(head->val < partition){
            before->next = head;
            before = before->next;
        }else{
            after->next = head;
            after = after->next;
        }
        head = head->next;
    }
    after->next = NULL;
    before->next = afterHead->next;
    return beforeHead->next;
}

void printList(ListNode* node){
    while(node!=nullptr){
        cout<< node->val << "->";
        node = node->next;
    }
    cout<< "NULL"<< endl;
}

int main(){
    ListNode* head = new ListNode(3);
    head->next = new ListNode(5);
    head->next->next = new ListNode(8);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(10);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(1);

    printList(head);
    ListNode* start = partition(head,5);
    printList(start);
    return 0;
}