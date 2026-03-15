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
    ListNode* prev = NULL;
    while(head!=NULL){
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
bool isPalindrome(ListNode* head){
    if (head == NULL) return true;
    ListNode* endOfFirstHalf = endOfFirstHalfFunc(head);
    ListNode* second = reverseList(endOfFirstHalf->next);
    bool result = true;
    ListNode* firstPosition = head;
    ListNode* secondPosition = second;
    while (result && secondPosition != NULL) {
        if (firstPosition->val != secondPosition->val) result = false;
        firstPosition = firstPosition->next;
        secondPosition = secondPosition->next;
    }     
    endOfFirstHalf->next = reverseList(second);
    return result;
}
ListNode* endOfFirstHalfFunc(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    while (curr != NULL) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}
int main(){
    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(0);

    cout<< isPalindrome(head);

    return 0;
}