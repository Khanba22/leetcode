class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int sum = nums[0];
        int maxi = INT_MIN;
        for(int i = 1; i < nums.size();i++){
            if(nums[i-1] < nums[i]){
                sum+=nums[i];
            }else{
                maxi = max(maxi,sum);
                sum = nums[i];
            }
        }
        return max(sum,maxi);
    }
};