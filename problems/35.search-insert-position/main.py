class Solution(object):
    def searchInsert(self, nums, target):
        left = 0
        right = len(nums)-1
        while left <= right:
            mid = (int)((left+right)/2)
            if nums[mid] < target: left = mid+1
            elif nums[mid] > target: right = mid-1
            else: return mid
        return right+1
                
# ==========================
# Test local
# ==========================
if __name__ == "__main__":
    sol = Solution()
    # Viết input ở đây
    nums = [1,3,5,6]
    target = 5
    res = sol.searchInsert(nums, target)
    print(res)