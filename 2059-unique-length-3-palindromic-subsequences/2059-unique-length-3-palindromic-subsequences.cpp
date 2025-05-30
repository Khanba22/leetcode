class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int res = 0;
        int n = s.size();
        vector<int> minIdx(26, -1), maxIdx(26, -1);

        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (minIdx[idx] == -1)
                minIdx[idx] = i;
            maxIdx[idx] = i;
        }

        for (int i = 0; i < 26; i++) {
            if (minIdx[i] != -1 && minIdx[i] < maxIdx[i]) {
                vector<bool> seen(26, false);
                for (int j = minIdx[i] + 1; j < maxIdx[i]; j++) {
                    if (!seen[s[j] - 'a']) {
                        seen[s[j] - 'a'] = true;
                        res++;
                    }
                }
            }
        }

        return res;
    }
};
