#include "hashtable.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void* hashtable_get(HashTable* hashtable, char* key) {
	printf("Getting from hastable with key '%s'\n", key);
	size_t hash = hashtable_hash(key) % hashtable->size;
	printf("Hash: %lu\n", hash);

	// Handle conflicts with linear (keep going down the list until find the key or an open spot)
	while (hashtable->values[hash] != NULL) {
		if (strcmp(hashtable->keys[hash], key) == 0) {
			break;
		}
		hash = (hash + 1) % hashtable->size;
	}

	return (hashtable->values[hash]);
}

int hashtable_get_int(HashTable* hashtable, char* key) {
	void* value_ptr = hashtable_get(hashtable, key);
	if (value_ptr == NULL) {
		fprintf(stderr, "The key '%s' does not exist in the hashtable", key);
		// TODO perhaps this needs to end the program, force the user to check that the key exists first or something
		return (0);
	}

	int value = *((int *)value_ptr);

	return (value);
}

unsigned int hashtable_get_uint(HashTable* hashtable, char* key);
long int hashtable_get_long(HashTable* hashtable, char* key);
unsigned long int hashtable_get_ulong(HashTable* hashtable, char* key);

float hashtable_get_float(HashTable* hashtable, char* key);
double hashtable_get_double(HashTable* hashtable, char* key);

char hashtable_get_char(HashTable* hashtable, char* key);
char* hashtable_get_str(HashTable* hashtable, char* key);
