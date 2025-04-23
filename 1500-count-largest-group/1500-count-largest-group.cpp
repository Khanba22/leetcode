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
        for(int i = 0;i < n;i++){
            m[getDigitSum(i+1)]++;
        }
        int maxGrpSize = 0;
        int maxGrpSizeFreq = 0;
        for(auto i:m){
            if(i.second == maxGrpSize){
                maxGrpSizeFreq++;
            }else if(i.second > maxGrpSize){
                maxGrpSizeFreq = 1;
                maxGrpSize = i.second;
            }
        }
        return maxGrpSizeFreq;
    }
};