class Solution {
public:
    bool canSteal(const vector<int>& nums, int k, int cap) {
        int count = 0;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] <= cap) {
                count++;
                i += 2; 
            } else {
                i++;
            }
            if(count >= k) return true;
        }
        return false;
    }
    
    int minCapability(vector<int>& nums, int k) {
        int left = INT_MAX;
        int right = INT_MIN;
        for(int i = 0;i < nums.size();i++){
            left = min(left,nums[i]);
            right = max(right,nums[i]);
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canSteal(nums, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};