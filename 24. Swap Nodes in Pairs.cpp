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
    //invert the first 2 and then recurse for the rest
    ListNode* swapPairs(ListNode* head) {
        //base case here
        if(!head || !head->next) return head;
        
        cout << head->val << endl; // input 1,2,3,4 output:1,3
        ListNode *temp = head->next;
        head->next = swapPairs(temp->next); 
        temp->next = head;

        return temp;
    }
};
