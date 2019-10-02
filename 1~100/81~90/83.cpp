/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* cur = head;
        ListNode* ans = new ListNode(cur->val);
        ListNode* res = ans;

        while (cur->next!=NULL){
            cur = cur->next;
            if (ans->val != cur->val){
                ans->next = new ListNode(cur->val);
                ans = ans->next;
            }
        }
        return res;
    }
};
