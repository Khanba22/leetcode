class Solution {
public:
    int i=0, j=0;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        const int n=preorder.size();
        TreeNode* root=new TreeNode(preorder[0]);
        vector<TreeNode*> stack={root};
        for(int i=1, j=0; i<n; i++){
            TreeNode* node=new TreeNode(preorder[i]);
            while(stack.back()->val==postorder[j]){
                stack.pop_back();
                j++;
            }
            if (stack.back()->left==NULL) stack.back()->left=node;
            else stack.back()->right=node;
            stack.push_back(node);
        }
        return root;
    }
};