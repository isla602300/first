#include "insertSort.h"
#include <iostream>

using namespace std;

int main()
{
	int arr[] = { 3, 5, 7, 4, 11, 5, 32, 27 };
	int length = sizeof(arr) / sizeof(arr[0]);
	insertSort(arr, length);
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}