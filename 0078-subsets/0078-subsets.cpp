class Solution {
public:
    void helper(int i, vector<int>& curr, vector<int>& nums, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(curr);
            return;
        }

        helper(i + 1, curr, nums, res);

        curr.push_back(nums[i]);
        helper(i + 1, curr, nums, res);
        curr.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res; 
        vector<int> curr; 
        helper(0, curr, nums, res);
        return res;
    }
};
