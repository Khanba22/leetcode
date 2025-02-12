class Solution {
public:
    int getDigitSum(int num){
        int res = 0;
        while(num){
            res+=num%10;
            num/=10;
        }
        return res;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>>sum;
        int res = -1;
        for(int &i:nums){
            int s = getDigitSum(i);
            if(sum.count(s)){
                if(i >= sum[s][1]){
                    sum[s][0] = sum[s][1];
                    sum[s][1] = i;
                }else if(i > sum[s][0]){
                    sum[s][0] = i;
                }
            }else{
                sum[s] = {-1,i};
            }
        }
        for(auto &x:sum){
            if(x.second[0] != -1){
                res = max(res,x.second[0] + x.second[1]);
            }
        }
        return res;
    }
};