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
    ListNode* merge(int left, int right, vector<ListNode*>& lists){
        if (left == right){
            return lists[left];
        }
        
        ListNode* l = merge(left, (left + right) / 2, lists);
        ListNode* r = merge((left + right) / 2 + 1, right, lists);
        ListNode dummy(0);
        ListNode* p = &dummy;

        while(l || r){
            if(!l){
                p->next = r;
                r = r->next;
            }else if(!r){
                p->next = l;
                l = l->next;
            }else{
                if(l->val > r->val){
                    p->next = r;
                    r = r->next;
                }else{
                    p->next = l;
                    l = l->next;
                }
            }
            p = p->next;
        }
        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        return lists.empty() ? nullptr : merge(0, lists.size() - 1, lists);
    }
};
