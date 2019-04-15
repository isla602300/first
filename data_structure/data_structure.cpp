// data_structure.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

//时间复杂度为O(n^2)，辣鸡
//因为是就地排序，空间复杂度很自然是O(1)，然而无卵用

using namespace std;

void insertSort(int a[], int n) 
{
	for (int i = 1; i < n; i++) 
	{
		int key = a[i];
		for (int j = i - 1; j >= 0; j--) 
		{
			if (a[j] < key) 
			{
				a[j + 1] = key;
				break;
			}
			a[j + 1] = a[j];
		}
	}
}


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

