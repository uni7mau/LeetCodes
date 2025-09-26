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
    bool check(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;

        if (!p || !q || p->val != q->val) return false;
        
        return check(p->left, q->right) && check(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->left->left = new TreeNode(3);
    head->left->right = new TreeNode(4);
    head->right = new TreeNode(2);
    head->right->right = new TreeNode(3);
    head->right->left = new TreeNode(4);
    bool res = sol.isSymmetric(head);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    -> Copy lại bài 100, đổi tí
*/