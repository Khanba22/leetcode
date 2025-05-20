class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>prefix(n+1,0);
        for(int i = 0;i < queries.size();i++){
            prefix[queries[i][0]]++;
            prefix[queries[i][1] + 1]--;
        }
        int curr = 0;
        for(int i = 0;i < n;i++){
            curr+=prefix[i];
            if(nums[i] - curr > 0) return false;
        }
        return true;
    }
};