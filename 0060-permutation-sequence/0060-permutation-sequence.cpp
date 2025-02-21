class Solution {
public:
    bool helper(int n, int k, vector<bool>& visited, string& res, int& count, string& curr) {
        if (curr.size() == n) {
            count++;  
            if (count == k) { 
                res = curr;
                return true;
            }
            return false;
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                curr.push_back(i + '0');

                if (helper(n, k, visited, res, count, curr)) return true;

                visited[i] = false;
                curr.pop_back();
            }
        }
        return false;
    }

    string getPermutation(int n, int k) {
        vector<bool> visited(n + 1, false);
        string res = "";
        int count = 0;
        string curr = "";

        helper(n, k, visited, res, count, curr);
        return res;
    }
};
