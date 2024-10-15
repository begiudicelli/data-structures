#ifndef HASH_MAP_HASH_MAP_H_
#define HASH_MAP_HASH_MAP_H_

#define MAX_DATA 256
#define HASHTABLE_SIZE 11

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

typedef struct HashNode{
	char data[MAX_DATA];
	struct HashNode* next;
}HashNode;

HashNode** getHashTable();
unsigned int hash(char *str);
void insertIntoTable(HashNode** hashtable, char *str);
void displayTable(HashNode** hashtable);
void displayNode(HashNode* current);
void displayHashMenu();



#endif
