#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode *pre = new ListNode(0);
         ListNode *cur = pre;
         int carry = 0;
         while (l1 != NULL || l2 != NULL) {
            int x = (l1 == NULL) ? 0 : l1->val;
            int y = (l2 == NULL) ? 0 : l2->val;
            int sum = x + y + carry;
            carry = sum / 10;
            sum  = sum % 10;
            cur->next = new ListNode(sum);
            cur = cur->next;
            if (l1 != NULL)
                l1 = l1->next;
            if (l2 != NULL)
                l2 = l2->next;
         }
         if (carry == 1)
             cur->next = new ListNode(1);
         return pre->next;
    }
};


int main()
{
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution solution;
    ListNode* l = solution.addTwoNumbers(l1,l2);

    while (l != NULL) {
        cout << l->val << " ";
        l = l->next;
    }
    return 0;
}
