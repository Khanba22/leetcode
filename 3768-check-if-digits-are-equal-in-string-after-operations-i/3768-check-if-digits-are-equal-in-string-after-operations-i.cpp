class Solution {
public:
    bool hasSameDigits(string s) {
        string temp;
        while (s.size() > 2) {
            for (int i = 1; i < s.size(); i++) {
                char c = (s[i] + s[i - 1] - '0' - '0') % 10;
                temp.push_back(c);
            }
            s = temp;
            temp = "";
        }
        return s[0] == s[1];
    }
};