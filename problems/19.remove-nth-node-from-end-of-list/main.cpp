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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* res = head;

        stack<ListNode*> st;
        while (head != nullptr) {
            st.push(head);
            head = head->next;
        }

        if (st.size() == 1 && n == 1) return head;
        if (st.size() == n) return res->next;

        if (n == 0) {
            st.pop();
            st.top()->next = nullptr;
        } else {
            int cnt = 0;
            while (!st.empty() && cnt < n) {
                st.pop();
                cnt++;
            }

            ListNode* prevNode = st.top();
            prevNode->next = prevNode->next->next;
        }

        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);

    int n = 2;
    ListNode* res = sol.removeNthFromEnd(head, n);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Lại là queue thôi
*/