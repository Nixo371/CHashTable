# CHashTable

It should be pretty intuitive

## Functions
`hashtable_create` creates a HashTable object pointer
`hashtable_insert_*` allows you to insert certain data types into the table with a string as a key
`hashtable_get_*` allows you to fetch certain data types from the table with a string as a key
You can always use the base `hashtable_insert` and `hashtable_get` functions to store and retrieve anything, as long as you know what you're doing, since they work with `void *`

## Notes
Getting a value of a different type than was inserted is undefined behavior until I make my own data type to handle that more gracefully
Currently you can insert all the data types available in the function declarations, but the get functions aren't implemented (except the int one)

## Soon™️
Currently there is no logic to expand the table when it gets too full. 
