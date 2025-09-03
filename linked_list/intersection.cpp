#include<iostream>
#include<map>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//naive solution
ListNode* findIntersection(ListNode*head1,ListNode*head2){
    map<ListNode*,int> mp;
    while(head1!=NULL){
        mp[head1]++;
        head1 = head1->next;
    }
    while(head2!=NULL){
        if(mp.find(head2)!=mp.end()){
            return head2;
        }
        head2 = head2->next;
    }
    return NULL;
}
void insertNode(ListNode* &node,int val){
    ListNode* newNode = new ListNode(val);
    if(node == NULL){
        node = newNode;
        return;
    }
    ListNode* temp = node;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return;

}
void printList(ListNode* node){
    while(node!=nullptr){
        cout<< node->val << "->";
        node = node->next;
    }
    cout<< "NULL"<< endl;
}



int main(){
    ListNode* head = NULL;
    insertNode(head,1);
    insertNode(head,3);
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,4);
    ListNode* head1 = head;
    head = head->next->next->next;
    ListNode* headSec = NULL;
    insertNode(headSec,3);
    ListNode* head2 = headSec;
    headSec->next = head;

    printList(head1);
    printList(head2);

    ListNode* res = findIntersection(head1,head2);
    cout<< res->val;


    return 0;
}