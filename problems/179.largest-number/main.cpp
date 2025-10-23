#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------

bool compare(int a, int b) {
    string tmp1 = to_string(a);
    string tmp2 = to_string(b);

    return (tmp1 + tmp2) > (tmp2 + tmp1);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        if (nums[0] == 0) return "0";

        string res = "";
        for (int i = 0; i < nums.size(); i++) {
            res += to_string(nums[i]);
        }   
    
        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<int> nums = {3,30,34,5,9};
    string res = sol.largestNumber(nums);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - sorting hooks
*/