class Solution:
    def threeSumClosest(self, nums, target: int) -> int:
        res = 999999999
        nums.sort()
        i = 0
        while i < len(nums):
            ptr1 = i+1
            ptr2 = len(nums) - 1
            while ptr1 < ptr2:
                tSum = nums[i] + nums[ptr1] + nums[ptr2]
                if tSum == target:
                    return tSum
                elif tSum > target:
                    ptr2-=1
                else:
                    ptr1+=1
                if abs(target-tSum) < abs(res-target):
                    res = tSum
            i+=1
        return res