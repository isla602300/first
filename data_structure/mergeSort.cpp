//冯·诺依曼nb!
#include "stdafx.h"
#include "mergeSort.h"
#include <iostream>

mergecls::mergecls(std::vector<int> vec) 
{
	_vec = vec;
}

void mergecls::mergeSort(int lo, int hi) 
{
	if (hi - lo < 2) return; //左闭右开，hi-lo=1时单元素区间自然有序
	int mi = (lo + hi) / 2;
	mergeSort(lo, mi);
	mergeSort(mi, hi);
	merge(lo, mi, hi);
}

void mergecls::merge(int lo, int mi, int hi)
{
	int length_a = mi - lo;
	int length_b = hi - mi;
	int *temp = new int[length_a];
	for (int i = 0; i < length_a; i++) {
		temp[i] = _vec[lo+i];
	}
	for (int i = 0, j = 0, k = 0; (j < length_a) || (k < length_b);)
	{
		if ((j < length_a) && (!(k < length_b) || (temp[j] <= _vec[mi + k])))
			_vec[lo+(i++)] = temp[j++];		//注意这里合并时使用的是相对索引
		if ((k < length_b) && (!(j < length_a) || (_vec[mi + k] < temp[j])))
		{
			_vec[lo+(i++)] = _vec[mi + k]; k++;
		}
	}
	delete[] temp;
}

void mergecls::printResult() {
	for (auto x : _vec)
	{
		std::cout << x << " " << std::endl;
	}
}
