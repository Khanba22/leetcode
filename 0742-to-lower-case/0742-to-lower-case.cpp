class Solution {
public:
    string toLowerCase(string s) {
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                res.push_back(s[i] - 'A' + 'a');
            } else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};
