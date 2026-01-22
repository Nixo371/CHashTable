#include "../include/hashtable.h"

#include <criterion/criterion.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TEST_VALUES 100
#define RAND_SEED 420

Test(value_integrity, ints) {
	srand(RAND_SEED);
	HashTable* table = hashtable_create();
	cr_assert(table != NULL, "Table creation failed");

	// Insert 100 random numbers
	int numbers[TEST_VALUES];
	for (int i = 0; i < TEST_VALUES; i++) {
		numbers[i] = rand();
		int negative = rand() % 2 ? -1 : 1; // If even, number is negative
		numbers[i] *= negative;
	}

	char key[12]; // Worst case -1 000 000 000
	for (int i = 0; i < TEST_VALUES; i++) {
		sprintf(key, "%d", numbers[i]);
		hashtable_insert_int(table, key, numbers[i]);
	}

	for (int i = 0; i < TEST_VALUES; i++) {
		sprintf(key, "%d", numbers[i]);
		int value = hashtable_get_int(table, key);
		cr_assert(value == numbers[i], "Ints don't match! (%d, %d)", value, numbers[i]);
	}

	hashtable_free(table);
}

Test(value_integrity, uints) {
	srand(RAND_SEED);
	HashTable* table = hashtable_create();
	cr_assert(table != NULL, "Table creation failed");

	// Insert 100 random numbers
	unsigned int numbers[TEST_VALUES];
	for (int i = 0; i < TEST_VALUES; i++) {
		numbers[i] = rand();
	}

	char key[12]; // Worst case -1 000 000 000
	for (int i = 0; i < TEST_VALUES; i++) {
		sprintf(key, "%u", numbers[i]);
		hashtable_insert_uint(table, key, numbers[i]);
	}

	for (int i = 0; i < TEST_VALUES; i++) {
		sprintf(key, "%u", numbers[i]);
		unsigned int value = hashtable_get_uint(table, key);
		cr_assert(value == numbers[i], "Uints don't match! (%u, %u)", value, numbers[i]);
	}

	hashtable_free(table);
}

Test(value_integrity, longs) {
	srand(RAND_SEED);
	HashTable* table = hashtable_create();
	cr_assert(table != NULL, "Table creation failed");

	// Insert 100 random numbers
	long numbers[TEST_VALUES];
	for (int i = 0; i < TEST_VALUES; i++) {
		numbers[i] = rand();
		int negative = rand() % 2 ? -1 : 1; // If even, number is negative
		numbers[i] *= negative;
	}

	char key[12]; // Worst case -1 000 000 000
	for (int i = 0; i < TEST_VALUES; i++) {
		sprintf(key, "%ld", numbers[i]);
		hashtable_insert_long(table, key, numbers[i]);
	}

	for (int i = 0; i < TEST_VALUES; i++) {
		sprintf(key, "%ld", numbers[i]);
		long value = hashtable_get_long(table, key);
		cr_assert(value == numbers[i], "Longs don't match! (%ld, %ld)", value, numbers[i]);
	}

	hashtable_free(table);
}

Test(value_integrity, ulongs) {
	srand(RAND_SEED);
	HashTable* table = hashtable_create();
	cr_assert(table != NULL, "Table creation failed");

	// Insert 100 random numbers
	unsigned long numbers[TEST_VALUES];
	for (int i = 0; i < TEST_VALUES; i++) {
		numbers[i] = rand();
	}

	char key[12]; // Worst case -1 000 000 000
	for (int i = 0; i < TEST_VALUES; i++) {
		sprintf(key, "%lu", numbers[i]);
		hashtable_insert_ulong(table, key, numbers[i]);
	}

	for (int i = 0; i < TEST_VALUES; i++) {
		sprintf(key, "%lu", numbers[i]);
		unsigned long value = hashtable_get_ulong(table, key);
		cr_assert(value == numbers[i], "Ulongs don't match! (%lu, %lu)", value, numbers[i]);
	}

	hashtable_free(table);
}

Test(value_integrity, floats) {
	srand(RAND_SEED);
	HashTable* table = hashtable_create();
	cr_assert(table != NULL, "Table creation failed");

	// Insert 100 random numbers
	float numbers[TEST_VALUES];
	for (int i = 0; i < TEST_VALUES; i++) {
		numbers[i] = (float)rand(); // integer part
		numbers[i] = (float)rand() / (float)(RAND_MAX); // decimal part
		int negative = rand() % 2 ? -1 : 1; // If even, number is negative
		numbers[i] *= negative;
	}

	char key[100]; // I literally have no idea what worst case scenario is so...
	for (int i = 0; i < TEST_VALUES; i++) {
		sprintf(key, "%.5f", numbers[i]); // 5 decimal points of precision
		hashtable_insert_float(table, key, numbers[i]);
	}

	for (int i = 0; i < TEST_VALUES; i++) {
		sprintf(key, "%.5f", numbers[i]);
		float value = hashtable_get_float(table, key);
		cr_assert(value == numbers[i], "Floats don't match! (%.5f, %.5f)", value, numbers[i]);
	}

	hashtable_free(table);
}

