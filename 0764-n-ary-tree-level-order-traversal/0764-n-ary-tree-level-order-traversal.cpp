/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {}; 

        deque<pair<Node*, int>> q;
        q.push_back({root, 0});
        vector<vector<int>> res;

        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop_front();

            if (res.size() == level) {
                res.push_back({});
            }
            res[level].push_back(node->val);

            for (auto child : node->children) {
                q.push_back({child, level + 1});
            }
        }
        return res;
    }
};
