/*
 *prev
 *tail   head
 *dummy   1    2    3   4    5
 *----------------------------
 *prev   head      tail
 *dummy   1    2    3   4    5
 *       cur
 *----------------------------
 * 每次让prev.next的元素插入到当前tail之后,这样tail不断前移,被挪动的元素头插入tail之后的链表
 *prev        tail head
 *dummy   2    3    1   4    5
 *       cur
 *----------------------------
 *prev   tail      head
 *dummy   3    2    1   4    5
 *       cur
 *----------------------------
 *                 prev
 *                 tail
 *                 head
 *dummy   3    2    1   4    5
 *----------------------------
 *                 prev  head     tail
 *dummy   3    2    1     4    5  null
 *----------------------------
 */
//这个遍历法解释比较易懂
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* pre=dummy;
        ListNode* cur=head;
        ListNode* tail=dummy;
        while(true){
            int count=0;
            tail=pre;
            while(tail!=NULL&&count<k){
                tail=tail->next; //退出循环后tail指向待反转链表的末尾节点
                count++;
            }
            if(tail==NULL)
                break;
            while(pre->next!=tail){ //pre->next==tail时退出循环
                cur=pre->next;//(1)
                pre->next=cur->next; //(1)  步骤(1):将cur从链表中切出来

                cur->next=tail->next;//(2)
                tail->next=cur; //(2) 步骤(2):将cur添加到tail后

            }
            pre=head;
            tail=head;
            head=pre->next;//head指向新的待翻转的链表头
        }
        return dummy->next;
    }
};
