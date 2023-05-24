#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HM_SIZE 1333

struct Node 
{
	int			key;
	int			value;
	struct Node	*next;
};


typedef struct {
    struct Node *HM[HM_SIZE];
} MyHashMap;


static inline MyHashMap* myHashMapCreate() {
    MyHashMap *obj;

	obj = (MyHashMap *)malloc(sizeof(MyHashMap));
	for (int i = 0; i < HM_SIZE; i++)
		obj->HM[i] = NULL;
	return (obj);
}

static inline void myHashMapPut(MyHashMap* obj, int key, int value) {
	struct Node	*p;
	struct Node	*q;
	struct Node	*newNode;

	newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->key = key;
	newNode->value = value;
	newNode->next = NULL;
	if (obj->HM[key % HM_SIZE] == NULL)
		obj->HM[key % HM_SIZE] = newNode;
	else if (obj->HM[key % HM_SIZE]->key > key)
	{
		newNode->next = obj->HM[key % HM_SIZE];
		obj->HM[key % HM_SIZE] = newNode;
	}
	else
	{
		p = obj->HM[key % HM_SIZE];
		q = NULL;
		while (p && p->key < key)
		{
			q = p;
			p = p->next;
		}
		if (p && p->key == key)
		{
			p->value = value;
			return;
		}
		if (q)
		{
			newNode->next = q->next;
			q->next = newNode;
		}
	}
}

static inline int myHashMapGet(MyHashMap* obj, int key) {
	struct Node	*p;

	p = obj->HM[key % HM_SIZE];
	while (p && p->key < key)
		p = p->next;
	if (p && p->key == key)
		return (p->value);
	return (-1);
}

static inline void myHashMapRemove(MyHashMap* obj, int key) {
	struct Node	*p;
	struct Node	*q;

	if (obj->HM[key % HM_SIZE] == NULL)
		return;
	if ((obj->HM[key % HM_SIZE])->key == key)
		obj->HM[key % HM_SIZE] = obj->HM[key % HM_SIZE]->next;
	else
	{
		p = obj->HM[key % HM_SIZE];
		q = NULL;
		while (p && p->key < key)
		{
			q = p;
			p = p->next;
		}
		if (p && p->key == key)
		{
			q->next = p->next;
			free(p);
		}
	}
}

static inline void myHashMapFree(MyHashMap* obj) {
    struct Node *temp;
	for (int i = 0; i < HM_SIZE; i++)
	{
		while (obj->HM[i])
		{
			temp = obj->HM[i];
			obj->HM[i] = obj->HM[i]->next;
			free(temp);
		}
	}
	free(obj);
}
