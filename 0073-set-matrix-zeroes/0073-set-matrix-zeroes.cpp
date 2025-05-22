class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>copy(m,vector<int>(n,0));
        for(int i =0;i <m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == 0){
                    copy[i] = vector<int>(n,1);
                    for(int k = 0;k < m;k++){
                        copy[k][j] = 1;
                    }
                }
            }
        }
        for(int i =0;i <m;i++){
            for(int j = 0;j<n;j++){
                if(copy[i][j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};