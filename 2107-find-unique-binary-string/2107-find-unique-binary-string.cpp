class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans(nums.size(),'0');
        for (int i = 0; i < nums.size(); i++) {
            ans[i]=nums[i][i] == '1' ? '0' : '1';
        }
        return ans;
    }
};