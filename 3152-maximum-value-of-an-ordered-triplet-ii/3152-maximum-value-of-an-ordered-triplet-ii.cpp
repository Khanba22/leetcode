class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return 0;

        vector<long long> prefix(n, 0), suffix(n, 0);
        prefix[0] = (long long)nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], (long long)nums[i]);
        }

        suffix[n - 1] = (long long)nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], (long long)nums[i]);
        }

        long long res = 0;
        for (int i = 1; i < n - 1; i++) {
            long long left = prefix[i - 1];
            long long right = suffix[i + 1];
            long long val = (left - (long long)nums[i]) * right;
            if(val > res) res = val;
        }

        return res;
    }
};