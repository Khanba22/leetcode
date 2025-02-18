class Solution {
public:
    void helper(string &pattern, int index, vector<bool>& visited, string &curr, string &res) {
        if (index == pattern.size() + 1) {
            if (res.empty() || curr < res) {
                res = curr;
            }
            return;
        }

        for (char i = '1'; i <= '9'; i++) {
            if (visited[i - '0']) continue;

            if (!curr.empty()) {
                char prev = curr.back();
                if ((pattern[index - 1] == 'I' && i <= prev) || 
                    (pattern[index - 1] == 'D' && i >= prev)) {
                    continue;
                }
            }

            curr.push_back(i);
            visited[i - '0'] = true;
            helper(pattern, index + 1, visited, curr, res);
            visited[i - '0'] = false;
            curr.pop_back();
        }
    }

    string smallestNumber(string pattern) {
        vector<bool> visited(10, false);
        string res, curr;
        helper(pattern, 0, visited, curr, res);
        return res;
    }
};
