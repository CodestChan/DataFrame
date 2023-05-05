#pragma once

#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

/// <summary>
/// 循环链表
/// </summary>
typedef struct CNode {
	int cdata;
	struct CNode* next;
}CNode,*CirLink;

void InitCirLink(CirLink& L);
bool GetCirElem(CirLink L, int i, int& e);
CNode* LocateCirElem(CirLink L, int e);
bool CirLinkInsert(CirLink& L, int i, int e);
bool CirLinkDelete(CirLink& L, int i);

/// <summary>
/// 双向链表
/// </summary>
typedef struct DuLNode {
	int Ddata;
	struct DuLNode* prior;
	struct DuLNode* next;
}DuLNode,*DuLinkList;

void InitDuLink(DuLinkList& L);
DuLNode* Get_Dul(DuLinkList L, int i);
bool DulInsert(DuLinkList& L, int i, int e);
bool DulDelete(DuLinkList& L, int i);
void CreateDul(DuLinkList& L, int n);

