// 2. Add Two Numbers


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return NULL;
        else if (!l1) return l2; 
		    else if (!l2) return l1;
        
        int sum = l1->val + l2->val;
        ListNode *p = new ListNode(sum % 10);
        p->next = addTwoNumbers(l1->next,l2->next);
        if (sum >= 10) p->next = addTwoNumbers(p->next, new ListNode(1));
        return p;

        /*
        not working for [1] [9,9]
        l1->next = addTwoNumbers(l1->next, l2->next);
        l1->val += l2->val;
        if(l1->val >= 10) {
            if(l1->next) ++l1->next->val;
            else l1->next = new ListNode(1);
            l1->val %= 10;
        }
        return l1; 
        */
    }
};
