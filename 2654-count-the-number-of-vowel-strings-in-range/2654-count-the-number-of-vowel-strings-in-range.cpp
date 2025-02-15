class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int c = 0;
        vector<char> v = {'a', 'e', 'i', 'o', 'u'};
        for (; left <= right; left++) {
            string s = words[left];
            char b = s[0], e = s[s.size() - 1];

            if (find(v.begin(), v.end(), b) != v.end() &&
                find(v.begin(), v.end(), e) != v.end())
                c++;
        }

        return c;
    }
};