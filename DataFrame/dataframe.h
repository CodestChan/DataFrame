#pragma once

#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

//˳���
typedef struct {
	int* elem;
	int length;
}SqList;

int InitList(SqList&);
int GetElem(SqList, int, int&);
int LocateElem(SqList, int);
int ListInsert(SqList&, int, int);
int ListDelete(SqList&, int);
void TraverseList(SqList);

//������
typedef struct LNode{
	int data;
	struct LNode* next;
}LNode,*LinkList;

void InitLinkList(LinkList&);
int GetLinkElem(LinkList, int, int&);
LNode* LocateLinkElem(LinkList, int);
int ListLinkInsert(LinkList&, int, int);
int ListLinkDelete(LinkList&, int);