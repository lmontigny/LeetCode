/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    std::unordered_set<ListNode*> htable;
public:
    bool hasCycle(ListNode *head) {
        while(head){
            if(htable.count(head))
                return true;
            htable.insert(head);           
            head=head->next;
        }
        return false;
    }
};
