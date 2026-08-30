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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carryover = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* pass = dummy;
        while(l1 or l2 or carryover){
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carryover;
            carryover = sum/10;
            pass->next = new ListNode(sum%10);
            pass = pass->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return dummy->next;
    }
};
