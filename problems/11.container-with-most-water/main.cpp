#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1, res = 0;
        while (left != right) {
            int curr = min(height[left], height[right])*(right-left);
            res = max(res, curr);
            if (height[left] < height[right]) left++;
            else right--;
        }

        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int res = sol.maxArea(height);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Cho dãy các cột với chiều cao
    - Trả ra lượng nước chứa được tối đa
    - Lượng nước tối đa giữa 2 cột là chiều dài của cột ngắn hơn
    -> Lượng nước giữa 2 cột cao nhất và cao nhì có phải lớn nhất không ? Chưa chắc
        Vậy dùng 2 con trỏ, nếu chưa = nhau thì cứ tiến tới
        Như đã nói ở trên mỗi lần làm như thế thì cập nhật res = max(res, min(val[left], val[right])*(right-left))
        Nếu bên trái < bên phải thì cho trái tiến tới, không thì phải tiến tới
*/