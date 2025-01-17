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
    int helper(TreeNode*root,int &maxi){
        if(root == nullptr) return 0;
        int left = helper(root->left,maxi);
        int right = helper(root->right,maxi);
        int total = left + right + root->val;
        int maxBranch = max(left,right) + root->val;
        int rootVal = root->val;
        maxi = max(maxi,max(maxBranch,max(total,root->val)));
        return max(maxBranch,rootVal); 
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        helper(root,maxi);
        return maxi;
    }
};