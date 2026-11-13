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
        int count = 0;
        ListNode* rec = head;
        while(rec){
            count++;
            rec=rec->next;
        }
        ListNode* head1 = head;
        ListNode* head1prev = nullptr;
        for(int i = 0; i < (count+1) / 2; i++){
            head1prev = head1;
            head1 = head1->next;
        }
        head1prev->next = nullptr;
        ListNode* prev = nullptr;
        while(head1){
            ListNode* temp = head1->next;
            head1->next = prev;
            prev = head1;
            head1 = temp;
        }
        ListNode* first = head;
        ListNode* second = prev;
        while(second){
            ListNode* nextf = first->next;
            ListNode* nexts = second->next;

            first->next = second;
            second->next = nextf;
            first = nextf;
            second = nexts;
        }
    }
};
