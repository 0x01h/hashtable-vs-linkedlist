/*
  _____ _______ _    _ 
 |_   _|__   __| |  | |
   | |    | |  | |  | |
   | |    | |  | |  | |
  _| |_   | |  | |__| |
 |_____|  |_|   \____/ 
                       
@Author
Student Name: Orçun Özdemir
Student ID: 150140121
Date: 29/11/2017
Example Usage: g++ main.cpp bookcharacter.cpp dictionary.cpp list.cpp -o program

*/

#include "hashtable.h"
#include "list.h"
#include "bookcharacter.h"
#include "dictionary.h"
#include <iostream>
#include <ctime>

using namespace std;

BookCharacter b;
Dictionary d;
List l;

int main(){
	clock_t begin = clock();				
	d.insertion(&b);
	clock_t end = clock();
	double dict_insertion = double(end - begin) / CLOCKS_PER_SEC;
	
	begin = clock();				
	d.lookup(&b);
	end = clock();
	double dict_lookup = double(end - begin) / CLOCKS_PER_SEC;
	
	begin = clock();				
	l.insertion(&b);
	end = clock();
	double list_insertion = double(end - begin) / CLOCKS_PER_SEC;
	
	begin = clock();				
	l.lookup(&b);
	end = clock();
	double list_lookup = double(end - begin) / CLOCKS_PER_SEC;
	
	cout << "\n\n\tDICTIONARY\n\t" << "Insertion finished after " <<  dict_insertion << " seconds.\n\n\t";
	cout << "Average number of collisions (first 1,000 items)   | " << float(d.c1)/1000 << "\n\t";
	cout << "Average number of collisions (first 10,000 items)  | " << float(d.c2)/10000 << "\n\t";
	cout << "Average number of collisions (first 100,000 items) | " << float(d.c3)/100000 << "\n\t";
	cout << "Average number of collisions (overall)             | " << float(d.total_collision)/d.counter << "\n\n\t";
	
	cout << "Lookup finished after " << dict_lookup << " seconds.\n\n\t";
	
	cout << "LIST\n\t";
	cout << "Insertion finished after " << list_insertion << " seconds.\n\t";
	cout << "Lookup finished after " << list_lookup << " seconds.\n\n";
}
