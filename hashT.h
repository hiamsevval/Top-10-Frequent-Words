#pragma once
#include <string>
struct nodeType {
	std::string info1; //word
	int info2; //number of word
	nodeType *link;
};
class hashT
{
public:
	void insert(const std::string& word);
	long long compute_hash(std::string const& s); //hash-function

	hashT();
	~hashT();


	nodeType *hTable[4000]; //array of nodeType heads
	int HTSize; //4000
	
};

//compute_hash functtion:

/*<Ayan Ghosal> (<11.09.2020>) 
< String hashing using Polynomial rolling hash function > (<?>)[<type>]
https://www.geeksforgeeks.org/string-hashing-using-polynomial-rolling-hash-function/ */

