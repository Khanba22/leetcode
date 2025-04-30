class Solution {
public:
    int kthFactor(int n, int k) {
        int res = 0;
        for(int i = 1;i <= n / 2;i++){
            if(n % i == 0) res++;
            if(res == k) return i;
        }
        if(res == k - 1) return n;
        return -1;
    }
};