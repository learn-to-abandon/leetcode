#include <iostream>

using namespace std;

class Solution {
public:
    ListNode * removeNthFromEnd(ListNode* head, int n) {
        //哑节点
        ListNode * pre = new ListNode(0);
        pre->next = head;
        //双指针，前一个先移动n个，再两个一起移动，直到第一个到达末尾
        ListNode *start = pre, *en = pre;
        while (n != 0) {
            start = start->next;
            n--;
        }

        while(start->next != nullptr) {
            start = start->next;
            en = en->next;
        }
        //删除第n个
        en->next = en->next->next;
        return pre->next;
    };
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
