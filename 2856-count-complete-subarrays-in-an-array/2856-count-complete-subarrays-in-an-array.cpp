class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end());
        unordered_map<int, int> freq;
        int res = 0;
        int left = 0;

        for (int r = 0; r < n; r++) {
            freq[nums[r]]++;

            while (freq.size() == s.size()) {
                res += (n - r);
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }
        }

        return res;
    }
};
