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
        ListNode* prev = &dummy;
        ListNode* start = head;
        ListNode* end = head;
        dummy.next = head;

        while(true){
            for(int i = 0; i < k - 1 && head; i++){
                head = head->next;
            }

            if(!head){
                break;
            }

            head = head->next;

            ListNode* ptr = head;
            for(int i = 0; i < k; i++){
                ListNode* next = start->next;
                start->next = ptr;
                ptr = start;
                start = next;
            }

            prev->next = ptr;
            end->next = head;

            prev = end;
            start = head;
            end = head;
        }
        return dummy.next;
    }
};
