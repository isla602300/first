#include "stdafx.h"
#include "countSort.h"

void CountSort(int* array, int size)
{
	int max = array[0];//�����е����ֵ
	int min = array[0];//�����е���Сֵ
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
	int range = max - min + 1;//��Ҫ���ٵĿռ��С
	int* count = new int[range];
	for (int i = 0; i < range; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < size; ++i)
	{
		count[array[i] - min]++;//array[i]-min�ǽ�������Ӧ�������ռ���±�
	}
	int index = 0;
	for (int i = 0; i < range; ++i)//���������ռ�
	{
		while (count[i]--)//�±괦����ֵ�Ǽ���˵�����������˼���
		{
			array[index++] = i + min;//���±괦������Ӧ��ԭ����
		}
	}
	//delete[] count;
}