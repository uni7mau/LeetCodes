from typing import List

# Gì đó ở đây, chưa biết được

# Viết code ở đây
class Solution(object):
    def generate(self, numRows):
        res = [[1]]

        for _ in range(numRows - 1):
            dummy_row = [0] + res[-1] + [0]
            row = []
            print(dummy_row)

            for i in range(len(res[-1]) + 1):
                row.append(dummy_row[i] + dummy_row[i+1])
            res.append(row)
        
        return res

# ==========================
# Test local
# ==========================
if __name__ == "__main__":
    sol = Solution()
    # Viết input ở đây
    numRows = 5
    res = sol.generate(numRows)
    print(res)

# Mỗi lần thêm 2 số 0 vào đầu và cuối thì khi cộng 2 số liền kề, ta được kết quả đúng cho ô dưới