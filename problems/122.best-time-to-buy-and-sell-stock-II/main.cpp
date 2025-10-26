#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sumProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i]-prices[i-1] > 0) sumProfit += prices[i]-prices[i-1];
        }

        return sumProfit;
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
    Giải giống như bài 1, dùng Kdane's Algorithm
    - Khi gặp lợi nhuận dương, thay vì lấy luôn ta cộng dồn lợi ích, bán hay không không còn quan trọng
*/