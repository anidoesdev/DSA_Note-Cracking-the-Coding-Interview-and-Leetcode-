```cpp
#include<iostream>
#include<cmath>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* sum_list(ListNode* head1,ListNode* head2,int carry){
    if (head1 == NULL && head2 == NULL && carry == 0) {
        return NULL;
    }
    int value = carry;
    if(head1!=NULL){
        value+=head1->val;
    }
    if(head2!=NULL){
        value+=head2->val;
    }
    ListNode* res = new ListNode(value % 10);
    res->next = sum_list(head1 == NULL ? NULL : head1->next, head2 == NULL ? NULL : head2->next, value >= 10 ? 1 : 0);
    return res;
}

void printList(ListNode* node){
    while(node!=nullptr){
        cout<< node->val << "->";
        node = node->next;
    }
    cout<< "NULL"<< endl;
}

int main(){
    ListNode* head1 = new ListNode(3);
    head1->next = new ListNode(5);
    head1->next->next = new ListNode(8);

    ListNode* head2 = new ListNode(3);
    head2->next = new ListNode(5);
    head2->next->next = new ListNode(8);

    printList(sum_list(head1,head2,0));

    return 0;
}
```