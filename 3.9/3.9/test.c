/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
1.
struct ListNode* detectCycle(struct ListNode* head)
{
    //����Ҫ�ҵ������㣬���ܶϿ���
    struct ListNode* fast, * slow;
    fast = slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            //fast��slow���ھ��������㣬�Ͽ�������һ����㲢������һ�����ĵ�ַ
            struct ListNode* newnode = slow->next;
            slow->next = NULL;
            //newnode�����������ͷָ����
      //��ʼ�����������ȣ�
            int len1 = 0, len2 = 0;
            struct ListNode* tail1 = head, * tail2 = newnode;
            while (tail1)//��������1�ĳ���
            {
                tail1 = tail1->next;
                ++len1;
            }
            while (tail2)//��������2�ĳ���
            {
                tail2 = tail2->next;
                ++len2;
            }
            //��������������������ˣ�����֪���ĸ��ǳ������ĸ��Ƕ�����ѽ�����Ի���Ҫ������
            int gap = abs(len1 - len2);
            struct ListNode* longlist = head, * shortlist = newnode;
            if (len1 < len2)
            {
                longlist = newnode;
                shortlist = head;
            }
            //�ó����������߳��Ȳ�
            while (gap--)
            {
                longlist = longlist->next;
            }
            //Ȼ������������һ���ߣ��Ƚ���ͬ��ʱ�����ཻ���
            while (longlist != shortlist)
            {
                longlist = longlist->next;
                shortlist = shortlist->next;
            }
            return longlist;
        }
    }
    return NULL;
}
2.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
    struct ListNode* detectCycle(struct ListNode* head)
{
    //�ж��Ƿ��л�
    struct ListNode* fast, * slow;
    fast = slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            //fast��slow���ھ���������
            //��ʱ�ӿ�ʼ���������ͬʱ�ߣ������ʱ�������뻷��
            while (head != slow)
            {
                head = head->next;
                slow = slow->next;
            }
            return head;
        }
    }
    return NULL;

}
3.
bool hasCycle(struct ListNode* head) {
    struct ListNode* fast, * slow;
    fast = slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            return true;
    }
    return false;
}