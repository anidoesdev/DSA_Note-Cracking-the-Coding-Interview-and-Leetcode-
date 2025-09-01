#include <iostream>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    // ListNode() : val(0), next(nullptr) {}
    // ListNode(int x) : val(x), next(nullptr) {}
    // ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void remove_dups(ListNode* head){
    set<int> st;
    ListNode* prev = NULL;
    while(head != nullptr){
        if(st.find(head->val) != st.end()){
            prev->next = head->next;
        }else{
            st.insert(head->val);
            prev = head;
        }
        
        
        head = head->next;
    }
}
//no buffer required 
void using_two_pointer(ListNode* head){
    ListNode* slow = head;
    

    while(slow!=NULL){
        ListNode* fast = slow;
        while(fast->next != NULL){
            if(fast->next->val == slow->val){
                fast->next = fast->next->next;
            }else{
                fast = fast->next;
            }
            
        }
        slow = slow->next;

    }
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
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);

    printList(head);

    // remove_dups(head);
    using_two_pointer(head);


    printList(head);

    return 0;
}




