#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Cách 1:
        // if (nums.size() == 1) return false;

        // sort(nums.begin(), nums.end());
        // for (int i = 1; i < nums.size(); i++) {
        //     if (nums[i-1] == nums[i]) return true;
        // }

        // return false;
        
        // Cách 2:
        // map<int, bool> mp;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (!mp[nums[i]]) mp[nums[i]] = true;
        //     else return true;
        // }
        // return false;

        // Cách 3:
        unordered_set<int> uos;
        for (int num : nums) {
            if (uos.count(num) > 0) return true;
            uos.insert(num);
        }
        return false;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<int> nums = {1,2,3,4,5,6,7,1};
    bool res = sol.containsDuplicate(nums);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    Cách dễ nhất là sort, cách dễ nhì là dùng map, dễ nữa thì unordered_set, cách tuyệt đối điện ảnh chưa nghĩ ra
    Không hiểu sao cách 1 beat gần 100% còn cách dùng map thì beat 9%
*/