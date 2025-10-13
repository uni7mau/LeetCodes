#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
// private:
//     int toVal(string s) {
//         int res = 0;
//         for (int i = 0; i < s.length(); i++) {
//             res += s[i]-'a'+1;
//         }

//         return res;
//     }

// public:
//     vector<string> removeAnagrams(vector<string>& words) {
//         map<int, bool> check;

//         for (int i = 0; i < words.size(); i++) {
//             int val = toVal(words[i]);
//             if (check[val] == true) {
//                 cout << words[i] << val << " ";
//                 words[i] = "";
//             }

//             check[val] = true;
//         }

//         vector<string> res;
//         for (int i = 0; i < words.size(); i++) {
//             if (words[i] != "") res.push_back(words[i]);
//         }

//         return res;
//     }

// Bên trên sai, không dùng được

public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        
        for (int i = 1; i < words.size(); i++) {
            string a = words[i], b = ans.back();
            sort(a.begin(), a.end()), sort(b.begin(), b.end());
            if (a != b) ans.push_back(words[i]); 
        }
        
        return ans;
    }

// 
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<string> words = {"meh","ab","qefigmpc","ab","fdkbqb"};
    vector<string> res = sol.removeAnagrams(words);
    for (auto x : res) cout << x << " ";
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Cho dãy các từ
    - Xoá các từ là anagram của từ đứng trước nó
    - Anagram là từ có thể sắp xếp lại thành từ khác
    -> Duyệt từ đầu đến cuối:
        - Nếu giá trị của từ chưa có thì lưu mp[val]++
        - Nếu đã có chứng tỏ có thể biến đổi từ hiện tại thành từ đó, lưu từ này vào res
    // X

    -> thật ra chỉ cần 2 string kề nhau là anagram là được, vậy sort 2 lần, cost O(n*Llog(L)) ~ O(n)
*/