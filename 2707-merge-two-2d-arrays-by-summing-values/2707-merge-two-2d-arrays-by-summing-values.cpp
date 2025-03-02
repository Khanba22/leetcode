class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& n1,
                                    vector<vector<int>>& n2) {
        int i = 0, j = 0;
        vector<vector<int>> res;
        int n = n2.size();
        int m = n1.size();
        int k1,k2,v1,v2;
        while (i < m && j < n) {
            int k1 = n1[i][0];
            int k2 = n2[j][0];
            int v1 = n1[i][1];
            int v2 = n2[j][1];
            if (k1 == n2[j][0]) {
                res.push_back({k1, v1 + v2});
                i++;
                j++;
            } else if (k1 < k2) {
                res.push_back({k1, v1});
                i++;
            } else {
                res.push_back({k2, v2});
                j++;
            }
        }
        while (i < m) {
            res.push_back({n1[i][0], n1[i][1]});
            i++;
        }
        while (j < n) {
            res.push_back({n2[j][0], n2[j][1]});
            j++;
        }
        return res;
    }
};