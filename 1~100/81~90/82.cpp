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
        if (head->next == NULL) return head;
        ListNode* cur = head;
        ListNode* pre = new ListNode(0);
        ListNode* res = pre;
        int f = -1000;

        while (cur->next!=NULL){
            if (cur->val != f && cur->next->val != cur->val){
                    pre->next = new ListNode(cur->val);
                    pre = pre->next;
            }
            f = cur->val;
            cur = cur->next;
        }
        if (cur->val!=f) pre->next = new ListNode(cur->val);
        return res->next;
    }
};
