#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        
        vector<vector<pair<int, int>>> graph(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }

        vector<long long> minTime(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        pq.push({0, 0});
        minTime[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            auto [currTime, u] = pq.top();
            pq.pop();

            if (currTime > minTime[u]) continue;

            for (auto& [v, time] : graph[u]) {
                long long newTime = currTime + time;

                if (newTime < minTime[v]) {
                    minTime[v] = newTime;
                    ways[v] = ways[u];
                    pq.push({newTime, v});
                } else if (newTime == minTime[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
