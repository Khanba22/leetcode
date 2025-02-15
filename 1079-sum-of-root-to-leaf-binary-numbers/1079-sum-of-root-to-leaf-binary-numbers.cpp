
class Solution {
public:
    void preOrder(TreeNode *root,int &ans,int digit){
        if(root == NULL){
            return ;
        }

        digit = (digit << 1) | root -> val;

        if(root -> left == NULL && root -> right == NULL){
            ans += digit;
            return ;
        }

        preOrder(root -> left,ans,digit);
        preOrder(root -> right,ans,digit);

    }
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        preOrder(root,ans,0);
        return ans;
    }
};