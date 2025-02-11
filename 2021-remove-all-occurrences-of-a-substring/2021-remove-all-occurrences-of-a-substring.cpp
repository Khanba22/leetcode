class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res;
        int len = part.size();
        char back = part.back();

        for (char ch : s) {
            res.push_back(ch);

            if (ch == back && res.size() >= len) {
                if (res.substr(res.size() - len) == part) {
                    res.erase(res.size() - len);
                }
            }
        }
        return res;
    }
};