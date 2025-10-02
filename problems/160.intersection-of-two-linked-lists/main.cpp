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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;
        while (ptr1 != ptr2) {
            if (ptr1 == nullptr) {
                ptr1 = headB;
            } else {
                ptr1 = ptr1->next;
            }

            if (ptr2 == nullptr) {
                ptr2 = headA;
            } else {
                ptr2 = ptr2->next;
            }
        }

        return ptr1;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);
    
    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next;
    headB->next->next->next->next = headA->next->next->next;
    headB->next->next->next->next->next = headA->next->next->next->next;
    ListNode *res = sol.getIntersectionNode(headA, headB);
    while (res != nullptr) {
        cout << (*res).val << " ";
        res = res->next;
    }
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Giải thích thông tin:
        + Cho 2 listnode a và b, kiểm tra xem nó trùng giá trị từ đâu
        + Trả về listnode đoạn đã bị gộp
    - Các ràng buộc cần lưu ý:
        + Độ dài của cả 2 list đều không quá 3*10^4
        + Giá trị của node không quá 10^5
    -> Lặp liên tục nếu hai con trỏ này khác nhau, nếu mà 1 trong 2 đọc đến cuối (null) thì gán cho nó đầu của listnode kia,
    trong quá trình đọc thì cho 2 con trỏ tăng, gặp trùng nhau thì vòng ngoài không chạy nữa và trả về list1 (phần tử trùng vừa loop tới)
        => O(m+n), Space(1)
*/