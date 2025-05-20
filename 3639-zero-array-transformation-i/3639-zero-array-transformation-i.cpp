class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>prefix(nums.size()+1,0);
        for(auto &q:queries){
            prefix[q[0]]++;
            prefix[q[1] + 1]--;
        }
        int curr = 0;
        for(int i = 0;i < nums.size();i++){
            curr+=prefix[i];
            if(max(nums[i] - curr,0) != 0) return false;
        }
        return true;
    }
};