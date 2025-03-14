class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int diff = 0;
        for(int i = 1;i < nums.size();i++){
            diff = max(nums[i]-nums[i-1],diff);
        }
        return diff;
    }
};