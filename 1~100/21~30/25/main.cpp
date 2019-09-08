/*
 *prev
 *tail   head
 *dummy   1    2    3   4    5
 *----------------------------
 *prev   head      tail
 *dummy   1    2    3   4    5
 *       cur
 *----------------------------
 * ÿ����prev.next��Ԫ�ز��뵽��ǰtail֮��,����tail����ǰ��,��Ų����Ԫ��ͷ����tail֮�������
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
//������������ͱȽ��׶�
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
                tail=tail->next; //�˳�ѭ����tailָ�����ת�����ĩβ�ڵ�
                count++;
            }
            if(tail==NULL)
                break;
            while(pre->next!=tail){ //pre->next==tailʱ�˳�ѭ��
                cur=pre->next;//(1)
                pre->next=cur->next; //(1)  ����(1):��cur���������г���

                cur->next=tail->next;//(2)
                tail->next=cur; //(2) ����(2):��cur��ӵ�tail��

            }
            pre=head;
            tail=head;
            head=pre->next;//headָ���µĴ���ת������ͷ
        }
        return dummy->next;
    }
};
