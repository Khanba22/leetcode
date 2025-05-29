class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int n = words.size();
        vector<bool> visited(n, false);
        int ptr = 0;
        for (int i = 0; i < n; i++) {
            if (s.substr(ptr, words[i].size()) == words[i]) {
                ptr += words[i].size();
            } else if (ptr == s.size())
                return true;
            else
                return false;
        }
        return ptr == s.size();
    }
};