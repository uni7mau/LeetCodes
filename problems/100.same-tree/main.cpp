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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Cách 1: (Cách này nhìn ngu lắm)
        // if (!p && q || p && !q) return false;

        // TreeNode* pNode = p;
        // TreeNode* qNode = q;
        // stack<TreeNode*> stp;
        // stack<TreeNode*> stq;

        // while ((pNode && qNode) || (!stp.empty() && !stq.empty())) {
        //     while (pNode && qNode && pNode->val == qNode->val) {
        //         stp.push(pNode);
        //         stq.push(qNode);
        //         pNode = pNode->left;
        //         qNode = qNode->left;
        //     }

        //     if (pNode && qNode && pNode->val != qNode->val) {
        //         return false;
        //     } else if (pNode || qNode) {
        //         return false;
        //     }

        //     pNode = stp.top(); stp.pop();
        //     qNode = stq.top(); stq.pop();
        //     if (!pNode->right && qNode->right || pNode->right && !qNode->right) return false;
        //     pNode = pNode->right;
        //     qNode = qNode->right;
        // }

        // return true;

        // Cách 2: (Dùng 2 cái vector, traversal rồi in nhưng mà lười)

        // Cách 3:
        if (!p && !q) return true;

        if (!p || !q || p->val != q->val) return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    // TreeNode* p = new TreeNode(1);
    // p->left = new TreeNode(2);
    // p->right = new TreeNode(3);
    // TreeNode* q = new TreeNode(1);
    // q->left = new TreeNode(2);
    // q->right = new TreeNode(3);

    TreeNode* p = new TreeNode(1);
    TreeNode* q = new TreeNode(1);
    q->right = new TreeNode(2);

    bool res = sol.isSameTree(p, q);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    -> Traversal cùng kiểu (pre, in, post)
    -> Traversal ra mảng rồi so sánh
    -> Hoặc đệ quy với mỗi lần check là kết quả của 2 nhánh con
        - Trường hợp true: p và q cùng null, 2 nhánh con giống nhau
        - Trường hợp false: p null, q null (vì check true trước nên là 1 trong 2 sẽ có giá trị, 
        thế thì 1 trong 2 vô giá trị là # nhau), p->val = q->val
*/