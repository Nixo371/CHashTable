#include "hashtable.h"
#include <stdio.h>

int main() {
	HashTable* hashtable = hashtable_create();

	hashtable_insert_int(hashtable, "twenty", 20);
	
	int value = hashtable_get_int(hashtable, "twenty");

	printf("Got the value %d from the hashtable!", value);

	return (0);
}
