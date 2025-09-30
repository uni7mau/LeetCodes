#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        res[0].push_back(1);
        if (numRows == 1) return res;

        for (int i = 1; i < numRows; i++) {
            res[i].push_back(1);
            for (int j = 1; j < i; j++) {
                res[i].push_back(res[i-1][j-1] + res[i-1][j]);
            }
            res[i].push_back(1);
        }

        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    int numRows = 5;
    vector<vector<int>> res = sol.generate(numRows);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < i+1; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    # Cuối cùng cũng có bài không phải node nữa

    - Giải thích thông tin:
        + Cho số lượng row
        + Mỗi row theo quy tắc lấy 2 thằng trên + vào
        + Trả về kết quả là các mảng của cả tam giác
    - Các ràng buộc cần lưu ý:
        + Số dòng tối đa khoảng 30 
    -> 
        - Trong mảng thì không có tính chất tam giác đối xứng như thế
        - Nếu là vector<vector<>> thì giá trị dưới tại i j bằng 2 thằng trên + lại là [i-1][j-1] + [i-1][j] (dịch trái), 2 giá trị ngoài luôn là 1
        - Trường hợp mẫu là 3 số 1 ở hàng 1 và hàng 2
        
        - Vì đề không cho những số 0 ở cùng cho nên là làm lại bằng push_back
*/