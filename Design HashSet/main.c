#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ======================== END : First Solution =================
/*
The bit array implementation offers a space-efficient solution, especially when the key 
range is significantly larger than the number of keys actually present. It allows you 
to use bitwise operations to store and retrieve key presence information.
*/



#define HT_SIZE 1000000

typedef struct {
    unsigned char	*bitArray;
} MyHashSet;


MyHashSet* myHashSetCreate() {
    MyHashSet	*obj;
	obj = (MyHashSet *)malloc(sizeof(MyHashSet));
	int numBits = (HT_SIZE / 8) + 1;
	obj->bitArray = (unsigned char *)malloc(sizeof(char) * numBits);
	memset(obj->bitArray, 0, numBits);
	return (obj);
}

void myHashSetAdd(MyHashSet* obj, int key) {
	int byteIndex = key / 8;
	int bitOffset = key % 8;
	unsigned char mask = 1 << bitOffset;
	obj->bitArray[byteIndex] |= mask;
}

void myHashSetRemove(MyHashSet* obj, int key) {
	int byteIndex = key / 8;
	int bitOffset = key % 8;
	unsigned char mask = ~(1 << bitOffset);
	obj->bitArray[byteIndex] &= mask;
}

bool myHashSetContains(MyHashSet* obj, int key) {
	int byteIndex = key / 8;
	int bitOffset = key % 8;
	unsigned char mask = 1 << bitOffset;
	if ((obj->bitArray[byteIndex] & mask) == 1)
		return (true);
	return (false);
}

void myHashSetFree(MyHashSet* obj) {
    free(obj->bitArray);
	free(obj);
}

// ======================== END : First Solution =================

