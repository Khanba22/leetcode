class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1000000007;
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        while (t--) {
            long long a = freq[25];
            vector<int> newFreq(26, 0);

            for (int i = 24; i >= 0; i--) {
                newFreq[i + 1] = freq[i];
            }

            newFreq[0] = a;
            newFreq[1] = (newFreq[1] + a) % MOD;

            freq = move(newFreq);
        }

        long long res = 0;
        for (int count : freq) {
            res = (res + count) % MOD;
        }

        return res;
    }
};
