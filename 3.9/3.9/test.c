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
    //首先要找到相遇点，才能断开它
    struct ListNode* fast, * slow;
    fast = slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            //fast和slow现在就是相遇点，断开它和下一个结点并保存下一个结点的地址
            struct ListNode* newnode = slow->next;
            slow->next = NULL;
            //newnode就是新链表的头指针啦
      //开始求两个链表长度！
            int len1 = 0, len2 = 0;
            struct ListNode* tail1 = head, * tail2 = newnode;
            while (tail1)//计算链表1的长度
            {
                tail1 = tail1->next;
                ++len1;
            }
            while (tail2)//计算链表2的长度
            {
                tail2 = tail2->next;
                ++len2;
            }
            //两个链表长度是求出来来了，但不知道哪个是长链表哪个是短链表呀，所以还需要讨论下
            int gap = abs(len1 - len2);
            struct ListNode* longlist = head, * shortlist = newnode;
            if (len1 < len2)
            {
                longlist = newnode;
                shortlist = head;
            }
            //让长的链表先走长度差
            while (gap--)
            {
                longlist = longlist->next;
            }
            //然后两个链表再一起走，比较相同的时就是相交结点
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
    //判断是否有环
    struct ListNode* fast, * slow;
    fast = slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            //fast与slow现在就是相遇点
            //这时从开始点和相遇点同时走，当相等时，就是入环点
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