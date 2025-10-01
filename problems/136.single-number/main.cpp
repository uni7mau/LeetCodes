#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Cách 1:
        // map<int, int> mp;
        // for (int i = 0; i < nums.size(); i++) {
        //     mp[nums[i]]++;
        // }

        // for (auto elem : mp) {
        //     if (elem.second == 1) return elem.first;
        // }

        // return nums[0];

        // Cách 2:
        int ans = 0;
	    for (auto x:nums) ans ^= x;
	    
        return ans;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<int> nums = {999};
    int res = sol.singleNumber(nums);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    Cho mảng không rỗng nums, mọi phần tử đều có 2 cái, trừ 1 phần tử có đúng 1 cái, hãy tìm phần tử đó rồi in ra
    -> Dùng map thì thường quá, dùng cái khác đi
        - Dùng xor đi:
            + 0^b = b
            + a^a = 0
            + b^a^a = a^b^a = a^a^b = b
            + Cứ lẻ lần thì ra b, chẵn thì = 0
*/