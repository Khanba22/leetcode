class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int res = 0;
        int sum = 0;
        int n = nums.size();
        vector<long long>prefix(n,0);
        prefix[0] = (long long)nums[0];
        for(int i = 1;i < nums.size();i++){
            prefix[i] = prefix[i - 1] + (long long)nums[i];
        }
        for(int i = 0;i < n - 1;i++){
            long long rightSum = prefix[n - 1] - prefix[i];
            long long leftSum = prefix[i];
            if(rightSum <= leftSum) res++;
        }
        return res;
    }
};