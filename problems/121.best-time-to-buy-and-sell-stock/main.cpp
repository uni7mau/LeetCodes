#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Cách 1:
        // int arr[prices.size()];
        // int currMx = prices[prices.size()-1];
        // for (int i = prices.size()-1; i >= 0; i--) {
        //     if (prices[i] > currMx) {
        //         currMx = prices[i];
        //         arr[i] = prices[i];
        //     } else {
        //         arr[i] = currMx;
        //     }
        // }

        // int res = 0;
        // for (int i = prices.size()-1; i >= 0; i--) {
        //     if (arr[i] - prices[i] > res) {
        //         res = arr[i] - prices[i];
        //     }
        // }

        // return res;

        // Cách 2:
        int buy = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            } else if (prices[i] - buy > profit) {
                profit = prices[i] - buy;
            }
        }

        return profit;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<int> prices = {7,1,5,3,6,4};
    int res = sol.maxProfit(prices);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Giải thích thông tin
        + Cho mảng prices chứa các giá trị sản phẩm tại ngày i
    - Ràng buộc cần lưu ý
        + Độ dài mảng tối đa 10^5

    -> Chắc là liên quan gì đó đến stack
    st:
    4 0
    6 0
    6 3
    6 1
    6 5
    7 0

    -> Duyệt từ cuối lên, gán vào mảng từng phần tử như sau:
        - Nếu lớn hơn currMx: arr[i] = curr
        - Không lớn hơn thì gán là curMx
    - Lại duyệt từ cuối lên, lấy giá trị của prices - đi cùng vị trí trong arr là ra maxprofit
    => O(n)

    -> Vì cách trên chưa tối ưu lắm cho nên làm cách khác
        - Dùng Kadane's Algorithm
*/