class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = INT_MIN, minSum = INT_MAX, currMin = 0, currMax = 0;
        for (int i=0;i < nums.size();i++) {
            int num = nums[i];
            currMin += num;
            currMax += num;
            maxSum = max(maxSum, currMax);
            minSum = min(minSum, currMin);
            currMax = max(currMax, 0);
            currMin = min(currMin, 0);
        }
        return max(abs(minSum), maxSum);
    }
};
