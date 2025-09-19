#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// ----------------------Solution here---------------------
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string str0 = strs[0], strN = strs[strs.size()-1], res = "";
        for (int i = 0; i < str0.size(); i++) {
            if (str0[i] == strN[i]) res += str0[i];
            else break;
        }

        return res;
    }
};
//---------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<string> strs = { "flower", "flow", "flight" };
    string res = sol.longestCommonPrefix(strs);
    cout << res;
    //-----------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Giải thích thông tin:
        + đề đang muốn in ra các ký tự trùng nhau liên tiếp ở các chuỗi
        + giống mảng dp 2 chiều
        + đề chả bảo gì về việc trùng ở vị trí như nhau hay không 
        nhưng để ý thấy các chuỗi dài ngắn khác nhau
        + nếu là 1 ký tự thì chưa phải chuỗi trùng
    - Các ràng buộc cần chú ý:
        + strs.length từ 1 -> 200
        + mỗi chuỗi trong strs từ 1 -> 200 ký tự
        + chuỗi đầu vào gồm toàn lowercase
    -> nếu cho rằng vị trí là có quan trọng, tức là string1[i] = string2[i]:
        - cho vòng for kiểm tra hết vị trí hiện tại i từ chuỗi 1 đến chuỗi cuối
    kiểu for (int i = 0; i < string[i].size(); i++) rồi for j -> strs[j=0 -> strs.size()]
        - độ dài của str kết quả cùng lắm là bằng chuỗi ngắn nhất
        - vậy thì for ngoài dùng chuỗi ngắn nhất, có thể duyệt đến khi gặp str ngắn nhất
        - nếu sắp xếp dãy string này từ bé đến lớn thì có thể so sánh đến khi gặp 
        string1[i] != string2[i]
        - sắp xếp rồi -> so sánh phần tử đầu và cuối do sắp xếp chuỗi theo bảng alpha
        => so sánh chuỗi đầu và cuối sau khi sx là được, đến khi gặp khác thì break,
        độ phức tạp là O(sortAl) ~ O(nlogn) ?

*/