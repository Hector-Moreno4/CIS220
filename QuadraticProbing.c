#include <stdio.h>
#include <stdbool.h>
#define EMPTY_START -1
#define EMPTY_REMOVED -2
#define C1 1
#define C2 1
//Hector Moreno
//Chapter 6 PA

int hashTableSize = 16;
int hashTable[16];

int hash(int key) { // returns the bucket number to insert the item in the hash table based on a Modulo hash function.
	return key % 16;
}

bool hashInsert(int item) { //inserts an item into the hash table if possible, returns true if successful and false if unsuccessful
	int i = 0;
	int bucketsProbed = 0;
	
	int bucket = hash(item) % 16; //Call has function for initial bucket 
	
	while (bucketsProbed < 16) {
		if (hashTable[bucket] == EMPTY_START || hashTable[bucket] == EMPTY_REMOVED) { //insert item in next empty bucket
		hashTable[bucket] = item;
		return true;
	}
	
	i = i + 1; //Increment i and use quadratic probing to find next empty bucket
	bucket = (hash(item) + C1 * i + C2 * i * i) % 16;
	bucketsProbed = bucketsProbed + 1;
	}
	return false;
}

bool hashRemove(int item) { //removes an item from the hash table and returns true if the item was removed and false if the item was not found
	int i = 0;
	int bucketsProbed = 0;
	
	int bucket = hash(item) % 16; //Call has function for initial bucket 
	
	while ((hashTable[bucket] != EMPTY_START) && (bucketsProbed < 16)) { //Remove item
		if (hashTable[bucket] != EMPTY_START && hashTable[bucket] != EMPTY_REMOVED && (hashTable[bucket] == item)){
			hashTable[bucket] = EMPTY_REMOVED;
		return true;
	}
	
	i = i + 1; //Increment i and use quadratic probing to find next empty bucket
	bucket = (hash(item) + C1 * i + C2 * i * i) % 16;
	bucketsProbed = bucketsProbed + 1;
	}
	return false;
}
		
int hashSearch(int item) { //searches for an item in the hash table and returns the bucket number in the hash table if found and -9 if not found.
	int i = 0;
	int bucketsProbed = 0;
	
	int bucket = hash(item) % 16; //Call has function for initial bucket 
	
	while ((hashTable[bucket] != EMPTY_START) && (bucketsProbed < 16)) { //Find item
		if (hashTable[bucket] != EMPTY_START && hashTable[bucket] != EMPTY_REMOVED && hashTable[bucket] == item){
		return bucket;
	}
	
	i = i + 1; //Increment i and use quadratic probing to find next empty bucket
	bucket = (hash(item) + C1 * i + C2 * i * i) % 16;
	bucketsProbed = bucketsProbed + 1;
	}
	return -9;
}

void displayHashTable() {
	printf("The hash table contents are:\n");
	for (int i = 0; i < 16; i++) {
		printf("HashTable[%d] %d\n", i, hashTable[i]);
	}
}

int main() {
int i;

for (i = 0; i < 16; i++) {
hashTable[i] = -1;
}

 printf("Item 32 was inserted %s\n", hashInsert(32) ? "successfully" : "unsuccessfully");//insert 32 and display if successful
 
 printf("Item 63 was inserted %s\n", hashInsert(63) ? "successfully" : "unsuccessfully");//insert 63 and display if successful
 
 printf("Item 16 was inserted %s\n", hashInsert(16) ? "successfully" : "unsuccessfully");//insert 16 and display if successful
 
 printf("Item 3 was inserted %s\n", hashInsert(3) ? "successfully" : "unsuccessfully");//insert 3 and display if successful
 
 printf("Item 23 was inserted %s\n", hashInsert(23) ? "successfully" : "unsuccessfully");//insert 23 and display if successful
 
 printf("Item 11 was inserted %s\n", hashInsert(11) ? "successfully" : "unsuccessfully");//insert 11 and display if successful
 
 printf("Item 64 was inserted %s\n", hashInsert(64) ? "successfully" : "unsuccessfully");//insert 64 and display if successful
 
 printf("Item 99 was inserted %s\n", hashInsert(99) ? "successfully" : "unsuccessfully");//insert 99 and display if successful
 
 printf("Item 42 was inserted %s\n", hashInsert(42) ? "successfully" : "unsuccessfully");//insert 42 and display if successful
 
 printf("Item 49 was inserted %s\n", hashInsert(49) ? "successfully" : "unsuccessfully");//insert 49 and display if successful
 
 printf("Item 48 was inserted %s\n", hashInsert(48) ? "successfully" : "unsuccessfully");//insert 48 and display if successful
 
 printf("Item 21 was inserted %s\n\n", hashInsert(21) ? "successfully" : "unsuccessfully");//insert 21 and display if successful
 
 displayHashTable();
 
 printf("Item 32 was removed %s\n", hashRemove(32) ? "successfully" : "unsuccessfully");//remove 32 and display if successful
 
 printf("Item 11 was removed %s\n", hashRemove(11) ? "successfully" : "unsuccessfully");//remove 11 and display if successful
 
 int result = hashSearch(64);//Find search item and print if found or not
    
    if (result != -9) {
        printf("Item 64 was found at bucket %d.\n", result);
    } else {
        printf("Item 64 not found.\n");
    }
    
 printf("Item 9 was inserted %s\n", hashInsert(9) ? "successfully" : "unsuccessfully");//insert 9 and display if successful
 
 result = hashSearch(48);//Find search item and print if found or not
    
    if (result != -9) {
        printf("Item 48 was found at bucket %d.\n", result);
    } else {
        printf("Item 48 not found.\n");
    }
    
 result = hashSearch(32);//Find search item and print if found or not
    
    if (result != -9) {
        printf("Item 32 was found at bucket %d\n", result);
    } else {
        printf("Item 32 not found.\n");
    }
    
 printf("Item 64 was removed %s\n", hashRemove(64) ? "successfully" : "unsuccessfully");//remove 64 and display if successful
 
 printf("Item 99 was removed %s\n\n", hashRemove(99) ? "successfully" : "unsuccessfully");//remove 99 and display if successful
 
 displayHashTable();
}
		
