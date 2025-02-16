class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> res(2 * n - 1, 0);
        vector<bool> visited(n + 1, false);
        helper(res, visited, n, 0);
        return res;
    }

    bool helper(vector<int>& res, vector<bool>& visited, int n, int x) {
        while (x < res.size() && res[x] != 0) {
            x++;
        }
        if (x == res.size()) {
            return true;
        }

        for (int i = n; i >= 1; i--) {
            if (visited[i])
                continue;

            if (i == 1) {
                res[x] = 1;
                visited[1] = true;
                if (helper(res, visited, n, x + 1))
                    return true;
                res[x] = 0;
                visited[1] = false;
            } else if (x + i < res.size() && res[x + i] == 0) {
                res[x] = i;
                res[x + i] = i;
                visited[i] = true;
                if (helper(res, visited, n, x + 1))
                    return true;
                res[x] = 0;
                res[x + i] = 0;
                visited[i] = false;
            }
        }
        return false;
    }
};