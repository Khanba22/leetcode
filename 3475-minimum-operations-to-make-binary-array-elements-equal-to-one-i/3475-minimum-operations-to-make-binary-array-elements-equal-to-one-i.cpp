class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0;
        int n = nums.size();

        for(int i = 0; i <= n - 3; i++) {
            if(nums[i] == 0) {
                ops++;
                for(int j = i; j < i + 3; j++) {
                    nums[j] = 1 - nums[j];
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) return -1;
        }

        return ops;
    }
};
