#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
    vector<string> res;
private:
    void backtrack(int op, int cl, string curr) {
        if (op == 0 && cl == 0) res.push_back(curr);

        if (op != 0) backtrack(op-1, cl, curr + '(');
        if (cl != 0 && op < cl) backtrack(op, cl-1, curr + ')');
    }
public:
    vector<string> generateParenthesis(int n) {
        backtrack(n, n, "");

        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    int n = 3;
    vector<string> res = sol.generateParenthesis(n);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Don't panic, bài này là cơ bản của backtracking: 
        + Trong các tập hợp hoán vị có n vị trí thì mỗi 1 phần tử con chỉ có 2 trường hợp ( hoặc ),
        nếu bài toán hỏi nhiều trường hợp hơn thì cứ tăng lượng phần tử lên
        + Vậy giá trị tiếp theo của nó cũng thế để tạo thành kết quả n = 1, là (), )(, )), ((
*/