class Solution {
public:
    void helper(vector<int>& nums, vector<int>& used, vector<vector<int>>& res,
                int currSize, vector<int>&perm) {
        if (currSize == nums.size())
            res.push_back(perm);
        for(int i = 0;i < nums.size();i++){
            if(!used[i]){
                used[i] = 1;
                perm.push_back(nums[i]);
                helper(nums,used,res,currSize+1,perm);
                perm.pop_back();
                used[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>used(nums.size(),0);
        vector<int>perm;
        helper(nums,used,res,0,perm);
        return res;
    }
};