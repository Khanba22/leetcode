class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> lir(m, n);
        vector<int> lic(n, m);
        vector<pair<int,int>>pos((m*n)+1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pos[mat[i][j]] = {i, j};
            }
        }
        for(int i = 0;i < arr.size();i++){
            auto position = pos[arr[i]];
            int x = position.first;
            int y = position.second;
            lir[x]--;
            if(lir[x] == 0) return i;
            lic[y]--;
            if(lic[y] == 0) return i;
        }
        return -1;
    }
};