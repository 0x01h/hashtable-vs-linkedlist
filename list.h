#ifndef LIST_H
#define LIST_H
#include "bookcharacter.h"

class List{
	public:
		void insertion(BookCharacter*);
		void lookup(BookCharacter*);
	private:
		void create();
		void push(int, int, int, char, int);
		BookCharacter *root;
};

#endif
