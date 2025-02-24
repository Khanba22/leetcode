#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> bobSteps(n, -1);
        vector<int> trace;
        trackBobPath(bob, -1, trace, adj);
        
        for (int i = 0; i < trace.size(); i++) {
            bobSteps[trace[i]] = i;
        }

        return calcAliceProfit(0, -1, 0, bobSteps, adj, 0, amount);
    }

private:
    bool trackBobPath(int node, int parent, vector<int>& trace, vector<vector<int>>& adj) {
        if (node == 0) return true;
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                trace.push_back(node);
                if (trackBobPath(neighbor, node, trace, adj)) return true;
                trace.pop_back();
            }
        }
        return false;
    }

    int calcAliceProfit(int node, int parent, int score, vector<int>& bobSteps, vector<vector<int>>& adj, int time, vector<int>& amount) {
        if (bobSteps[node] == -1 || bobSteps[node] > time) {
            score += amount[node];
        } else if (bobSteps[node] == time) {
            score += amount[node] / 2;
        }
        if (adj[node].size() == 1 && node != 0) return score;
        int maxProfit = INT_MIN;
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                maxProfit = max(maxProfit, calcAliceProfit(neighbor, node, score, bobSteps, adj, time + 1, amount));
            }
        }
        return maxProfit;
    }
};
