class Solution {
  public:
      vector<int> queryResults(int limit, vector<vector<int>>& queries) {
          unordered_map<int, int> node, color;
          vector<int> ans;
  
          for (auto& q : queries) {
              int x = q[0], y = q[1];
  
              if (node.count(x)) {
                  int prev = node[x];
                  if (prev == y) {
                      ans.push_back(color.size());
                      continue;
                  }
                  if (--color[prev] == 0) color.erase(prev);
              }
  
              node[x] = y;
              color[y]++;
              ans.push_back(color.size());
          }
  
          return ans;
      }
  };