#include "stdafx.h"
#include "quickSort.h"
#include "insertSort.h"
#include "heap.h"
#include "mergeSort.h"
#include "countSort.h"
#include "infixToPostfix.h"
#include <iostream>


void insertSortTest()
{
	int arr[] = { 3, 5, 7, 4, 11, 5, 32, 27 };
	int length = sizeof(arr) / sizeof(arr[0]);
	insertSort(arr, length);
	for (int i = 0; i < length; i++)
	{
		std::cout << arr[i] << " ";
	}
}

void heapTest()
{
	std::vector<int> temp = { 14,42,33,85,2,41 };
	heap h(temp);
	std::cout << h.extractMaxium() << std::endl;
}

void quickSortTest() 
{
	std::vector<int> vec = { 5, 3, 7, 11 ,4 };
	quick q(vec);
	q.quickSort(0, vec.size());
	q.printResult();
}

void mergeSortTest()
{
	std::vector<int> vec = { 9,5,11,4,32 };
	mergecls c(vec);
	c.mergeSort(0, vec.size());
	c.printResult();
}

void countSortTest() 
{
	int array[] = {5, 9 ,11, 33, 21};
	int size = sizeof(array) / sizeof(array[0]);
	CountSort(array, size);
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
}

void inToPostTest() {
	char data[] = "3+(5*6-7/1*7)*9";
	int len = sizeof(data) / sizeof(data[0]);
	char final[sizeof(data) / sizeof(data[0])];
	inToPost(data, len, final);
	printf("%s\n", final);
}

int main()
{
	//heapTest();
	//quickSortTest();
	//mergeSortTest();
	//countSortTest();
	inToPostTest();
	return 0;
}