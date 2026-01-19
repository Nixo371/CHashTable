#include "hashtable.h"

#include <stdlib.h>
#include <string.h>

// TODO should I make this a "private" function and require a size?
// The value should be allocated previously, the key will be copied for ease of use with raw strings (hashtable_insert_int(hashtable, "example", 20))
int hashtable_insert(HashTable* hashtable, char* key, void* value) {
	// printf("Inserting into hashtable with key '%s'\n", key);
	size_t hash = hashtable_hash(key) % hashtable->size;
	// printf("Hash: %lu\n", hash);

	// Handle conflicts with linear (keep going down the list until find the key or an open spot)
	while (hashtable->keys[hash] != NULL) {
		// TODO Check if key is already in table
		if (strcmp(hashtable->keys[hash], key) == 0) {
			// TODO what happens if you try to insert and the key is already in the table?
			// replace? perhaps makes more sense to have this be a separate function?
			// error?
			// For now I'll throw an error
			return (-1); // Maybe I need to have error codes in an ENUM?
		}
		hash = (hash + 1) % hashtable->size;
	}
	size_t key_len = strlen(key);
	hashtable->keys[hash] = malloc((key_len + 1) * sizeof(char *));
	// hashtable->values[hash] = malloc(1 * sizeof(void *));

	strncpy(hashtable->keys[hash], key, key_len + 1);
	hashtable->values[hash] = value;

	hashtable->load++;
	double load_factor = (double)hashtable->load / hashtable->size;
	if (load_factor > hashtable->max_load_factor) {
		hashtable_resize(hashtable, hashtable->size * 2);
	}

	return (0);
}

int hashtable_insert_int(HashTable* hashtable, char* key, int value) {
	void* value_ptr = (void *) malloc(1 * sizeof(int));
	*((int *)value_ptr) = value; // absolutely fucking disgusting

	return (hashtable_insert(hashtable, key, value_ptr));
}

int hashtable_insert_uint(HashTable* hashtable, char* key, unsigned int value) {
	void* value_ptr = (void *) malloc(1 * sizeof(unsigned int));
	*((unsigned int *)value_ptr) = value; // absolutely fucking disgusting

	return (hashtable_insert(hashtable, key, value_ptr));
}

int hashtable_insert_long(HashTable* hashtable, char* key, long int value) {
	void* value_ptr = (void *) malloc(1 * sizeof(long int));
	*((long int *)value_ptr) = value; // absolutely fucking disgusting

	return (hashtable_insert(hashtable, key, value_ptr));
}

int hashtable_insert_ulong(HashTable* hashtable, char* key, long unsigned int value) {
	void* value_ptr = (void *) malloc(1 * sizeof(long unsigned int));
	*((long unsigned int *)value_ptr) = value; // absolutely fucking disgusting

	return (hashtable_insert(hashtable, key, value_ptr));
}

int hashtable_insert_float(HashTable* hashtable, char* key, float value) {
	void* value_ptr = (void *) malloc(1 * sizeof(float));
	*((float *)value_ptr) = value; // absolutely fucking disgusting

	return (hashtable_insert(hashtable, key, value_ptr));
}

int hashtable_insert_double(HashTable* hashtable, char* key, double value) {
	void* value_ptr = (void *) malloc(1 * sizeof(double));
	*((double *)value_ptr) = value; // absolutely fucking disgusting

	return (hashtable_insert(hashtable, key, value_ptr));
}

int hashtable_insert_char(HashTable* hashtable, char* key, char value) {
	void* value_ptr = (void *) malloc(1 * sizeof(char));
	*((char *)value_ptr) = value; // absolutely fucking disgusting

	return (hashtable_insert(hashtable, key, value_ptr));
}

int hashtable_insert_str(HashTable* hashtable, char* key, char* value) {
	int value_len = strlen(value);
	void* value_ptr = (void *) malloc((value_len + 1) * sizeof(char));
	strncpy(value_ptr, value, value_len + 1); // should null-terminate the string
	
	return (hashtable_insert(hashtable, key, value_ptr));
}

