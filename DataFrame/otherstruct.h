#pragma once

/// <summary>
/// Ñ­»·Á´±í
/// </summary>
typedef struct CNode {
	int cdata;
	struct CNode* next;
}CNode,*CirLink;

void InitCirLink(CirLink& L);
bool GetCirElem(CirLink L, int i, int& e);
CNode* LocateCirElem(CirLink L, int e);
bool CirLinkInsert(CirLink& L, int i, int e);

