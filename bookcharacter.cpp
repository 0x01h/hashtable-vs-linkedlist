#include "bookcharacter.h"
#include <sstream>

using namespace std;

void BookCharacter::unique_key(){	// With the help of these if conditions every key will be unique in this format [XXX-XX-XX].
	stringstream concat;
	if (line <= 9){
		concat << page << 0 << line << index;
	}
	else if (index <= 9){
		concat << page << line << 0 << index;
	}
	else if (line <= 9 && index <= 9){
		concat << page << 0 << line << 0 << index;
	}
	else {
		concat << page << line << index;
	}
	concat >> key;
}
