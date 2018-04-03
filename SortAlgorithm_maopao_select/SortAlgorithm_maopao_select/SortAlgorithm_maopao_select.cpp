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

int BubbleSort(int *data, int length)
{
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

int main(int argc, char** argv)
{
	int data[10] = {1,38,5, 44, 15,36, 27, 2, 44, 19};

	PrintArray(data, 10);
	printf("==========================================\n");
	//BubbleSort(data, sizeof(data)/sizeof(int));
	SelectionSort(data, sizeof(data)/sizeof(int));
	char c = getchar();

	return 0;
}

