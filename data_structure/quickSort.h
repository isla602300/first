#pragma once
#include <vector>

using namespace std;

class quick {
private:
	vector<int> _vec;
public:
	quick(vector<int> vec);
	void quickSort(int lo, int hi);
	int partitionA(int lo, int hi);
	int partitionB(int lo, int hi);
	void printResult();
};


