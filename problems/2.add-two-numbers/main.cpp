#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode();
        ListNode* res = newHead;
        int remem = 0;
        while (l1 != nullptr && l2 != nullptr) {
            int cal = l1->val + l2->val + remem;
            newHead->next = new ListNode(cal%10);
            remem = cal/10;
            newHead = newHead->next; l1 = l1->next; l2 = l2->next;
        }
        while (l1 != nullptr) {
            int cal = l1->val + remem;
            newHead->next = new ListNode(cal%10);
            remem = cal/10;
            newHead = newHead->next; l1 = l1->next;
        }
        while (l2 != nullptr) {
            int cal = l2->val + remem;
            newHead->next = new ListNode(cal%10);
            remem = cal/10;
            newHead = newHead->next; l2 = l2->next;
        }
        if (remem != 0) {
            newHead->next = new ListNode(remem);
            newHead = newHead->next;
        }    
        newHead->next = nullptr;

        return res->next;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    ListNode* head1 = new ListNode(2);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(3);
    ListNode* head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(4);
    ListNode* res = sol.addTwoNumbers(head1, head2);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây

*/