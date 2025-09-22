from typing import List

# Gì đó ở đây, chưa biết được

# Viết code ở đây
class Solution(object):
    def lengthOfLastWord(self, s):
        words = s.strip().split()
        
        return len(words[-1])

# ==========================
# Test local
# ==========================
if __name__ == "__main__":
    sol = Solution()
    # Viết input ở đây
    s = "   fly me   to   the moon  "
    res = sol.lengthOfLastWord(s)
    print(res)


# Ở đây cũng có hàm như stringstream kiểu lấy được các chữ trong chuỗi là strip().split()
