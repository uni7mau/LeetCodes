#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false}, cols[9][9] = {false}, boxs[9][9] = {false};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j]-'1', x = i/3*3 + j/3;
                    if (rows[i][num] || cols[j][num] || boxs[x][num]) return false;
                    rows[i][num] = cols[j][num] = boxs[x][num] = 1;
                }
            }
        }

        return true;
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
    - Có 2 điều kiện sau để giải bài này:
        + Trong 1 hàng và 1 cột không được trùng
        + Trong 9 ô xung quanh không được trùng 
    -> Rồi xong rồi đó, không conflict thì valid thôi
*/