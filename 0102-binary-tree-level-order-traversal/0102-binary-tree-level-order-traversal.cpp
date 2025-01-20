/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        deque<pair<int, TreeNode*>> q;
        q.push_back({0, root});

        vector<vector<int>> res;

        while (!q.empty()) {
            auto elem = q.front();
            q.pop_front();

            int level = elem.first;
            TreeNode* node = elem.second;

            if (res.size() == level) {
                res.push_back({node->val});
            } else {
                res[level].push_back(node->val);
            }

            if (node->left) {
                q.push_back({level + 1, node->left});
            }
            if (node->right) {
                q.push_back({level + 1, node->right});
            }
        }

        return res;
    }
};
