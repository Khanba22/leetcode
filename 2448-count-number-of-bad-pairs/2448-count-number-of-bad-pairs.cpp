class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long count = 0;
        int n = nums.size();
        unordered_map<int,int>pairs;
        for(int i = 0;i < n;i++){
            int diff = nums[i] - i;
            count+=pairs[diff];
            pairs[diff]++;
        }
        long long x = ((1LL*n * (n-1)))/2;     
        return x - count;
    }
};