class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size() <= 2) return false;
        int n = arr.size() - 3;
        for(int i = 0;i <= n;i++){
            if(arr[i] & 1 && arr[i + 1] & 1 && arr[i + 2] & 1) return true;
        }
        return false;
    }
};