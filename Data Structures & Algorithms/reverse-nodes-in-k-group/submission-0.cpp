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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        while(true) {
            ListNode* end = prev;

            for(int i = 0; i < k && end; i++) {
                end = end->next;
            }

            if(!end) break;

            ListNode* start = prev->next;
            ListNode* next_node = end->next;

            ListNode* cur = start;
            ListNode* pre = next_node;

            while(cur != next_node) {
                ListNode* next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }

            prev->next = end;
            prev = start;
        }

        return dummy.next;
    }
};