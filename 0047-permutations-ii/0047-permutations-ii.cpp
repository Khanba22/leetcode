class Solution {
public:
    void helper(vector<int>& nums, vector<int>& used, vector<vector<int>>& res,
                vector<int>& perm) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            used[i] = 1;
            perm.push_back(nums[i]);
            helper(nums, used, res, perm);
            perm.pop_back();
            used[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> used(nums.size(), 0);
        vector<int> perm;
        sort(nums.begin(), nums.end());
        helper(nums, used, res, perm);
        return res;
    }
};
