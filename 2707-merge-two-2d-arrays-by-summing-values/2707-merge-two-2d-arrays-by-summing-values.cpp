class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& n1, vector<vector<int>>& n2) {
        map<int,int>m;
        for(vector<int>&arr:n1){
            m[arr[0]]+=arr[1];
        }
        for(vector<int>&arr:n2){
            m[arr[0]]+=arr[1];
        }
        vector<vector<int>>res;
        for(auto &i:m){
            res.push_back({i.first,i.second});
        }
        return res;
    }
};