#include<iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* reverse(ListNode* head){
    ListNode* temp = NULL;
    while(head!=NULL){
        ListNode* n = new ListNode(head->val);
        n->next = temp;
        temp = n;
        head = head->next;
    }
    return temp;
}
bool isPalindrome(ListNode* head,ListNode* reverse){
    while(head!=NULL && reverse!=NULL){
        if(head->val != reverse->val){
            return false;
        }
        head = head->next;
        reverse = reverse->next;
    }
    return true;
}
//different approaches left
int main(){
    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(0);

    ListNode* node = head;
    ListNode* rev = reverse(head);

    cout<< isPalindrome(node,rev);

    return 0;
}