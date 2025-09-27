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
    TreeNode* BST(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        int mid = (left+right)/2;
        TreeNode* midNode = new TreeNode(nums[mid]);

        midNode->left = BST(nums, left, mid-1);
        midNode->right = BST(nums, mid+1, right);

        return midNode;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST(nums, 0, nums.size() - 1);
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<int> nums = {0,-10,5,NULL,-3,NULL,9};
    // TreeNode* Tre
    // Well I don't know how to print it, so forget it btw
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Lời giải dựa trên tuật toán binary search ?
*/