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
    ListNode* begin;
    bool res=true; //assume palindrome
    
    bool isPalindrome(ListNode* head) {
        begin=head;
        traverse(head);
        return res;
    }
private:
    void traverse(ListNode* head){
        // Traverse until reaching the leaf node
        if(!head) return;
        traverse(head->next);
        
        if(head->val != begin->val){
            res = false;
        }
        
        // Move begin to the next
        // When head at the leaft node, move begin to next for the recursion before
        begin=begin->next;

        return;
    }
};
