class FindElements {
private:
    unordered_map<int, int> seen;

public:
    FindElements(TreeNode* root) {
        if (root) {
            root->val = 0;
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                TreeNode* node = q.front();
                q.pop();

                int val = node->val;
                seen[val]++;

                if (node->left) {
                    node->left->val = 2 * val + 1;
                    q.push(node->left);
                }
                if (node->right) {
                    node->right->val = 2 * val + 2;
                    q.push(node->right);
                }
            }
        }
    }

    bool find(int target) { return seen.count(target); }
};