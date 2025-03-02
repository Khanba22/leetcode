class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& n1,
                                    vector<vector<int>>& n2) {
        int i = 0, j = 0;
        vector<vector<int>> res;
        while (i < n1.size() && j < n2.size()) {
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
        while (i < n1.size()) {
            res.push_back({n1[i][0], n1[i][1]});
            i++;
        }
        while (j < n2.size()) {
            res.push_back({n2[j][0], n2[j][1]});
            j++;
        }
        return res;
    }
};