#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// ----------------------Solution here---------------------
class Solution {
public:
// Cách 1:
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<int> res{-1, -1};
    //     for (int i = 0; i < nums.size()-1; i++) {
    //         for (int j = i+1; j < nums.size(); j++) {
    //             if (nums[i] + nums[j] == target) {
    //                 res.push_back(i);
    //                 res.push_back(j);
    //                 break;
    //             }
    //         }
    //         if (res.size() != 0) break;
    //     }

    //     return res;
    // }
// Cách 2:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(target - nums[i]) == mp.end()) {
                mp[nums[i]] = i;
            } else {
                return { mp[target - nums[i]], i };
            }
        }
        
        return {-1, -1};
    }
};
//---------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<int> nums = {3, 4};
    int target = 8;

    auto ans = sol.twoSum(nums, target);
    for (int x : ans) cout << x << " ";
    //-----------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Ràng buộc cần để ý gồm: 
        + Lấy đúng 2 elem
        + Không dùng 1 elem 2 lần
        + Output không cần theo order

    -> Cách dễ nhất để tìm tổng là for 2 lần
        => độ phức tạp là O(n^2) giống với selection sort

    -> Hoặc là dùng mảng đánh dấu: 
        - Ta có: a + b = s => b = s - a với a là phần tử đang duyệt và s đã có
            + Nếu không có phần tử b ở trong mảng đã duyệt, thì cho a vào với vị trí i
            + Nếu đã có phần tử b ở trong mảng đã duyệt thì đây là kết quả cần tìm, return luôn
            + Nếu duyệt hết mảng nhưng không thấy thì in ra { -1, -1 }
        => (
            ~ Duyệt hết 1 mảng hết O(n)
            ~ Hàm find trong map có độ phức tạp là O(logn) do đây là cây tìm kiếm nhị phân cân bằng
            Vậy tổng O(nlogn) nhanh hơn cách 1
        )
*/