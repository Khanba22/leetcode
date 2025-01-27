class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre,
                                     vector<vector<int>>& queries) {
        vector<vector<int>> g(n, vector<int>(n, 0));
        for (int i = 0; i < pre.size(); i++) {
            g[pre[i][0]][pre[i][1]] = 1;
        }
        vector<bool> reachable(queries.size(), false);
        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int target = queries[i][1];
            queue<int> q;
            vector<bool> visited(n, false);
            q.push(start);
            visited[start] = true;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (u == target) {
                    reachable[i] = true;
                    break;
                }
                for (int v = 0; v < n; v++) {
                    if (g[u][v] && !visited[v]) { 
                        q.push(v);
                        visited[v] = true;
                    }
                }
            }
        }
        
        return reachable;
    }
};
