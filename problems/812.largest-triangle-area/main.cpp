#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res = 0;
        for (int i = 0; i < points.size() - 2; i++) {
            for (int j = i + 1; j < points.size() - 1; j++ ) {
                for (int k = j + 1; k < points.size(); k++) {
                    int x1 = points[i][0] - points[j][0];
                    int y1 = points[i][1] - points[j][1];
                    int x2 = points[i][0] - points[k][0];
                    int y2 = points[i][1] - points[k][1];
                    int area = x1*y2 - x2*y1;
                    res = max(res, 0.5*abs(area));
                }
            }
        }

        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<vector<int>> points = {{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}};
    double res = sol.largestTriangleArea(points);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    // Dùng 1/2 của tích vô hướng, còn dùng 3 vòng for do ràng buộc không lớn
*/