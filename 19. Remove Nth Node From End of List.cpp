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

    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        
        // Give fast point an advance of n steps
        while(n--){
            fast = fast->next;
        }
        // if fast is NULL, n is equal to the length of the linked list
        // then need to remove the first node (head) so return the next node directly
        if(!fast)
            return head->next;
        
        // Start to move slow and fast together, the delta will stay the same
        // When the end of the list is reached, the node to be deleted has been found (slow->next)
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return head;
    }
};
