class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& n1,
                                    vector<vector<int>>& n2) {
        int i = 0, j = 0;
        int m = n1.size(), n = n2.size();
        vector<vector<int>> res;
        res.reserve(m + n);  // Preallocate memory

        while (i < m && j < n) {
            int k1 = n1[i][0], v1 = n1[i][1]; 
            int k2 = n2[j][0], v2 = n2[j][1];

            if (k1 == k2) {
                res.push_back({k1, v1 + v2});
                i++;
                j++;
            } else if (k1 < k2) {
                res.push_back(move(n1[i])); 
                i++;
            } else {
                res.push_back(move(n2[j]));
                j++;
            }
        }
        
        while (i < m) res.push_back(move(n1[i++]));
        while (j < n) res.push_back(move(n2[j++]));

        return res;
    }
};
