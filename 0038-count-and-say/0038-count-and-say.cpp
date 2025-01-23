class Solution {
public:
    string helper(string &s, int n) {
        if (n == 1) return "1";
        string res = "";
        char current = s[0];
        int currCount = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == current) {
                currCount++;
            } else {
                res += to_string(currCount) + current;
                current = s[i];
                currCount = 1;
            }
        }
        res += to_string(currCount) + current;
        
        return res;
    }

    string countAndSay(int n) {
        string start = "1";
        for (int i = 1; i < n; i++) {
            start = helper(start, 2);
        }
        return start;
    }
};
