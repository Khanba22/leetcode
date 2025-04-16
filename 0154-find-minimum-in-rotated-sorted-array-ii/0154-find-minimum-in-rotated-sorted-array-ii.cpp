class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int breakpoint = 0;
        for(int i = 1;i < n;i++){
            if(nums[i] >= nums[i-1]) breakpoint = i;
            else break;
        }
        if(breakpoint == n - 1) return nums[0];
        return nums[breakpoint+1];
        return nums[0];
    }
};