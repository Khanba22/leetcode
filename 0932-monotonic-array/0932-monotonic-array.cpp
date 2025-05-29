class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int increasing = true;
        int decreasing = true;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1])
                increasing = false;
            else if (nums[i] < nums[i + 1])
                decreasing = false;
        }
        return increasing || decreasing;
    }
};