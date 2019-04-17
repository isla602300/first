#include "stdafx.h"
#include <vector>
#include "heap.h"


heap::heap(std::vector<int> v) {
	vec = v;
	int n = v.size();
	for(int i = (n-2)/2;i > -1 && i < n;i--)
	{
		percolateDown(i);//Floyd建堆算法，自底向上下滤内部节点
	}
}

int heap::percolateUp(int i) 
{
	while (i > 0) 
	{
		int parent = (i - 1) / 2;
		if (vec[i] < vec[parent])
		{
			//如果i小于其父，则停止上滤
			break;
		}
		//否则交换i和其父
		std::swap(vec[i], vec[parent]);
		i = parent;
	}
	return i; //返回插入的元素最终的秩
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
		//如果i不是三父子中最大的，则交换i与他儿子（其实是他爸）
		std::swap(vec[i], vec[parent]);
		i = parent;
	}
	//返回下滤抵达的位置
	return i;
}

int heap::extractMaxium()
{
	int max = vec[0];
	percolateDown(0);
	return max;
}