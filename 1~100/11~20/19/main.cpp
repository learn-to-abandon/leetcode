#include <iostream>

using namespace std;

class Solution {
public:
    ListNode * removeNthFromEnd(ListNode* head, int n) {
        //�ƽڵ�
        ListNode * pre = new ListNode(0);
        pre->next = head;
        //˫ָ�룬ǰһ�����ƶ�n����������һ���ƶ���ֱ����һ������ĩβ
        ListNode *start = pre, *en = pre;
        while (n != 0) {
            start = start->next;
            n--;
        }

        while(start->next != nullptr) {
            start = start->next;
            en = en->next;
        }
        //ɾ����n��
        en->next = en->next->next;
        return pre->next;
    };
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
