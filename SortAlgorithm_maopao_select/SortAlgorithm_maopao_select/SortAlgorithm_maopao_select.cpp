// SortAlgorithm_maopao_select.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


void PrintArray(int *data, int length)
{
	for (int i=0; i<length; i++)
	{
		printf("%d \t", data[i]);
	}
	printf("\n");
}

void swap(int *data, int j, int k)
{
	int temp = data[j];
	data[j] = data[k];
	data[k] = temp;
}


int BubbleSort(int *data, int length)
{
	//Another method
	for(int i=0; i<length-1; i++)
	{
		for(int j=length-2; j>=i; j--)
		{
			if(data[j] < data[j+1])
			{
				swap(data, j, j+1);
			}
		}
		PrintArray(data, length);
	}
	/*
	for(int i=0; i<length-1; i++)
	{
		for(int j=0; j<length-1-i; j++)
		{
			if(data[j] < data[j+1])
			{
				swap(data, j, j+1);
			}
		}
		PrintArray(data, length);
	}
	*/
	/*
	for (int i=0; i<length; i++)
	{
		for (int j=0; j<length-1-i; j++)
		{
			if (data[j]> data[j+1])
			{
				int temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
		PrintArray(data, length);
	}
	*/
	return 0;
}
int SelectionSort3(int *data, int length)
{
	for(int i=0; i<length; i++)
	{
		int min = i;
		for(int j=i+1; j<length; j++)
		{
			if(data[min] > data[j])
				min = j;
		}

		if(min != i)
			swap(data, min, i);
		PrintArray(data, length);
	}
	return 0;
}

int SelectionSort2(int *data, int length)
{
	for(int i=0; i<length-1; i++)
	{
		int min = i;
		for(int j=i; j<length; j++)
		{
			if(data[min] > data[j])
				min = j;
		}
		if(min !=i)
			swap(data, i, min);
		PrintArray(data, length);
	}
	return 0;
}

int SelectionSort(int *data, int length)
{

	for (int i=0; i<length; i++)
	{
		int minIndex = i;
		for (int j=i+1;j<length; j++)
		{
			if (data[j] < data[minIndex])
			{
				minIndex = j;
			}
		}
		int temp = data[i];
		data[i] = data[minIndex];
		data[minIndex] = temp;
		PrintArray(data, length);
	}
	return 0;
}

void QuickSort(int *data, int _left, int _right)
{
	int left = _left;
	int right = _right;
	int temp = 0;
	if(left <right)
	{
		temp = data[left];
		while(left != right)
		{
			while(right>left && data[right]>= temp)
				right--;
			data[left] = data[right];

			while(left<right && data[left]<=temp)
				left++;
			data[right] = data[left];
		}
		data[right] = temp;
		QuickSort(data, _left, left-1);
		QuickSort(data, right+1, _right);
	}

}

int main(int argc, char** argv)
{
	//int data[10] = {1,38,5, 44, 15,36, 27, 2, 44, 19};
	int data[10] = {9,3,1,4,2,0,7,8,6,5};

	PrintArray(data, 10);
	printf("==========================================\n");
	//BubbleSort(data, sizeof(data)/sizeof(int));
	//SelectionSort3(data, sizeof(data)/sizeof(int));
	QuickSort(data, 0, 9);
	PrintArray(data, 10);
	char c = getchar();

	return 0;
}

