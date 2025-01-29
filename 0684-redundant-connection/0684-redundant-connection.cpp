class Solution {
public:
    unordered_map<int, vector<int>> graph;
    
    bool dfs(int source, int target, unordered_set<int>& visited) {
        if (source == target) return true; 
        visited.insert(source);
        
        for (int neighbor : graph[source]) {
            if (!visited.count(neighbor)) {
                if (dfs(neighbor, target, visited)) return true;
            }
        }
        
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            unordered_set<int> visited;

            if (graph.count(u) && graph.count(v) && dfs(u, v, visited)) {
                return edge;
            }

            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return {};
    }
};
