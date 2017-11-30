#include "list.h"
#include <iostream>
#include <fstream>

using namespace std;

void List::create(){
	root = NULL;
}

void List::push(int p, int l, int i, char c, int k){
	BookCharacter *temp = new BookCharacter;
	temp->page = p;
	temp->line = l;
	temp->index = i;
	temp->character = c;
	temp->key = k;
	temp->next = NULL;
	
	if (root == NULL){
		root = temp;
	}
	
	else {
		BookCharacter *traverse = root;
			while (traverse->next != NULL){
			traverse = traverse->next;
			}
		traverse->next = temp;
	}
}

void List::insertion(BookCharacter* b){
	create();
	ifstream input;
	input.open("ds-set-input.txt");
	
	if (input.fail()){
		cout << "File could not be opened!";
	}
	
	while(!input.eof()){
		input >> b->page;
		input >> b->line;
		input >> b->index;
		input.ignore(256, '\t');
		
		if (input.peek() == ' '){
			b->character = ' ';
		}
		else {
			input >> b->character;
		}
		
		input.ignore(256, '\n');
		b->unique_key();
		push(b->page, b->line, b->index, b->character, b->key);
	}
	
	input.close();
}

void List::lookup(BookCharacter* b){
	ifstream input;
	ofstream output;
	
	input.open("ds-set-lookup.txt");
	output.open("ds-set-output-list.txt");
	
	if (input.fail()){
		cout << "File could not be opened!";
	}
	
	if (output.fail()){
		cout << "File could not be written!";
	}
	
	BookCharacter *traverse;
	
	while(!input.eof()){
		input >> b->page;
		input >> b->line;
		input >> b->index;
		input.ignore(256, '\n');
		b->unique_key();
		
		traverse = root;
		while (traverse->key != b->key){
			traverse = traverse->next;
		}
		output << traverse->character;
	}
	
	input.close();
	output.close();
}

