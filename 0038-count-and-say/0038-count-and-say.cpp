class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 1; i < n; i++) {
            string next = "";
            char current = res[0];
            int count = 1;
            for (int j = 1; j < res.size(); j++) {
                if (res[j] == current) {
                    count++;
                } else {
                    next += to_string(count) + current;
                    current = res[j];
                    count = 1;
                }
            }
            next += to_string(count) + current;
            res = next;
        }
        return res;
    }
};
