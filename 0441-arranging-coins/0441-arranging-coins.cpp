class Solution {
public:
    int arrangeCoins(int n) {
        long left = 1,right = n;
        while(left <= right){
            long mid = left + (right-left)/2;
            long s = mid  * (mid + 1) /2;
            if(s == n) return (int) mid;
            else if(s < n) left = mid + 1;
            else right = mid - 1;
        }
        return (int) right;
    }
};