class Solution {
public:
    int getDigitSum(int n){
        int res = 0;
        while(n){
            res+=n%10;
            n/=10;
        }
        return res;
    }
    int countLargestGroup(int n) {
        map<int,int>m;
        int maxGrpSizeFreq = 0;
        for(int i = 0;i < n;i++){
            maxGrpSizeFreq = max(maxGrpSizeFreq,++m[getDigitSum(i+1)]);
        }
        
        return maxGrpSizeFreq;
    }
};