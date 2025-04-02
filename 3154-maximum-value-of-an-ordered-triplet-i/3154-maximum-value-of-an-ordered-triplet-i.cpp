class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int ptr1,ptr2,ptr3;
        ptr1 = 0;
        long long maxi = 0;
        int n = nums.size();
        while(ptr1 < n - 2){
            ptr2 = ptr1 + 1;
            while(ptr2 < n - 1){
                ptr3 = ptr2 + 1;
                while(ptr3 < n){
                    long long val = ((long long )nums[ptr1] - (long long )nums[ptr2])* (long long) nums[ptr3];
                    maxi = max(maxi,val);
                    ptr3++;
                }
                ptr2++;
            }
            ptr1++;
        }
        return maxi;
    }
};