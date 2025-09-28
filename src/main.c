#include "hashtable.h"
#include <stdio.h>

int main() {
	HashTable* hashtable = hashtable_create();

	hashtable_insert_int(hashtable, "int", -23);
	int int_value = hashtable_get_int(hashtable, "int");
	printf("Got the value %d from the hashtable!\n", int_value);

	hashtable_insert_uint(hashtable, "uint", 3000000069);
	unsigned int uint_value = hashtable_get_uint(hashtable, "uint");
	printf("Got the value %u from the hashtable!\n", uint_value);

	hashtable_insert_long(hashtable, "long", -69000000000);
	long int lint_value = hashtable_get_long(hashtable, "long");
	printf("Got the value %ld from the hashtable!\n", lint_value);

	hashtable_insert_ulong(hashtable, "ulong", 420000000000);
	long unsigned int luint_value = hashtable_get_ulong(hashtable, "ulong");
	printf("Got the value %lu from the hashtable!\n", luint_value);

	hashtable_insert_float(hashtable, "float", 420.69);
	float float_value = hashtable_get_float(hashtable, "float");
	printf("Got the value %f from the hashtable!\n", float_value);

	hashtable_insert_double(hashtable, "double", -420.6969);
	double double_value = hashtable_get_double(hashtable, "double");
	printf("Got the value %lf from the hashtable!\n", double_value);

	hashtable_insert_char(hashtable, "char", 'F');
	char char_value = hashtable_get_char(hashtable, "char");
	printf("Got the value %c from the hashtable!\n", char_value);

	hashtable_insert_str(hashtable, "string", "the n word");
	char* str_value = hashtable_get_str(hashtable, "string");
	printf("Got the value %s from the hashtable!\n", str_value);

	return (0);
}
