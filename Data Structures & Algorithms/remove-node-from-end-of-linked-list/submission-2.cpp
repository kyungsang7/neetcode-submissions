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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* left = head;
        ListNode* right = head;
        for(int i = 0; i < n; i++){
            right = right->next;
        }
        ListNode* prev = nullptr;
        while(right){
            prev = left;
            left = left->next;
            right = right->next;
        }
        if(!prev){
            return head->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};
