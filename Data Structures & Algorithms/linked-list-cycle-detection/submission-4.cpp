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
    bool hasCycle(ListNode* head) {
        ListNode* head1 = head;
        ListNode* head2 = head;
        while(head2 != nullptr && head2->next != nullptr){
            head1 = head1->next;
            head2 = head2->next->next;            
            if (head1 == head2){
                return true;
            }
        }
    return false;
    }
};
