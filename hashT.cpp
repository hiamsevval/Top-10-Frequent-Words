#include "hashT.h"
#include <iostream>

long long hashT::compute_hash(std::string const& str) //computes the mod value
{
	int p = 31;
	long long power_of_p = 1;
	long long hash_val = 0;
	for (int i = 0; i < str.length(); i++) {
		hash_val
			= (hash_val
				+ (str[i] - 'a' + 1) * power_of_p)
			% HTSize;
		power_of_p
			= (power_of_p * p) % HTSize;
	}
	return hash_val;
}

hashT::hashT() { //constuctor
	HTSize = 4000;
	for (int i = 0; i < HTSize; i++) {
		hTable[i] = NULL;
	}
}

hashT::~hashT() { //destructor
	nodeType *temp;
	nodeType *tempnext;
	for (int i = 0; i < HTSize; i++) {
		temp = hTable[i];
		while (temp != NULL) {
			tempnext = temp->link;
			delete temp;
			temp = tempnext;
		}
		hTable[i] = NULL;
	}
	HTSize = 0;
}


void hashT::insert(const std::string& word) {
	nodeType *newNode, *current, *trailCurrent;
	int index = compute_hash(word);
	if (hTable[index] != NULL) {
		current = hTable[index];
		trailCurrent = current;
		if (hTable[index]->info1 == word)
			hTable[index]->info2++;
		else {
			while (current != NULL && current->info1 != word) {
				current = current->link;
			}
			if (current == NULL) {
				newNode = new nodeType;
				newNode->info1 = word;
				newNode->info2 = 1;
				newNode->link = NULL;
				trailCurrent->link = newNode;

			}
			else {
				current->info2++;
			}
		}
	}
	else {
		newNode = new nodeType;
		newNode->info1 = word;
		newNode->info2 = 1;
		newNode->link = NULL;
		hTable[index] = newNode;

	}
}
