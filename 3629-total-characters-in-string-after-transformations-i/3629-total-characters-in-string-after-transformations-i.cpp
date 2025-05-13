class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int MOD = 1e9 + 7;
        vector<long> cnts(26, 0);

        for (char c : s) {
            cnts[c - 'a']++;
        }

        while (t >= 26) {
            vector<long> tmp(26, 0);
            for (int i = 0; i < 25; ++i) {
                tmp[i + 1] += cnts[i];
            }

            tmp[0] += cnts[25];
            tmp[1] += cnts[25];

            for (int i = 0; i < 26; ++i) {
                cnts[i] = (cnts[i] + tmp[i]) % MOD;
            }

            t -= 26;
        }

        long ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + cnts[i]) % MOD;
            if (i + t >= 26) {
                ans = (ans + cnts[i]) % MOD;
            }
        }

        return ans;
    }
};
