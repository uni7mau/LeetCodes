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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res = new ListNode;
        ListNode* newList = res;

        while (head) {
            while (head->next && head->val == head->next->val) head->next = head->next->next;
            newList->next = head;
            newList = newList->next;
            head = head->next;
        }

        return res->next;
    }
};
// ------------------------------------------------------------

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    ListNode* list = new ListNode(1);
    list->next = new ListNode(1);
    list->next->next = new ListNode(2);
    list->next->next->next = new ListNode(3);
    list->next->next->next->next = new ListNode(3);

    ListNode* res = sol.deleteDuplicates(list);

    cout << "Merged List: ";
    printList(res);
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Giải thích thông tin: 
        + Cho list, xóa hết trùng rồi trả về đầu node
    - Các ràng buộc cần lưu ý:
        + Số lượng node tối đa là 300
        + Giá trị node vào khoảng -100 đến 100
        + List bị ràng buộc rằng đã sort tăng dần
    -> Lại là di chuyển node
        - Duyệt từ đầu đến cuối, so sánh giá trị node hiện tại với node tiếp theo, nếu trùng thì node->next = node->next->next
        - Sau đó là hết trùng của giá trị hiện tại, giờ gán newlist-> next là node hiện tại, rồi cho newList, head đi lên tiếp (hiểu k)
        => O(n)
*/