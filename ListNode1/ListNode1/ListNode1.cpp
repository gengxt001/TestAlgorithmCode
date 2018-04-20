// ListNode1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>

typedef struct Node
{
	int value;
	Node *pNext;
}Node;

int error_no = 0;

//有一个空Node的情况
Node* Create(int length)
{
	Node *pHead = new Node();
	pHead->pNext = NULL;

	if(length == 0)
		return pHead;
	
	Node *pCur = NULL;
	for(int i=0; i<length; i++)
	{
		Node *pNode = new Node();
		if(pNode ==NULL)
		{
			return pHead;
		}
		else
		{
			pNode->value = rand()%100;
			pNode->pNext = NULL;
			if(pHead->pNext == NULL)
			{
				pHead->pNext = pNode;
				pCur = pNode;
			}
			else
			{
				pCur->pNext = pNode;
				pCur = pNode;
			}
		}
	}
	
	return pHead;
}

Node* Create2(int length)
{
	Node *pHead = NULL;
	if(length <=0)
		return pHead;

	Node *pCur = NULL;
	for(int i=0; i<length; i++)
	{
		Node *pNew = new Node();
		if(pNew != NULL)
		{
			pNew->pNext = NULL;
			pNew->value = rand()%100;
			if(pHead == NULL)
			{
				pHead = pNew;
				pCur = pNew;
			}
			else
			{
				pCur->pNext = pNew;
				pCur = pNew;
			}
		}
	}
	return pHead;
}

void PrintList(Node* pHead)
{
	if(pHead == NULL || pHead->pNext == NULL)
	{
		printf("NULL\n");
		return;
	}
	Node *pPtr = pHead->pNext;
	while(pPtr != NULL)
	{
		printf("%d-->", pPtr->value);
		pPtr = pPtr->pNext;
	}
	printf("NULL\n");
}

void PrintList2(Node *pHead)
{
	while(pHead !=NULL)
	{
		printf("%d\t", pHead->value);
		pHead = pHead->pNext;
	}
}

int GetLength(Node *pHead)
{
	int n = 0;
	Node *pCurrent = pHead;
	while(pCurrent != NULL)
	{
		n++;
		pCurrent = pCurrent->pNext;
	}
	return n;
}

Node* Reserve(Node *pHead)
{
	if(pHead==NULL || pHead->pNext == NULL)
		return pHead;

	Node *pReservedHead = NULL;
	Node *pCurrent = pHead;	

	while(pCurrent != NULL)
	{
		Node *pTemp = pCurrent;
		pCurrent = pCurrent->pNext;

		pTemp->pNext = pReservedHead;
		pReservedHead = pTemp;
	}

	return pReservedHead;
}

Node* GetNode_K(Node *pHead, int k)
{
	int n=0;
	if(pHead == NULL || k<0)
		return NULL;

	Node *pCurrent = pHead;
	while(pCurrent != NULL && n<k)
	{
		n++;
		pCurrent = pCurrent->pNext;
	}

	return pCurrent;
}

Node* GetNode_ReverseK(Node *pHead, int k)
{
	if(k==0 || pHead ==NULL)
		return NULL;

	Node *pAhead = pHead;
	Node *pBehind = pHead;
	while(k>1 && pAhead!=NULL)
	{
		k--;
		pAhead = pAhead->pNext;
	}
	if(pAhead==NULL || k>1)
		return NULL;
	while(pAhead->pNext != NULL)
	{
		pAhead = pAhead->pNext;
		pBehind = pBehind->pNext;
	}
	return pBehind;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Node *pHead = Create2(10);
	PrintList2(pHead);

	printf("\nLength = %d\n", GetLength(pHead));
	printf("\nLength = %d\n", GetLength(pHead));

	//Node *pReserved = Reserve(pHead);
	//PrintList2(pReserved);

	//Node *k1 = GetNode_K(pHead, 0);
	//Node *k2 = GetNode_K(pHead, 9);

	Node *reK1 = GetNode_ReverseK(pHead, 1);
	return 0;
}

