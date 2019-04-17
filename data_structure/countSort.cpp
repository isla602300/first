#include "stdafx.h"
#include "countSort.h"

void CountSort(int* array, int size)
{
	int max = array[0];//序列中的最大值
	int min = array[0];//序列中的最小值
	for (int i = 0; i < size; ++i)
	{
		if (array[i] >= max)
		{
			max = array[i];
		}
		else if (array[i] <= min)
		{
			min = array[i];
		}
	}
	int range = max - min + 1;//需要开辟的空间大小
	int* count = new int[range];
	for (int i = 0; i < range; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < size; ++i)
	{
		count[array[i] - min]++;//array[i]-min是将该数对应到辅助空间的下标
	}
	int index = 0;
	for (int i = 0; i < range; ++i)//遍历辅助空间
	{
		while (count[i]--)//下标处的数值是几，说明该数出现了几次
		{
			array[index++] = i + min;//将下标处的数对应回原数组
		}
	}
	//delete[] count;
}