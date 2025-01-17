class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int>r(n,0);
        int power = 1;
        int i = 0;
        while(true){
            if(r[i]) break;
            r[i]++;
            i = (i + power*k) % n;
            power++;
        }
        vector<int>res;
        for(int i = 0;i < n ;i++){
            if(!r[i]) res.push_back(i+1);
        }
        return res;
    }
};