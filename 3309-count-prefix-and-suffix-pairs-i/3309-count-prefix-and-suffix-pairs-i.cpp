class Solution {
public:
    bool helper(const string& s1, const string& s2) {
        int n = s2.size();
        if (n > s1.size()) return false;

        if (s1.substr(0, n) != s2) return false;

        if (s1.substr(s1.size() - n) != s2) return false;

        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int res = 0;
        int n = words.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (helper(words[j], words[i])) {
                    res++;
                }
            }
        }

        return res;
    }
};
