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
private:
    int dfs(TreeNode* node, bool left) {
        if (!node) return 0;
        if (!node->left && !node->right) return left ? node->val : 0; 
        
        int leftSum = dfs(node->left, true);
        int rightSum = dfs(node->right, false);
        return leftSum + rightSum;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------

    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Cho cái cây, trả về giá trị tổng của tất cả các lá bên trái
    -> dfs() cho tới khi gặp node không có trái và phải thì trả về giá trị nếu nó là node trái không thì trả về 0
*/