class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& newIn) {
        vector<vector<int>>res;
        int i =0;
        while(i < in.size() && in[i][1] < newIn[0]){
            res.push_back(in[i++]);
        }
        while(i < in.size()&& in[i][0] <= newIn[1]){
            newIn = {min(newIn[0],in[i][0]),max(newIn[1],in[i][1])};
            i++;
        }
        res.push_back(newIn);
        while(i < in.size()){
            res.push_back(in[i]);
            i++;
        }
        return res;
    }
};