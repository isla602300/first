// data_structure.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

//ʱ�临�Ӷ�ΪO(n^2)������
//��Ϊ�Ǿ͵����򣬿ռ临�ӶȺ���Ȼ��O(1)��Ȼ��������

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

