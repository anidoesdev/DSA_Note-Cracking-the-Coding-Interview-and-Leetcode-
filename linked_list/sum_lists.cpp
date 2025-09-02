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
    //by taking numbers in reverse order
    ListNode* res = new ListNode();
    int value = carry;
    if(head1!=NULL){
        value+=head1->val;
    }
    if(head2!=NULL){
        value+=head2->val;
    }
    res->val = value%10;
    if(head1!=NULL || head2!=NULL){
        ListNode* sum = sum_list(head1==NULL ? NULL : head1->next,head2==NULL ? NULL : head2->next,value>=10 ? 1 : 0);
        res->next = sum;
    }
    return res;

    //by taking in forward order
    // int count1 = 0;
    // ListNode* temp1 = head1;
    // while(temp1!=NULL){
    //     count1++;
    //     temp1 = temp1->next;
    // }
    // temp1 = head1;
    // int num1 = 0;
    // for(int i=count1;i>0;i--){
    //     num1=((pow(10,i-1))*temp1->val)+num1;
    //     temp1 = temp1->next;
    // }
    // int count2 = 0;
    // ListNode* temp2 = head2;
    // while(temp2!=NULL){
    //     count2++;
    //     temp2 = temp2->next;
    // }
    // temp2 = head2;
    // int num2 = 0;
    // for(int i=count2;i>0;i--){
    //     num2+=pow(10,i-1)*temp2->val;
    //     temp2 = temp2->next;
    // }
    // return num1+num2;
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