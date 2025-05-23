class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix(words.size() + 1, 0);
        int n = words.size();

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i];
            if (isVowel(words[i].front()) && isVowel(words[i].back())) {
                prefix[i + 1]++;
            }
        }

        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0], r = queries[i][1];
            res[i] = prefix[r + 1] - prefix[l];
        }

        return res;
    }
};
