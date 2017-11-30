#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "hashtable.h"
#include "bookcharacter.h"
#define M 131071

class Dictionary{
	public:
		void insertion(BookCharacter*);
		void lookup(BookCharacter*);
		int counter;	// Total number of chars.
		int c1;	// Total collisions. (first 1,000 items)
		int c2;	// Total collisions. (first 10,000 items)
		int c3;	// Total collisions. (first 100,000 items)
		int total_collision;	// Total number of collisions.

	private:
		Hash_Table h_t[M];
		unsigned long hash(int);
		unsigned long probed_hash(unsigned long, int);
		int collision;	// Collision detector for probing hash function.
};

#endif
