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
    void helper(TreeNode * root,map<int,vector<int>>&s,int level){
        if(root == NULL) return;
        if(s.find(level)!= s.end()){
            s[level].push_back(root->val);
        }else{
            s[level] = {root->val};
        }
        helper(root->left,s,level+1);
        helper(root->right,s,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        // deque<pair<int,int>>q;
        // if(root == nullptr) return res;
        // q.push_back({root->val,0});
        // while(!q.empty()){
        //     auto p = q.front();
        //     q.pop_front();
            
        // }
        map<int,vector<int>>s;
        helper(root,s,0);
        for(auto &i:s){
            res.push_back(i.second);
        }
        return res;
    }
};