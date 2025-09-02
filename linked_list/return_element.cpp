//return kth to the last element
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//bruteforce solution
int return_element(ListNode* head,int k){
    int count = 0;
    ListNode* temp = head;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    temp = head;
    for(int i=1;i<count-k+1;i++){
        temp = temp->next;
    }
    return temp->val;
    
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    

    cout<< return_element(head,2);


    return 0;
}