#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
    public:
    int majorityElement(vector<int>& nums) {
        int num = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0) {
                num = nums[i];
            }

            if (nums[i] == num) {
                cnt++;
            } else {
                cnt--;
            }
        }

        return num;
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
    Bài này cũng chả có gì 
*/