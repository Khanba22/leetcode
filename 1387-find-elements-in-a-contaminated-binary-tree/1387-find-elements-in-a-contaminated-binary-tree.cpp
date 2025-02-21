class FindElements {
public:
    unordered_map<int,bool> treeData;
    
    void recoverTree(TreeNode* root, int rootVal) {
        if (root == nullptr) return ;
        root->val = rootVal;
        treeData[rootVal] = true;
        recoverTree(root->left, rootVal*2 + 1);
        recoverTree(root->right, rootVal*2 + 2);
    }

    FindElements(TreeNode* root) {
        recoverTree(root, 0);
    }
    
    bool find(int target) {
        return target < treeData.size() && treeData[target];
    }
};
