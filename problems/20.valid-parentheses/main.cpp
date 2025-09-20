#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// ----------------------Solution here---------------------
class Solution {
public:
    bool isValid(string s) {
        // map<char, int> mp; mp['('] = mp['['] = mp['{'] = 0;
        // int pos = 0;
        // while (pos < s.length()) {
        //     if (s[pos] == ')' || s[pos] == ']' || s[pos] == '}') {
        //         if (mp[s[pos]] != 0) mp[s[pos]]--;
        //         else break;
        //     } else {
        //         mp[s[pos]]++;
        //     }

        //     pos++;
        // }
        
        // if (pos < s.length()) return false; 
        // else if (pos == s.length() && (mp['('] > 0 || mp['['] > 0 || mp['{'] > 0)) return false;
        // return true;

        if (s.length() == 0 || s.length() == 1) return false;
        
        vector<char> open;
        int pos = 0;
        while (pos < s.length()) {
            char curr = s[pos];
            if (curr == '(' || curr == '[' || curr == '{') open.push_back(curr);
            else {
                if (open.empty()) break;
                else if (
                    (curr == ')' && open.back() == '(') ||
                    (curr == ']' && open.back() == '[') ||
                    (curr == '}' && open.back() == '{')
                ) open.pop_back();
                else break;
            }

            pos++;
        }

        if (pos == s.length() && open.size() == 0) return true;
        return false;
    }
};
//---------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    string s = "}{";
    bool res = sol.isValid(s);
    cout << res;
    //-----------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Giải thích thông tin: 
        + có 3 loại ngoặc, mỗi loại ngoặc gồm 2 phần tử, nếu 1 mở 1 đóng thì là valid
        + cách xa, lồng nhau cũng được
        + phải cùng theo thứ tự
    - Các ràng buộc cần để ý:
        + s.length từ 1 -> 10^4
        + các ký tự bao gồm: ()[]{}
    -> Giải phức tạp như sau:
        - Tạo mảng chứa dấu mở, dấu đóng
        - Duyệt từ đầu đến cuối:
            + Nếu gặp ký tự mở thì cho vào mảng 
            + Nếu gặp ký tự dấu đóng thì:
                <TH1 - mảng rỗng> break vòng for
                <TH2 - mảng có phần tử>
                    <TH 1 - phần tử đầu khớp> đi 
            khớp thì xóa khỏi mảng, không khớp thì  
        - Khi duyệt hết rồi thì kiểm tra:
            + Nếu còn phần tử thì trả về false
            + Nếu rỗng thì trả về true


    -> Giải đơn giản như sau:
        - Tạo 1 cái map cho 3 loại ngoặc mở map<char, int>, gán = 0, int pos = 0;
        - Duyệt từ đầu đến cuối bằng while tăng pos, nếu gặp ký tự đóng thì kiểm tra trong map kiểu:
            + Nếu map[currChar] != 0 (có mở ngoặc trước đó) thì map[curChar]--
            + Nếu map[currChar] == 0 (Không mở trước đó) thì break
            + pos++
        - Nếu pos < s.length thì return false;
        - Nếu pos == s.length() and (map[char1] > 0 or map[char2] > 0 or map[char3] > 0) thì return false;
        - else return true;

    // Cách trên không hoạt động đâu
    
    -> Giải đơn giản như sau:
        - Tạo một mảng 1 chiều
        - Duyệt từ đầu đến cuối:
            + Nếu gặp mở thì kiểm tra xem phần tử cuối có to hơn không:
                <TH1 - phần tử sắp thêm vào to hơn> break
                <TH2 - phần tử sắp thêm vào bé hơn> cho vào
            + Nếu gặp đóng thì kiểm tra đầu vector:
                <TH1 - Nếu mảng rỗng> break
                <TH2 - Nếu match> pop
                <TH3 - Nếu không match> break
        - Nếu pos == s.length() và mảng rỗng thì trả về true
        - Còn lại thì trả về false hết
        => O(n)
*/