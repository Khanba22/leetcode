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
    void flatten(TreeNode* root) {
        if (!root) return;

        stack<TreeNode*> st;
        st.push(root);
        TreeNode* prev = nullptr;

        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();

            if (prev) {
                prev->right = curr;
                prev->left = nullptr;
            }

            if (curr->right) st.push(curr->right);
            if (curr->left) st.push(curr->left);

            prev = curr;
        }
    }
};
