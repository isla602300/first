#include "stdafx.h"
#include <vector>
#include "heap.h"


heap::heap(std::vector<int> v) {
	vec = v;
	int n = v.size();
	for(int i = (n-2)/2;i > -1 && i < n;i--)
	{
		percolateDown(i);//Floyd�����㷨���Ե����������ڲ��ڵ�
	}
}

int heap::percolateUp(int i) 
{
	while (i > 0) 
	{
		int parent = (i - 1) / 2;
		if (vec[i] < vec[parent])
		{
			//���iС���丸����ֹͣ����
			break;
		}
		//���򽻻�i���丸
		std::swap(vec[i], vec[parent]);
		i = parent;
	}
	return i; //���ز����Ԫ�����յ���
}

void heap::insert(int x) 
{
	vec.push_back(x);
	int n = vec.size();
	percolateUp(n-1);
}

int heap::maxium() 
{
	return vec[0];
}

int heap::bigger(int i, int j) 
{
	return vec[i] < vec[j] ? j : i;
}

int heap::properparent(int i, int n) 
{
	return (2 * (i + 1)) < n ? bigger(bigger(i, 2 * i + 1), 2 * (i + 1)) : (2 * i + 1) < n ? bigger(i, 2 * i + 1) : i;
}

int heap::percolateDown(int i)
{
	int parent;
	while (i != (parent = properparent(i,vec.size())))
	{
		//���i���������������ģ��򽻻�i�������ӣ���ʵ�����֣�
		std::swap(vec[i], vec[parent]);
		i = parent;
	}
	//�������˵ִ��λ��
	return i;
}

int heap::extractMaxium()
{
	int max = vec[0];
	percolateDown(0);
	return max;
}