// From https://discuss.leetcode.com/topic/17916/8ms-c-iterative-and-recursive-solutions-with-explanations
// 206. Reverse Linked List


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !(head->next)) return head;
        ListNode* node = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return node; 
    }
};
