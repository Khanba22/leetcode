class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long res = 0;
        long long count = 0;
        unordered_map<int, int> freq;
        for(int r = 0,l = 0;r < nums.size();r++){
            int x = nums[r];
            count+=freq[x]++;

            while(count >= k){
                res+=(nums.size()-r);
                count-=--freq[nums[l]];
                l++;
            }
        }
        return res;
    }
};