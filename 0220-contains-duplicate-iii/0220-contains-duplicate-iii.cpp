class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if (indexDiff <= 0 || valueDiff < 0) return false;
        
        set<long long> window;
        
        for (int i = 0; i < nums.size(); ++i) {
            auto lower = window.lower_bound((long long)nums[i] - valueDiff);
            if (lower != window.end() && *lower <= (long long)nums[i] + valueDiff) {
                return true;
            }

            window.insert(nums[i]);
            if (i >= indexDiff) {
                window.erase(nums[i - indexDiff]);
            }
        }
        
        return false;
    }
};
