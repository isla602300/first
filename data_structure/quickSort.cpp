#include "stdafx.h"
#include "quickSort.h"
#include <iostream>

quick::quick(std::vector<int> vec) 
{
	_vec = vec;
}

void quick::quickSort(int lo, int hi)
{
	if (hi - lo < 2) return;
	int mi = partitionB(lo, hi - 1);
	quickSort(lo, mi);
	quickSort(mi + 1, hi);
}

int quick::partitionA(int lo, int hi)
{
	swap(_vec[lo], _vec[lo + rand() % (hi - lo + 1)]);
	int pivot = _vec[lo];
	while (lo < hi) {
		while ((lo < hi) && (pivot <= _vec[hi]))
			hi--;
		_vec[lo] = _vec[hi];
		while ((lo < hi) && (_vec[lo] <= pivot))
			lo++;
		_vec[hi] = _vec[lo];
	}
	_vec[lo] = pivot;	//��ʱlo == hi
	return lo;	//����������
}


//B������ֹ�������ڿ������˵ĵط�
int quick::partitionB(int lo, int hi)
{
	swap(_vec[lo], _vec[lo + rand() % (hi - lo + 1)]);
	int pivot = _vec[lo];
	while (lo < hi) {
		while (lo < hi) {
			if (pivot < _vec[hi])
				hi--;
			else
			{
				_vec[lo++] = _vec[hi];
				break;
			}
		}
		while (lo < hi) {
			if (_vec[lo] < pivot)
				lo++;
			else
			{
				_vec[hi--] = _vec[lo];
				break;
			}
		}
	}
	_vec[lo] = pivot;	//��ʱlo == hi
	return lo;	//����������
}

void quick::printResult() 
{
	for (auto x:_vec)
	{
		std::cout << x << " " << std::endl;
	}
}