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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res = new ListNode;
        ListNode* newList = res;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                newList->next = list1;
                list1 = list1->next;
            } else {
                newList->next = list2;
                list2 = list2->next;
            }
            newList = newList->next;
        }
        // Khi 1 trong 2 kết thúc thì gắn đuôi newList vào đầu list nào còn node
        if (list1) newList->next = list1;
        if (list2) newList->next = list2;
        // node đầu chưa có gì, di chuyển lên 1 node
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
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    ListNode* merged = sol.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(merged);
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    -> Khi gặp bài có node liên quan tới node mới thì tạo 2 cái listnode mới với list2 chạy đến đuôi còn list1 nằm ở đầu
        => O(n1+n2)
*/