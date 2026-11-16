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
        int upper = 0;
        ListNode* head = new ListNode();
        ListNode* curr = head;
        while(l1 || l2 || upper){
            ListNode* tpr = new ListNode();
            int rec = 0;
            if(l1 && l2){
                rec = l1->val + l2->val;
            }else if(l1){
                rec = l1->val;
            }else if(l2){
                rec = l2->val;
            }
            rec += upper;

            upper = rec / 10;
            tpr->val = rec % 10;

            curr->next = tpr;
            curr = tpr;

            if(l1){
               l1 = l1->next; 
            }
            if(l2){
                l2 = l2->next;
            }
            

        }
        return head->next;
    }
};
