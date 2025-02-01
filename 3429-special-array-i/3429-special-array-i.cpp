class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool flag = nums[0] % 2 == 0;
        for(int i = 1;i < nums.size();i++){
            if(flag == (nums[i]%2 == 0) ) return false;
            flag = !flag;
        }
        return true;
    }
};