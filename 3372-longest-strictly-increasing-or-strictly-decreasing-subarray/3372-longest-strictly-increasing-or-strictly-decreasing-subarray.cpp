class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int count = 1;
        int maxLen = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                count++;
            } else {
                count = 1;
            }
            maxLen = max(maxLen, count);
        }
        count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                count++;
            } else {
                count = 1;
            }
            maxLen = max(maxLen, count);
        }

        return maxLen;
    }
};
