class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int>res;
        for(int n:nums){
            res.push_back(nums[n]);
        }
        return res;
    }
};