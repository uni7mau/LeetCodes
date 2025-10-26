#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> res;
        for (int i = 0; i < land.size(); i++) {
            for (int j = 0; j < land[i].size(); j++) {
                if (land[i][j] == 1) {
                    int r = i, c = j;
                    while (r < land.size() && land[r][c] == 1) r++;
                    r--;
                    while (c < land[r].size() && land[r][c] == 1) c++;
                    c--;
                    res.push_back({i, j, r, c});
                    for (int x = i; x <= r; x++) {
                        for (int y = j; y <= c; y++) {
                            land[x][y] = 0;
                        }
                    }
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
    vector<vector<int>> land = {{1,0,0}, {0,1,1}, {0,1,1}};
    vector<vector<int>> res = sol.findFarmland(land);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Khi gặp 1,1 thì đi sâu nhất có thể, vì là mảng vuông nên không cần dfs
*/