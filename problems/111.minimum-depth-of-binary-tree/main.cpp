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
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return left == 0 || right == 0 ? left + right + 1 : min(left, right) + 1;
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
    int res = sol.minDepth(head);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Như bài tìm sâu nhất
    -> DFS lấy min, nhưng khác ở chỗ nếu chỉ có 1 node thì không phải độ sâu (cái node root ấy) nên là thêm
    trường hợp đấy không thì gọi dfs 2 nhánh con của nó, nếu 0 thì bỏ th đó đi ...
*/