class Solution {
public:
    long long coloredCells(int n) {
        long long count = 0;
        for (long long i = n - 1; i >= 0; i--) {
            if(i == n - 1){
                count += 2 * i + 1;
            }else{
                count += 4 * i + 2;
            }
        }
        return count;
    }
};