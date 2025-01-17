
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head == nullptr) return true;
        if(root == nullptr) return false;
        if(head->val == root->val){
            return isSubPath(head->next,root->left) || isSubPath(head->next,root->left);
        }
        return false;
    }
};