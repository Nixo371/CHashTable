#include "hashtable.h"

#include <stdlib.h>
#include <string.h>

HashTable* hashtable_create() {
	return (hashtable_create_ex(128, 0.6));
}

HashTable* hashtable_create_ex(size_t starting_size, double max_load_factor) {
	HashTable* hashtable = (HashTable *) malloc(sizeof(HashTable));
	hashtable->load = 0;
	hashtable->size = starting_size;
	hashtable->max_load_factor = max_load_factor;

	hashtable->keys = (char **) malloc(hashtable->size * sizeof(void *));
	hashtable->values = (void **) malloc(hashtable->size * sizeof(void *));
	for (size_t i = 0; i < hashtable->size; i++) {
		hashtable->keys[i] = NULL;
		hashtable->values[i] = NULL;
	}

	return (hashtable);
}

size_t hashtable_hash(char *value) {
	size_t count = strlen(value);

	return (hashtable_hash_ex(value, count));
}

size_t hashtable_hash_ex(char* value, size_t count) {
	size_t hash = 1;
	for (size_t i = 0; i < count; i++) {
		char c = value[i];
		if (c == 0) {
			// Specially researched number to maximize distribution
			hash *= 69;
			continue;
		}
		hash *= (size_t) c;
	}

	return (hash);
}
