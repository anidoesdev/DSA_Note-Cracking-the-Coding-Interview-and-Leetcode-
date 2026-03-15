#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int return_element(ListNode* head, int k) {
    ListNode* first = head;
    ListNode* second = head;
    for (int i = 0; i < k; i++) {
        first = first->next;
    }
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }
    return second->val;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << return_element(head, 2);

    return 0;
}