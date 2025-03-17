class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int>freq;
        for(int &i : nums){
            freq[i]++;
        }
        for(auto i:freq){
            if(i.second % 2) return false;
        }
        return true;
    }
};