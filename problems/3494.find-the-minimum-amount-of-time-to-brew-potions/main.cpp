#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> res(n+1, 0);

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                res[i+1] = max(res[i+1], res[i]) + 1LL*skill[i]*mana[j];
            }

            // for (int i = 0; i < n+1; i++) {
            //     cout << res[i] << " ";
            // }
            // cout << " | ";

            for (int i = n-1; i > 0; i--) {
                res[i] = res[i+1] - 1LL*skill[i]*mana[j];
            }

            // for (int i = 0; i < n+1; i++) {
            //     cout << res[i] << " ";
            // }
            // cout << "\n";
        }

        return res[n];
    }   
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<int> skill = {1,5,2,4};
    vector<int> mana = {5,1,4,2};
    long long res = sol.minTime(skill, mana);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Giải thích thông tin:
        + Cho 2 mảng số nguyên là skill và mana
        + Có n (skill size) wizard và m (mana size) lọ thuốc
        + Mỗi lọ thuốc có sức chứa mana là mana[j] và đi qua tất cả các wizard tuần tự để pha chế
        + Thời gian wizard thứ i mất tại vị trí lọ thuốc i là skill[i]*mana[j]
        + Lọ thuốc được pha chế đồng bộ, tức là wizard sau khi hoàn thành công việc thì phải ngay lập tức truyền cho người tiếp theo
        + Trả về thời gian tối thiểu cho các lọ thuốc để được pha chế xong
    - Các ràng buộc cần lưu ý:
        + Số lượng các phần tử của cả 2 mảng tối đa là 5000
        + Giá trị tối đa của cả 2 mảng là 5000
    -> Các điểm cần làm rõ trong ví dụ 1, 5, 2, 4 và 5, 1, 4, 2 như sau:
        + Các wizard pha chế lọ số 0 như sau:
            1*5 -> 5*5 -> 2*5 -> 4*5
            5      25     10     20    <- Thời gian cần của từng wizard
        + Bắt đầu từ mốc thời gian 0:
        0 -> 5 -> 30 -> 40 -> 60
        + Pha chế lọ số 1:
            1*1 -> 5*1 -> 2*1 -> 4*1
            1       5      2      4
        + Bắt đầu từ mốc thời gian sau khi wizard 0 làm xong lọ trước:
        5 -> 6 -> 11 -> 13 -> 17   <- Bị xung đột tại wizard 1 (số 11) vì tại thời gian 11 wizard 0 truyền cho 1 thì
        wizard 1 đang pha lọ thứ 1, đến mốc 30s mới xong
        
        - Chính vì vậy các wizard cần phải tìm mốc thời gian để đưa lọ số 1 vào, tương tự như các lọ khác sao cho
        không bị xung đột thời gian (tức là không ai phải chờ)
        + Bắt đầu từ mốc thời gian sau 12 giây khi wizard gần cuối làm xong:
        52 -> 53 -> 58 -> 60 -> 64  <- Thấy không còn wizard nào bị chờ

        - Tức là sao?
            + Tức là tính toán làm sao cho 1 wizard nào đấy trong dãy có thời gian truyền lọ mới đến vừa đúng lúc thực hiện xong lọ trước
            + Nếu nhìn lại trong mảng prefix, ta nhận ra f[i] là thời gian rảnh tiếp theo của wizard thứ i
            + Vậy thì ta đi tìm max thời gian phải chờ của mỗi vòng lặp
            + Để cho nhanh thì trong vòng lặp, duyệt ngược lại để tính ra giá trị f[i] từ thời gian wizard cuối làm xong

        now = f[0];
        for (i = 1->n) {
            now = max(now + skill[i-1]*x, f[i]);
        }

        now = [0, <0+1*5;5> -> 5,<5+5*5;30> -> 30, <30+2*5;40> -> 40, <40+4*5;60> -> 60]
        now = [0, <5+1*1;5> -> ]
        ...          

*/