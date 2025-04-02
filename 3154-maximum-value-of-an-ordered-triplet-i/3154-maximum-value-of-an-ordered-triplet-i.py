class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        p_max = [nums[0]]
        s_max = [nums[-1]]
        n = len(nums)
        for i in range(1,n):
            p_max.append(max(p_max[i-1], nums[i]))
        for j in range(n - 2,-1,-1):
            s_max.append(max(s_max[n-j-2], nums[j]))
        s_max = s_max[::-1]
        res = 0
        for i in range(1,n-1):
            res = max((p_max[i-1] - nums[i]) * s_max[i + 1], res)
        return res