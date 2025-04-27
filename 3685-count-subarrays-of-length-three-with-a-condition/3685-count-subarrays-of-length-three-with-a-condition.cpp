class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for(int i = 0;i < n - 2;i++){
            res+=(nums[i] + nums[i + 2] == nums[i + 1] / 2 && !(nums[i + 1] & 1));
        }
        return res;
    }
};