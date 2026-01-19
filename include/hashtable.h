#ifndef HASHTABLE_H
# define HASHTABLE_H

# include <stddef.h>
# include <stdio.h>
# include <stdbool.h>

	typedef struct {
		size_t load;
		size_t size;
		double max_load_factor;

		char** keys;
		void** values;
	} HashTable;

	// ------------------
	// |     CREATE     |
	// ------------------
	HashTable* hashtable_create();
	HashTable* hashtable_create_ex(size_t starting_size, double max_load_factor);

	// ------------------
	// |     RESIZE     |
	// ------------------
	void hashtable_resize(HashTable* hashtable, size_t new_size);

	// ------------------
	// |      ERASE     |
	// ------------------
	void hashtable_erase(HashTable* hashtable, bool free_keys, bool free_values);

	// ----------------
	// |     FREE     |
	// ----------------
	void hashtable_free(HashTable* hashtable);
	void hashtable_free_ex(HashTable* hashtable, bool free_keys, bool free_values);

	// ------------------
	// |     INSERT     |
	// ------------------
	int hashtable_insert(HashTable* hashtable, char* key, void* value);

	int hashtable_insert_int(HashTable* hashtable, char* key, int value);
	int hashtable_insert_uint(HashTable* hashtable, char* key, unsigned int value);
	int hashtable_insert_long(HashTable* hashtable, char* key, long int value);
	int hashtable_insert_ulong(HashTable* hashtable, char* key, long unsigned int value);

	int hashtable_insert_float(HashTable* hashtable, char* key, float value);
	int hashtable_insert_double(HashTable* hashtable, char* key, double value);

	int hashtable_insert_char(HashTable* hashtable, char* key, char value);
	int hashtable_insert_str(HashTable* hashtable, char* key, char* value);

	// ------------------
	// |       GET      |
	// ------------------
	void* hashtable_get(HashTable* hashtable, char* key);

	int hashtable_get_int(HashTable* hashtable, char* key);
	unsigned int hashtable_get_uint(HashTable* hashtable, char* key);
	long int hashtable_get_long(HashTable* hashtable, char* key);
	unsigned long int hashtable_get_ulong(HashTable* hashtable, char* key);

	float hashtable_get_float(HashTable* hashtable, char* key);
	double hashtable_get_double(HashTable* hashtable, char* key);

	char hashtable_get_char(HashTable* hashtable, char* key);
	char* hashtable_get_str(HashTable* hashtable, char* key);

	// ------------------
	// |      HASH      |
	// ------------------
	size_t hashtable_hash(char* value);
	size_t hashtable_hash_ex(char* value, size_t count);

	// ------------------
	// |      MISC      |
	// ------------------
	void hashtable_print_ints(HashTable* hashtable);
#endif
