#pragma once

#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

//Ë³Ðò±í
typedef struct {
	int* elem;
	int length;
}SqList;

int InitList(SqList& L);
int GetElem(SqList L, int i, int& e);
int LocateElem(SqList L, int e);
int ListInsert(SqList& L, int i, int e);
int ListDelete(SqList& L, int i);
void TraverseList(SqList L);

//µ¥Á´±í
typedef struct LNode{
	int data;
	struct LNode* next;
}LNode,*LinkList;

void InitLinkList(LinkList& L);
int GetLinkElem(LinkList L, int i, int& e);
LNode* LocateLinkElem(LinkList L, int e);
int ListLinkInsert(LinkList& L, int i, int e);
int ListLinkDelete(LinkList& L, int i);
void CreateList_H(LinkList& L, int n);
void CreteList_R(LinkList& L, int n);