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
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* second = slow->next;
        ListNode* pre = nullptr;
        slow->next = nullptr;
        while(second){
            ListNode* tmp = second->next;
            second->next = pre;
            pre = second;
            second = tmp;
        }

        ListNode* first = head;
        second = pre;

        while(second!=nullptr){
            ListNode* fnext = first->next;
            ListNode* snext = second->next;
            first->next = second;
            second->next = fnext;
            first = fnext;
            second = snext;
        }

    }   
};
