#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int     val;
    struct  ListNode *next;
};

struct  ListNode *reverseList(struct ListNode *head)
{
    struct  ListNode *p;
    struct  ListNode *q;
    struct  ListNode *r;

    p = head;
    q = NULL;
    r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return (q);
}

int main(void)
{
    struct  ListNode *head;
    struct  ListNode *p;
    struct  ListNode *q;
    int     i;

    head = NULL;
    for (i = 0; i < 10; i++)
    {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val = i;
        p->next = NULL;
        if (head == NULL)
            head = p;
        else
            q->next = p;
        q = p;
    }
    p = head;
    while (p)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
    head = reverseList(head);
    p = head;
    while (p)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
    return (0);
}