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
    ListNode* start = head;
    ListNode* end = head;
    while(head != NULL){
        ListNode* temp = head->next;
        if(head->val < partition){
            head->next = start;
            start = head;
        }else{
            end->next = head;
            end = head;
        }
        head = temp;

    }
    end->next = NULL;
    return start;
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