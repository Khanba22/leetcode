class NumArray {
public:
    vector<int>nums;
    vector<int>sums;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        int sum = 0;
        for(int i = 0;i < nums.size();i++){
            sum+=nums[i];
            sums.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return sums[right];
        return sums[right] - sums[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */