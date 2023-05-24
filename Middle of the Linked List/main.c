/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *p = head;
    struct ListNode *q = head;
    if (head->next == NULL)
    {
        return (head);
    }
    else if (head->next->next == NULL)
    {
        return (head->next);
    }
    else
    {
        while (p->next->next && q->next)
        {
            p = p->next;
            q = q->next->next;
            if (q == NULL)
                break;
        }
        return (p);
    }
}
