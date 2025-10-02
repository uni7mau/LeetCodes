#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;

        ListNode *node1 = head;
        ListNode *node2 = head;

        while (node1 != nullptr && node2 != nullptr) {
            node1 = node1->next;
            node2 = node2->next;
            if (node2 != nullptr) node2 = node2->next;
            if (node1 == node2) return true;
        }

        return false;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;
    bool res = sol.hasCycle(head);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Giải thích thông tin:
        + Cho một ListNode
        + Hãy kiểm tra xem listnode này quay ngược lại ở vị trí nào, nếu không có thì in ra -1
    - Ràng buộc cần lưu ý:
        + Tối đa 10^4 số lượng node
        + Giá trị trong [-10^5 -> 10^5]
        + Không truyền vào tham số mà truyền vào con trỏ
    -> Cho 2 node đuổi nhau bằng cách để node 2 đi 2 bước và node 1 đi 1 bước, đằng nào cũng phải gặp nhau.
    => O(n)
*/