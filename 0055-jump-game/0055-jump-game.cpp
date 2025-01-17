class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        int n = nums.size() - 1;
        int last = n;
        for(int i = n;i >= 0;i--){
            if(i+nums[i] >= last){
                last = i;
            }
        }
        return !last;
    }
};