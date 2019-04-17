#pragma once
#include <vector>

class heap {
public:
	heap(std::vector<int> v);
	std::vector<int> vec;
	int percolateUp(int i);
	void insert(int x);		//���Ӷ�ΪO(logN)
	int maxium();	//���Ӷ�ΪO(1)
	int extractMaxium();	//���Ӷ�ΪO(logN)
	int percolateDown(int i);
	int properparent(int i, int j);
	int bigger(int i, int j);
};