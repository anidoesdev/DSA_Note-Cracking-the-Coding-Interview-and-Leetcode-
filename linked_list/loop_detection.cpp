#include<iostream>


using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* loop_detection(ListNode* head){
    ListNode* slow = head;
    ListNode* fast= head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }
    if(fast==NULL || fast->next == NULL){
        return NULL;
    }
    slow = head;
    while (slow!=fast){
       slow = slow->next;
       fast = fast->next;
    }
    return fast;
}
void printList(ListNode* node){
    while(node!=nullptr){
        cout<< node->val << "->";
        node = node->next;
    }
    cout<< "NULL"<< endl;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(5);
  
    head->next->next->next->next = head->next;
    
    ListNode* res = loop_detection(head);
    cout<< res->val;

    
    return 0;
}