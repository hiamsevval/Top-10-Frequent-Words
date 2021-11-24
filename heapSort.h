#pragma once
#pragma once
#include<string>
using namespace std;

struct heapElem
{
	string name_w;
	int number_w;
};


classsorting_heap
{
public:
	void heapSortingAll(nodeType* head, int m);
private:
	void swap(heapElem &a, heapElem &b);
	void heapify(heapElem arr[], int n, int i);
	void sortHeap(heapElem arr[], int n);
	nodeType *head;
	heapElem arr[10];
};
