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
    int dfs(TreeNode* node) {
        if (!node) return 0;
        else {
            int left = dfs(node->left);
            int right = dfs(node->left);
            return max(left + 1, right + 1);
        }
    }

    int maxDepth(TreeNode* root) {
        return dfs(root) + 1;

        // Dưới này là nháp
        // stack<TreeNode*> st;
        // int res = 0;
        // TreeNode* curr = root;

        // while (curr || !st.empty()) {
        //     while (curr) {
        //         st.push(curr);
        //         curr = curr->left;
        //     }

        //     curr = st.top(); st.pop();
        //     curr = curr->right;
        // }

        // return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    TreeNode* head = new TreeNode(3);
    head->left = new TreeNode(9);
    head->right = new TreeNode(20);
    head->right->left = new TreeNode(15);
    head->right->right = new TreeNode(7);
    int res = sol.maxDepth(head);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    -> Đi được sâu nhất với giá trị cộng dồn -> dfs 2 nhánh
        - val-empty = 0
        - val-midnode = max(val-leftnode + 1, val-rightnode + 1)
*/