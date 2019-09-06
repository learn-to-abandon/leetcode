#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //简单地使用了第21题合并两个链表的函数
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        int len = lists.size();
        if (len == 1)
            return lists[0];
        ListNode* l = new ListNode(0);

        for (int i = 0; i < len; ++i)
             l->next = mergeTwoLists(l->next, lists[i]);
        return l->next;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
