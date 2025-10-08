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
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> st;
        while (head != nullptr) {
            st.push(head);
            head = head->next;
        }
        
        ListNode* res = new ListNode();
        ListNode* newHead = res;
        while (!st.empty()) {
            ListNode* next = st.top(); st.pop();
            res->next = next;
            res = res->next;
        }
        res->next = nullptr;

        return newHead->next;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* res = sol.reverseList(head);
    while (res) {
        cout << res->val << " ";
        res = res->next; 
    }
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    Hoặc là quăng vào mảng rồi xâu ngược lại
    Hoặc là cái gì đấy, nói chung là chúc mừng năm mới
*/