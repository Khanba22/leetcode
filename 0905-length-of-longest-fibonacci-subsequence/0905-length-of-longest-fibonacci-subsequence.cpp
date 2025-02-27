class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;

        unordered_map<int, int> indexMap;
        unordered_map<int, int> dp; 
        int maxLength = 0;

        for (int i = 0; i < n; i++) {
            indexMap[arr[i]] = i;
        }
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < j; i++) {
                int a = arr[i], b = arr[j];
                int prevIndex = indexMap.count(a + b) ? indexMap[a + b] : -1;

                if (prevIndex > j) {
                    int key = i * n + j;
                    int prevKey = j * n + prevIndex;
                    
                    dp[prevKey] = dp.count(key) ? dp[key] + 1 : 3;
                    maxLength = max(maxLength, dp[prevKey]);
                }
            }
        }

        return maxLength;
    }
};
