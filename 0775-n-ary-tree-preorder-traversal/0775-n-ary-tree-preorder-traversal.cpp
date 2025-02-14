/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void helper(Node *root,vector<int>&res){
        if(root == nullptr) return;
        res.push_back(root->val);
        for(Node* &i:root->children){
            helper(i,res);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int>res;
        helper(root,res);
        return res;
    }
};