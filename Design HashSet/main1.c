#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


// ======================== Second Solution =================
/*
the efficiency of this code depends on the distribution of keys and the number 
of elements in the hash set. If the hash function provides a good distribution of keys across 
the hash table, and the number of collisions (i.e., elements hashing to the same bucket) is low, 
the performance will be better. However, if there are many collisions, and the linked lists 
become long, the efficiency will degrade.
*/


struct ListNode
{
	int				val;
	struct ListNode	*next;
};

#define HT_SIZE 10000

typedef struct {
    struct ListNode	*HT[HT_SIZE];
} MyHashSet;

void	SortedInsert(struct ListNode **head, int key)
{
	struct ListNode	*p;
	struct ListNode	*q;
	struct ListNode	*newNode;

	newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
	newNode->val = key;
	newNode->next = NULL;
	if (*head == NULL)
		*head = newNode;
	else if ((*head)->val > key)
	{
		newNode->next = *head;
		*head = newNode;
	}
	else
	{
		p = *head;
		q = NULL;
		while (p && p->val < key)
		{
			q = p;
			p = p->next;
		}
		if (p && p->val == key)
		{
			free(newNode);
			return;
		}
		if (q)
		{
			newNode->next = q->next;
			q->next = newNode;
		}
	}
}

void	Delete(struct ListNode **head, int key)
{
	struct ListNode	*p;
	struct ListNode	*q;

	if (*head == NULL)
		return;
	if ((*head)->val == key)
		*head = (*head)->next;
	else
	{
		p = *head;
		q = NULL;
		while (p && p->val < key)
		{
			q = p;
			p = p->next;
		}
		if (p && p->val == key)
		{
			q->next = p->next;
			free(p);
		}
	}
}

bool	Serach(struct ListNode *head, int key)
{
	struct ListNode	*p;

	p = head;
	while (p && p->val < key)
		p = p->next;
	if (p && p->val == key)
		return (true);
	return (false);
}

MyHashSet* myHashSetCreate() {
    MyHashSet	*obj;

	obj = (MyHashSet *)malloc(sizeof(MyHashSet));
	for (int i = 0; i < HT_SIZE; i++)
		obj->HT[i] = NULL;
	return (obj);
}

void myHashSetAdd(MyHashSet* obj, int key) {
	SortedInsert(&obj->HT[key % HT_SIZE], key);
}

void myHashSetRemove(MyHashSet* obj, int key) {
	Delete(&obj->HT[key % HT_SIZE], key);
}

bool myHashSetContains(MyHashSet* obj, int key) {
	return (Serach(obj->HT[key % HT_SIZE], key));
}

void myHashSetFree(MyHashSet* obj) {
	struct ListNode	*temp;

	for (int i = 0; i < HT_SIZE; i++)
	{
		while (obj->HT[i])
		{
			temp = obj->HT[i];
			obj->HT[i] = obj->HT[i]->next;
			free(temp);
		}
	}
	free(obj);
}
