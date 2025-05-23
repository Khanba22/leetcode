class Solution {
public:
    void helper(vector<int>&nums,int target,int i,int &res,int curr){
        if(i == nums.size()){
           if(curr == target) res++;
           return;
        }
        helper(nums,target,i+1,res,curr+nums[i]);
        helper(nums,target,i+1,res,curr-nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int res = 0;
        helper(nums,target,0,res,0);
        return res;
    }
};