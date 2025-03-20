class Solution {
public:
    vector<int> minimumCost(int numNodes, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<int> parent(numNodes), minEdgeCost(numNodes, -1);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> findRoot = [&](int node) {
            if (parent[node] != node) {
                parent[node] = findRoot(parent[node]);
            }
            return parent[node];
        };

        for (auto& edge : edges) {
            int nodeA = edge[0], nodeB = edge[1], edgeWeight = edge[2];
            int rootA = findRoot(nodeA);
            int rootB = findRoot(nodeB);

            minEdgeCost[rootB] &= edgeWeight;

            if (rootA != rootB) {
                minEdgeCost[rootB] &= minEdgeCost[rootA];
                parent[rootA] = rootB;
            }
        }

        vector<int> results;
        for (auto& query : queries) {
            int startNode = query[0], endNode = query[1];
            if (startNode == endNode) {
                results.push_back(0);
            } else if (findRoot(startNode) != findRoot(endNode)) {
                results.push_back(-1);
            } else {
                results.push_back(minEdgeCost[findRoot(startNode)]);
            }
        }
        return results;
    }
};
