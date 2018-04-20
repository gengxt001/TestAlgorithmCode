// SortAlgorithm_Insert_Shell_Merge.cpp : Defines the entry point for the console application.
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

int InsertSort2(int *data, int length)
{
	int current;
	for(int i=1; i<length; i++)
	{
		current = data[i];
		int preIndex = i-1;
		while(preIndex >=0 && data[preIndex]>current)
		{
			data[preIndex+1] = data[preIndex];
			preIndex--;
		}
		data[preIndex+1] = current;
		PrintArray(data,length);
	}
	return 0;
}

int InsertSort(int *data, int length)
{
	int current;
	for (int i=1; i<length; i++)
	{
		current = data[i];
		int preIndex = i-1;
		while (preIndex>=0 && current< data[preIndex])
		{
			data[preIndex+1] = data[preIndex];
			preIndex --;
		}
		data[preIndex+1] = current;
		PrintArray(data, length);
	}

	return 0;
}

int ShellSort(int *data, int length)
{
	int temp, gap = length / 2;
        while (gap > 0) {
            for (int i = gap; i < length; i++) {
                temp = data[i];
                int preIndex = i - gap;
                while (preIndex >= 0 && data[preIndex] > temp) {
                    data[preIndex + gap] = data[preIndex];
                    preIndex -= gap;
                }
                data[preIndex + gap] = temp;
            }
            gap /= 2;
			PrintArray(data, length);
        }
	return  0;
}


int main(int argc, char** argv)
{
	int data[10] = {1,38,5, 44, 15,36, 27, 2, 44, 19};

	PrintArray(data, 10);
	
	printf("==========================================\n");
	//InsertSort2(data, 10);
	ShellSort(data, 10);

	char c = getchar();

	return 0;
}

