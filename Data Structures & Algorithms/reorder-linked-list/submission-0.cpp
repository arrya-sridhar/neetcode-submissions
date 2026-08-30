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
    void reorderList(ListNode* head) {
        ListNode* pass = head;
        ListNode* half = head;
        ListNode* left = head;
        while(pass->next!=nullptr and pass->next->next!=nullptr){
            pass = pass->next->next;
            half = half->next;
        }
        ListNode* start = half->next;
        half->next = nullptr;
        ListNode* right = start;
        ListNode* nxt = nullptr;
        ListNode* prev = nullptr;
        while(start!=nullptr){
            nxt = start->next;
            start->next = prev;
            prev = start;
            start = nxt; 
        }
        right = prev;
        ListNode* dummy = new ListNode(0);
        while(right!=nullptr){
            dummy->next = left;
            left = left->next;
            dummy = dummy->next;
            dummy->next = right;
            right = right->next;
            dummy = dummy->next;
        }
        dummy->next = left;
    }
};
