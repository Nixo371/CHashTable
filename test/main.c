#include "../include/hashtable.h"
#include <stdio.h>

#include <criterion/criterion.h>
#include <stdlib.h>

Test(value_integrity, ints) {
	HashTable* table = hashtable_create_ex(101, 1); // Shouldn't automatically resize itself
	cr_assert(table != NULL, "Expected table to be created properly");

	// Insert 100 random numbers
	char *numbers[] = { "1847392041", "-923847562", "1456783920", "-1829374651", "745892031", "-456182937", "2091847563", "-1673849201", "892047315", "-1284930567", "1537829461", "-2047391856", "364819275", "-1891047362", "1928374056", "-738291465", "1647382910", "-1092847356", "582910473", "-1456738291", "2019384756", "-867492013", "1238475690", "-1928475036", "473829156", "-1547382910", "1829374056", "-638291047", "1947382056", "-1738294056", "291847356", "-1392847501", "1647829305", "-928374615", "1829475603", "-1456829037", "738291456", "-1928374605", "2038475619", "-547382910", "1384756920", "-1847392056", "928374156", "-1637482950", "1547829306", "-829374516", "1928476053", "-1473829156", "647382915", "-1928374650", "2047385169", "-738294156", "1456738290", "-1829475036", "847392016", "-1547839201", "1738294056", "-928475163", "1928374650", "-1384756029", "547382910", "-1928374056", "2091847536", "-647382915", "1384756902", "-1738294650", "928374605", "-1456738209", "1647382905", "-847392016", "1928475036", "-1547382906", "738294156", "-1928374605", "2019384756", "-547839201", "1456738920", "-1829374056", "928475136", "-1647382905", "1738294056", "-829374651", "1928374605", "-1384756920", "647382910", "-1928475036", "2038475619", "-738291456", "1456829037", "-1738294056", "847392105", "-1456738290", "1647839201", "-928374156", "1928475063", "-1547382910", "738294651", "-1928374650", "666666666", "0" };
	int numbers_count = sizeof(numbers) / sizeof(numbers[0]);

	for (int i = 0; i < numbers_count; i++) {
		hashtable_insert_int(table, numbers[i], atoi(numbers[i]));
	}

	// TODO Test that they're actually there

	hashtable_free(table);
}

Test(table_integrity, resize) {
	HashTable* table = hashtable_create_ex(8, 0.5);
	cr_assert(table != NULL, "Expected table to be created properly");


	hashtable_resize(table, 16);
	cr_assert(table->size == 16, "Expected new table size to be 16");
	cr_assert(table->load == 0, "Expected new table size to be 0");

	// Insert 8 values (right before forcing a resize)
	char s[2];
	s[1] = '\0';
	for (int i = 0; i < 8; i++) {
		s[0] = 'a' + i;
		hashtable_insert_int(table, s, i);
	}

	hashtable_print_ints(table);

	cr_assert(table->load == 8, "Expected table to have 8 values loaded");

	hashtable_insert_int(table, "overflow", 69);

	hashtable_print_ints(table);

	cr_assert(table->load == 9, "Expected table to insert properly");
	cr_assert(table->size == 32, "Expected table to have been resized properly");

	// Check that values are still there
}
