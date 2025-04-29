class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long res = 0,freq = 0,left = 0;
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            if(nums[i] == maxi) freq++;
            while(freq >= k) {
                if(nums[left] == maxi) freq--;
                left++;
            }
            res += left;
        }
        return res;
    }
};
