class Solution {
public:
    long long coloredCells(int n) {
        long long cnt=0;
        int x=1;
        for(int i=0;i<n-1;i++){
            cnt+=(x*2);
            x+=2;
        }
        return cnt+x;
    }
};