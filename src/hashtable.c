#include "hashtable.h"

#include <stddef.h>
#include <stdio.h>
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

	hashtable->keys = (char **) malloc(hashtable->size * sizeof(char *));
	hashtable->values = (void **) malloc(hashtable->size * sizeof(void *));
	for (size_t i = 0; i < hashtable->size; i++) {
		hashtable->keys[i] = NULL;
		hashtable->values[i] = NULL;
	}

	return (hashtable);
}

void hashtable_resize(HashTable* hashtable, size_t new_size) {
	HashTable* new_hashtable = hashtable_create_ex(new_size, hashtable->max_load_factor);

	for (size_t i = 0; i < hashtable->size; i++) {
		if (hashtable->keys[i] == NULL) {
			continue;
		}
		hashtable_insert(new_hashtable, hashtable->keys[i], hashtable->values[i]);
	}

	char** tmp_keys = hashtable->keys;
	void** tmp_values = hashtable->values;

	new_hashtable->size = hashtable->size;
	hashtable->size = new_size;
	hashtable->keys = new_hashtable->keys;
	hashtable->values = new_hashtable->values;

	new_hashtable->keys = tmp_keys;
	new_hashtable->values = tmp_values;
	hashtable_free_ex(new_hashtable, true, false);
}

void hashtable_free(HashTable* hashtable) {
	hashtable_free_ex(hashtable, true, true);
}

void hashtable_free_ex(HashTable* hashtable, bool free_keys, bool free_values) {
	if (free_keys == true || free_values == true) {
		hashtable_erase(hashtable, free_keys, free_values);
	}
	free(hashtable->values);
	free(hashtable->keys);

	free(hashtable);
}

void hashtable_erase(HashTable* hashtable, bool free_keys, bool free_values) {
	for (size_t i = 0; i < hashtable->size; i++) {
		if (hashtable->keys[i] == NULL) {
			continue;
		}

		if (free_keys) {
			free(hashtable->keys[i]);
		}
		if (free_values) {
			free(hashtable->values[i]);
		}
	}
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

void hashtable_print_ints(HashTable* hashtable) {
	printf("KEY\tVALUE\n");
	for (size_t i = 0; i < hashtable->size; i++) {
		if (hashtable->keys[i] == NULL) {
			continue;
		}
		int value = hashtable_get_int(hashtable, hashtable->keys[i]);
		printf("%s\t%d\n", hashtable->keys[i], value);
	}
}
