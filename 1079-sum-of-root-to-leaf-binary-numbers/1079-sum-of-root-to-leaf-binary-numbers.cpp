
class Solution {
public:
    void preOrder(TreeNode *root,int &ans,int digit){
        //base case
        if(root == NULL){
            return ;
        }

        //binary to decimal convertion 
        digit = (digit << 1) | root -> val;

        //leaf node
        if(root -> left == NULL && root -> right == NULL){
            ans += digit;
            return ;
        }

        //recursive call
        preOrder(root -> left,ans,digit);
        preOrder(root -> right,ans,digit);

    }
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        // postOrder(root,ans,0);
        preOrder(root,ans,0);
        return ans;
    }
};