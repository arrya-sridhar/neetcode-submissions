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

    bool checkval(ListNode* node, int n){
        for(int i=0;i<n-1;i++){
            if(node->next==nullptr) return false;
            else node = node->next;
        }
        if(node->next!=nullptr) return false;
        return true;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* pass = head;
        ListNode* prev = dummy;
        while(pass!=nullptr){
            if(checkval(pass,n)){
                prev->next = pass->next;
                break;
            }
            else{
                prev = pass;
                pass = pass->next;
            }
        }
        return dummy->next;
    }
};