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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        
        ListNode* parent = head;
        while(head && head->next){
            // else needed in case 1,1,1,2,3,3
            //ex: 1->1->2
            // at the next while iteration
            // head = 1, head->next = 2 as the duplicate was removed
            // so it will go to the else case
            // that's why the head=head->next is on the else only
            if(head->val == head->next->val){
                ListNode* tmp = head->next->next;
                head->next = tmp;
            }
            else
                head = head->next;
        }
        return parent;
    }
};
