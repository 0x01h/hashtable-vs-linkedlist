#ifndef BOOKCHARACTER_H
#define BOOKCHARACTER_H

class BookCharacter{
	public:
		int page;
		int line;
		int index;
		int key;
		char character;
		void unique_key();
		BookCharacter *next;
};

#endif
