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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* res = head;

        while (res != nullptr) {
            while (res->next != nullptr && res->next->val == val) {
                res->next = res->next->next;
            }
            res = res->next;
        }
        
        if (head != nullptr && head->val == val) return head->next;
        return head;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    int val = 6;
    ListNode* res = sol.removeElements(head, val);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Cách này stupid quá mà thôi kệ
*/