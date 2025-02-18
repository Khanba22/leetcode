class Solution {
public:
    void helper(string &pattern, int index, vector<bool>& visited, string &curr, string &res) {
        if (index == pattern.size() + 1) {
            if (res.empty() || curr < res) {
                res = curr;
            }
            return;
        }

        for (int i = 1; i <= 9; i++) {
            if (visited[i]) continue;
            char ci = i + '0';
            if (index) {
                char prev = curr.back();
                if ((pattern[index - 1] == 'I' && ci <= prev) || 
                    (pattern[index - 1] == 'D' && ci >= prev)) {
                    continue;
                }
            }
            curr.push_back(ci);
            visited[i] = true;
            helper(pattern, index + 1, visited, curr, res);
            visited[i] = false;
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
