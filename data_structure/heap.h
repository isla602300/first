#pragma once
#include <vector>

class heap {
public:
	heap(std::vector<int> v);
	std::vector<int> vec;
	int percolateUp(int i);
	void insert(int x);		//复杂度为O(logN)
	int maxium();	//复杂度为O(1)
	int extractMaxium();	//复杂度为O(logN)
	int percolateDown(int i);
	int properparent(int i, int j);
	int bigger(int i, int j);
};