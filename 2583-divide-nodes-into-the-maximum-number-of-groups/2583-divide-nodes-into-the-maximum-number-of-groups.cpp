class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>>g(n);
        for(int i = 0;i < edges.size();i++){
            g[edges[i][0] - 1].push_back(edges[i][1] - 1);
            g[edges[i][1] - 1].push_back(edges[i][0] - 1);
        }
        vector<int>dp(n);
        for(int i = 0;i < n;i++){
            queue<int>q;
            vector<int>dist(n);
            dist[i] = 1;
            q.push(i);
            int m = 1;
            int root = i;
            while(!q.empty()){
                int a = q.front();
                q.pop();
                root = min(root,a);
                for(int b:g[a]){
                    if(dist[b] == 0){
                        dist[b] = dist[a] + 1;
                        m = max(m,dist[b]);
                        q.push(b);
                    }else if(abs(dist[b]-dist[a]) != 1){
                        return -1;
                    }
                }
            }
            dp[root] = max(dp[root],m);
        }
        return accumulate(dp.begin(),dp.end(),0);
    }
};