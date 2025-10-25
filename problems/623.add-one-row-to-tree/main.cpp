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
    TreeNode* BFS(TreeNode* node, int val, int depth, int curr) {
        if (!node) return nullptr;

        if (curr == depth-1) {
            TreeNode* left = node->left;
            TreeNode* right = node->right;

            node->left = new TreeNode(val);
            node->right = new TreeNode(val);

            node->left->left = left;
            node->right->right = right;

            return node;
        }

        node->left = BFS(node->left, val, depth, curr+1);
        node->right = BFS(node->right, val, depth, curr+1);

        return node;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;

            return newRoot;
        }

        return BFS(root, val, depth, 1);
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

*/