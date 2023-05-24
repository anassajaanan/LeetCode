#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// ======================== Third Solution =================
/*
In the ideal hashing approach, you would allocate an array of a suitable size 
(based on the key range) and directly access the array indices using the keys. 
This results in constant-time operations for insertion, removal, and lookup, 
as there is no need for any bitwise operations or searching for bits in a bit array.
*/

#define HT_SIZE 1000001

typedef struct {
	int HT[HT_SIZE];
} MyHashSet;


MyHashSet* myHashSetCreate() {
	MyHashSet	*obj;
	obj = (MyHashSet *)malloc(sizeof(MyHashSet));
	return (obj);
}

void myHashSetAdd(MyHashSet* obj, int key) {
	obj->HT[key] = key;
}

void myHashSetRemove(MyHashSet* obj, int key) {
	obj->HT[key] = -1;
}

bool myHashSetContains(MyHashSet* obj, int key) {
	return (obj->HT[key] == key);
}

void myHashSetFree(MyHashSet* obj) {
    free(obj);
}