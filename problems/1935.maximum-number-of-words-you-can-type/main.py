from typing import List

# Gì đó ở đây, chưa biết được

# Viết code ở đây
class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        broken = set(brokenLetters)
        count = 0
        for word in text.split():
            if all(char not in broken for char in word):
                count += 1

        return count

# ==========================
# Test local
# ==========================
if __name__ == "__main__":
    sol = Solution()
    # Viết input ở đây
    text = "hello world"
    brokenLetters = "ad"
    print(sol.canBeTypedWords(text, brokenLetters))