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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;

        vector<int> res;
        while (root || !st.empty()) {
            while (root) {
                res.push_back(root->val);
                st.push(root);
                root = root->right;
            }
            
            root = st.top(); st.pop();
            root = root->left;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    vector<int> res = sol.postorderTraversal(root);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Ngày hôm nay ta cùng họp hoan nơi đây, mọi người bên nhau ta cùng traversal
    - Các bài toán về traversal có chung 1 template giải, chỉ khác ở chỗ "khi nào cần đến value"
*/