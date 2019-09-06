#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* ans = new ListNode(0);
        ListNode* pre = ans;
        ans -> next = head;

        ListNode* cur = head;

        while( cur != NULL) {
            ListNode* next = cur->next;
            if (next == NULL)
                break;


            //1 -> 2 -> 3 ->4


            //2 -> 3 -> 4
            //1 -> 2 -> 3 ->4
            pre -> next = next;
            //2 -> 3 -> 4
            //1 -> 3 -> 4
            cur -> next = next -> next;
            //2 -> 1 -> 3 -> 4
            //1 -> 1 -> 3 -> 4
            next -> next = cur;


            //3 -> 4
            //3 -> 4
            pre = cur;
            cur = cur -> next;
        }

        return ans->next;

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
