#pragma once
#include "hashT.h"
#include<string>
#include<ostream>
struct heapElem
{
	std::string name_w = "";
	int number_w = 0;
};

class sorting_heap :
	public hashT
{
public:
	void heapSortingAll(hashT arr, std::string stops);
	
private:
	void swap(heapElem &a, heapElem &b);
	void heapify(heapElem sortArr[], int n, int i);
	void sortHeap(heapElem sortArr[], int n); //sorting function
	
	heapElem arr[20000];
};

