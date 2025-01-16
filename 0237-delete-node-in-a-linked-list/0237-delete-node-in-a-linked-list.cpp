/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode*ptr = node;
        ListNode*prev;
        while(ptr->next!=nullptr){
            ptr->val = ptr->next->val;
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = nullptr;
    }
};