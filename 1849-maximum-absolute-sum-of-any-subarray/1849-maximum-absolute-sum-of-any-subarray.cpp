class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currentSum = 0;
        int minSum = INT_MAX;

        for (int num : nums) {
            currentSum += num;

            maxSum = max(maxSum, currentSum);

            if (currentSum < 0)
                currentSum = 0;
        }
        currentSum = 0;
        
        for (int num : nums) {
            currentSum += num;

            minSum = min(minSum, currentSum);

            if (currentSum > 0)
                currentSum = 0;
        }

        return max(abs(minSum),maxSum);
    }
};