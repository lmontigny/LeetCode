// 83. Remove Duplicates from Sorted List
// from wen587sort 

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !(head->next)) return head;
        head->next = deleteDuplicates(head->next);
        return head->val == head->next->val ? head->next : head;
    }
};
