class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& n1,
                                    vector<vector<int>>& n2) {
        int i = 0, j = 0;
        vector<vector<int>> res;
        int n = n2.size();
        int m = n1.size();
        while (i < m && j < n) {
            if (n1[i][0] == n2[j][0]) {
                res.push_back({n1[i][0], n1[i][1] + n2[j][1]});
                i++;
                j++;
            } else if (n1[i][0] < n2[j][0]) {
                res.push_back({n1[i][0], n1[i][1]});
                i++;
            } else {
                res.push_back({n2[j][0], n2[j][1]});
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