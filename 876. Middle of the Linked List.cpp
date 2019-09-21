    // Fast and Slow pointer
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }
    
    
    // OR (mine)
    
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
    ListNode* res;
    int depth = 0;
    
    ListNode* middleNode(ListNode* head) {
        int tmp = helper(head);        
        int mid = depth/2+1;
        clean(head,mid,0);
        return res;
    }
    
private:
    int helper(ListNode* head){
        if(!head) return -1;
        depth++;
        return helper(head->next); 
    }
    
    void clean(ListNode* head, int mid, int level){
        if(!head) return;
        level++;
        
        if(level==mid){
            res = head;
            return;
        }
        
        clean(head->next, mid, level);
    }
};
