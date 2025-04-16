class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        return dfs(root, "");
    }

private:
    string dfs(TreeNode* node, string suffix) {
        if (!node) return "~";
        
        char currentChar = 'a' + node->val;
        string currentStr = currentChar + suffix;
        if (!node->left && !node->right) {
            return currentStr;
        }
        string left = dfs(node->left, currentStr);
        string right = dfs(node->right, currentStr);

        return min(left, right);
    }
};
