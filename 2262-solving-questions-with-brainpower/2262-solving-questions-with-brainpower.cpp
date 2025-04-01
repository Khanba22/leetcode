class Solution {
public:
    long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            long take = questions[i][0]; 
            int nextIdx = i + questions[i][1] + 1;
            if (nextIdx < n) take += dp[nextIdx]; 

            long dontTake = dp[i + 1];

            dp[i] = max(take, dontTake);
        }

        return dp[0];
    }
};
