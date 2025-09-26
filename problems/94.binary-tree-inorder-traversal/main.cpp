#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;

        TreeNode* curr = root;
        vector<int> res;
        while (curr || !st.empty()) {
            // Đi sâu nhất có thể
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top(); st.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }

        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    TreeNode* head = new TreeNode(1);
    TreeNode* right = head;
    head->left = new TreeNode(2);
    TreeNode* leftright = head->left;
    head->left->left = new TreeNode(4);
    leftright->right = new TreeNode(5);
    TreeNode* leftrightright = leftright->right;
    leftrightright->left = new TreeNode(6);
    leftrightright->right = new TreeNode(7);
    right->right = new TreeNode(3);
    right->right->right = new TreeNode(8);
    right->right->right->left = new TreeNode(9);
    vector<int> res = sol.inorderTraversal(head);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Bài bắt in ra giá trị của các node theo kiểu duyệt inorder
        ! Các kiểu duyệt: pre - lấy trái, in - lấy giữa - post - lấy phải (you know if you know)
    -> Duyệt inorder bằng cách:
        - Đi trái sâu nhất, in ra lui, duyệt phải
*/