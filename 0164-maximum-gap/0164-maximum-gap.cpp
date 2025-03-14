class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxS=0;
        if(nums.size()<2) return 0;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-1;i++){
            int sum=nums[i+1]-nums[i];
            maxS=max(maxS, sum);
        }
        return maxS;
    }
};