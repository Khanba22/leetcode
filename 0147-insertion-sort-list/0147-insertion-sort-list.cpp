class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = head;
        
        while (curr && curr->next) {
            if (curr->val <= curr->next->val) {
                curr = curr->next;
                continue;
            }
            
            ListNode* toInsert = curr->next;
            curr->next = toInsert->next;
            
            ListNode* prev = dummy;
            while (prev->next && prev->next->val < toInsert->val) {
                prev = prev->next;
            }
            
            toInsert->next = prev->next;
            prev->next = toInsert;
        }
        
        return dummy->next;
    }
};