Test(value_integrity, doubles) {
	srand(RAND_SEED);
	HashTable* table = hashtable_create();
	cr_assert(table != NULL, "Table creation failed");

	// Insert 100 random numbers
	double numbers[TEST_VALUES];
	for (int i = 0; i < TEST_VALUES; i++) {
		numbers[i] = (double)rand(); // integer part
		numbers[i] = (double)rand() / (double)(RAND_MAX); // decimal part
		int negative = rand() % 2 ? -1 : 1; // If even, number is negative
		numbers[i] *= negative;
	}

	char key[100]; // I literally have no idea what worst case scenario is so...
	for (int i = 0; i < TEST_VALUES; i++) {
		sprintf(key, "%.5lf", numbers[i]); // 5 decimal points of precision
		hashtable_insert_double(table, key, numbers[i]);
	}

	for (int i = 0; i < TEST_VALUES; i++) {
		sprintf(key, "%.5lf", numbers[i]);
		double value = hashtable_get_double(table, key);
		cr_assert(value == numbers[i], "Doubles don't match! (%.5lf, %.5lf)", value, numbers[i]);
	}

	hashtable_free(table);
}

Test(value_integrity, chars) {
	srand(RAND_SEED);
	HashTable* table = hashtable_create();
	cr_assert(table != NULL, "Table creation failed");

	// Insert 100 random chars
	char characters[TEST_VALUES];
	for (int i = 0; i < TEST_VALUES; i++) {
		characters[i] = (rand() % 95) + 32; // 32 (space) - 126 (~) // printable chars
	}

	char key[100]; // I literally have no idea what worst case scenario is so...
	for (int i = 0; i < TEST_VALUES; i++) {
		sprintf(key, "%d%c", i, characters[i]); // Use the index to avoid collisions
		hashtable_insert_char(table, key, characters[i]);
	}

	for (int i = 0; i < TEST_VALUES; i++) {
		sprintf(key, "%d%c", i, characters[i]);
		char value = hashtable_get_char(table, key);
		cr_assert(value == characters[i], "characters don't match! (%c, %c)", value, characters[i]);
	}

	hashtable_free(table);
}

Test(value_integrity, strings) {
	srand(RAND_SEED);
	HashTable* table = hashtable_create();
	cr_assert(table != NULL, "Table creation failed");

	// Insert 100 random strings
	char* strings[TEST_VALUES];
	for (int i = 0; i < TEST_VALUES; i++) {
		int len = rand() % 100;
		strings[i] = (char *) malloc((len + 1) * sizeof(char));
		for (int j = 0; j < len; j++) {
			strings[i][j] = (rand() % 95) + 32; // 32 (space) - 126 (~) // printable chars
		}
	}

	for (int i = 0; i < TEST_VALUES; i++) {
		hashtable_insert_str(table, strings[i], strings[i]);
	}

	for (int i = 0; i < TEST_VALUES; i++) {
		char* value = hashtable_get_str(table, strings[i]);
		cr_assert(strncmp(value, strings[i], strlen(value)) == 0, "strings don't match! (%s, %s)", value, strings[i]);
	}

	hashtable_free(table);
}

Test(table_integrity, resize) {
	HashTable* table = hashtable_create_ex(8, 0.5);
	cr_assert(table != NULL, "Table creation failed");


	hashtable_resize(table, 16);
	cr_assert(table->size == 16, "Expected new table size to be 16 (%lu)", table->size);
	cr_assert(table->load == 0, "Expected new table load to be 0 (%lu)", table->load);

	// Insert 8 values (right before forcing a resize)
	char s[2];
	s[1] = '\0';
	for (int i = 0; i < 8; i++) {
		s[0] = '0' + i;
		hashtable_insert_int(table, s, i);
	}

	cr_assert(table->load == 8, "Expected table to have 8 values (%lu)", table->load);

	hashtable_insert_int(table, "overflow", 69);

	cr_assert(table->load == 9, "Expected table to insert properly");
	cr_assert(table->size == 32, "Table was not properly resized to 32 (%lu)", table->size);

	// Check that values are still there
	for (int i = 0; i < 8; i++) {
		s[0] = '0' + i;
		int value = hashtable_get_int(table, s);
		cr_assert(value == atoi(s), "Numbers don't match! (%d, %d)", value, atoi(s));
	}
	int final = hashtable_get_int(table, "overflow");
	cr_assert(69 == final, "Final value inserted doesn't match (69, %d)", final);

	hashtable_free(table);
}
