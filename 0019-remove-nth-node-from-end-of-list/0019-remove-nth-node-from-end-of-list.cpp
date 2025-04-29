/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int ahead(ListNode *head,int n){
        if(head == nullptr) return 0;
        int next = ahead(head->next,n);
        if(next == n){
            head->next = head->next->next;
        }
        return next+1;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ahead(dummy,n);
        return dummy->next;
    }
};