#include "dictionary.h"
#include <iostream>
#include <cmath>
#include <fstream>
#define A 0.618

using namespace std;

unsigned long Dictionary::hash(int key){
	return (M * fmod(key * A, 1));
}

unsigned long Dictionary::probed_hash(unsigned long key, int i){
	return fmod(key + 7 * i + 3 * i * i, M);
}

void Dictionary::insertion(BookCharacter* b){
	ifstream input;
	input.open("ds-set-input.txt");
	
	if (input.fail()){
		cout << "File could not be opened!";
	}
	
	counter = 0;
	collision = 1;
	total_collision = 0;
	
	unsigned long current_hash;

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
		current_hash = hash(b->key);
		
			while (h_t[current_hash].c != '\0'){
			current_hash = probed_hash(current_hash, collision++);
			total_collision++;
			}
		
			h_t[current_hash].p = b->page;
			h_t[current_hash].l = b->line;
			h_t[current_hash].i = b->index;
			h_t[current_hash].k = b->key;
			h_t[current_hash].c = b->character;
			
			collision = 1;
			counter++;
			
			if (counter == 1000){
				c1 = total_collision;
			}
			if (counter == 10000){
				c2 = total_collision;
			}
			if (counter == 100000){
				c3 = total_collision;
			}
			
	}
	
	input.close();
}

void Dictionary::lookup(BookCharacter* b){
	ifstream input;
	ofstream output;
	
	input.open("ds-set-lookup.txt");
	output.open("ds-set-output-dict.txt");
	
	if (input.fail()){
		cout << "File could not be opened!";
	}
	
	if (output.fail()){
		cout << "File could not be written!";
	}
	
	collision = 1;
	unsigned long current_hash;
	
	while(!input.eof()){
		input >> b->page;
		input >> b->line;
		input >> b->index;
		input.ignore(256, '\n');
		
		b->unique_key();
		current_hash = hash(b->key);
		
			while (h_t[current_hash].k != b->key){
			current_hash = probed_hash(current_hash, collision++);
			}
			
		output << h_t[current_hash].c;
		collision = 1;
	}
	
	input.close();
	output.close();
}
