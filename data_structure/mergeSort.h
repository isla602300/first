#pragma once
#include <vector>

class mergecls {
private:
	std::vector<int> _vec;
public:
	mergecls(std::vector<int> _vec);
	void mergeSort(int lo, int hi);
	void merge(int lo, int mi, int hi);
	void printResult();
};