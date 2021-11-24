#include "sorting_heap.h"
#include<iostream>
#include <fstream>
#include<string>

void sorting_heap::swap(heapElem &a, heapElem &b) //swaps strings and numbers of a and b 
{
	std::string tempW = a.name_w;
	int tempN = a.number_w;

	a.name_w = b.name_w;
	b.name_w = tempW;

	a.number_w = b.number_w;
	b.number_w = tempN;
}

void sorting_heap::heapify(heapElem sortArr[], int n, int i)
{
	int big = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && sortArr[left].number_w < sortArr[big].number_w)
	{
		big = left;
	}
	if (right < n && sortArr[right].number_w < sortArr[big].number_w) 
	{
		big = right;
	}
	if (big != i)
	{
		swap(sortArr[i], sortArr[big]);
		heapify(sortArr, n, big);
	}
}

void sorting_heap::sortHeap(heapElem sortArr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(sortArr, n, i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		swap(sortArr[0], sortArr[i]);
		heapify(sortArr, i, 0);
	}
}

void sorting_heap::heapSortingAll(hashT heapArr, std::string stops)
{
	int k = 0; //total unique word number
	nodeType *current;
	for (int i = 0; i < heapArr.HTSize; i++) //travelling in the hash
	{
		current = heapArr.hTable[i];
		while (current != NULL)
		{
			arr[k].name_w = current->info1; //assigns word
			arr[k].number_w = current->info2; //assigns number of the word
			current = current->link;
			k++;
		}
	}
	sortHeap(arr, k);

	
	int counter = 0; //top10 counter
	int i = 0;
	while (counter < 10)
	{
		if (stops.find(arr[i].name_w) != std::string::npos) //checks stopword
		{
			i++;
			continue;
		}
		else //prints if it is not in stopwords
		{
			std::cout << "<" << arr[i].name_w << ">        <" << arr[i].number_w << ">" << std::endl;
			i++;
			counter++;
		}
	}
}
