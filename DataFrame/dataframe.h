#pragma once

#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

//À≥–Ú±Ì
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

//µ•¡¥±Ì
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

/// <summary>
/// À≥–Ú’ª
/// </summary>
typedef struct {
	int* base;
	int* top;
	int stacksize;
}SqStack;

bool InitStack(SqStack& S);
bool Push(SqStack& S, int e);
bool Pop(SqStack& S, int& e);
int GetTop(SqStack S);

/// <summary>
/// ¡¥’ª
/// </summary>
typedef struct StackNode {
	int data;
	struct StackNode* next;
}StackNode,*LinkStack;

bool InitStack(LinkStack& S);
bool Push(LinkStack& S, int e);
bool Pop(LinkStack& S, int& e);
int GetTop(LinkStack S);
