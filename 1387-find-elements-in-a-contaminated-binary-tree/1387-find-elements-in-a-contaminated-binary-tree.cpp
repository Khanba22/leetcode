class FindElements {
public:
    vector<bool> treeData;
    
    int recoverTree(TreeNode* root, int rootVal) {
        if (root == nullptr) return 0;
        root->val = rootVal;
        return max(recoverTree(root->left, 2 * rootVal + 1), 
                   recoverTree(root->right, 2 * rootVal + 2)) + 1;
    }

    void setUp(TreeNode* root) {
        if (root == nullptr) return;
        if (root->val < treeData.size()) {
            treeData[root->val] = true;
        }
        setUp(root->left);
        setUp(root->right);
    }

    FindElements(TreeNode* root) {
        if (!root) return;
        int depth = recoverTree(root, 0);
        treeData.resize((1 << depth), false); 
        setUp(root);
    }
    
    bool find(int target) {
        return target < treeData.size() && treeData[target];
    }
};
