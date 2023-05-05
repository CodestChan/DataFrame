#include "otherstruct.h"

/*这里主要编写课本上有描述但描述十分少的数据结构*/
/*这些额外的数据结构都不会编写函数描述*/

void InitCirLink(CirLink& L) {
	L = new CNode;
	L->next = L;
	return;
}

bool GetCirElem(CirLink L, int i, int& e) {
	CirLink p;
	p = L->next;
	int j = 1;
	while ((p!=L) && j < i) {
		p = p->next;
		++j;
	}
	if ((p==L) || j > i) return false;
	e = p->cdata;
	return true;
}

CNode* LocateCirElem(CirLink L, int e) {
	CirLink p;
	p = L->next;
	while ((p!=L) && p->cdata != e)
		p = p->next;
	return p;
}

bool CirLinkInsert(CirLink& L, int i, int e) {
	CirLink p = L;
	int j = 0;
	while (p->next!=L && (j < i - 1)) {
		p = p->next;
		++j;
	}
	if (j > i - 1) return false;
	if (p->next == L) {
		CirLink s = new CNode;
		s->cdata = e;
		s->next = L;
		p->next = s;
		return true;
	}
	CirLink s = new CNode;
	s->cdata = e;
	s->next = p->next;
	p->next = s;
	return true;
}

bool CirLinkDelete(CirLink& L, int i) {
	CirLink p = L;
	int j = 0;
	while ((p->next) && (j < i - 1)) {
		p = p->next;
		++j;
	}
	if (!(p->next) || (j > i - 1)) return false;
	CirLink q = p->next;
	p->next = q->next;
	delete q;
	return true;
}

void InitDuLink(DuLinkList& L) {
	L = new DuLNode;
	L->prior = nullptr;
	L->next = nullptr;
}

DuLNode* Get_Dul(DuLinkList L, int i) {
	DuLinkList p = L->next;
	int j = 1;
	while ((p != nullptr) && (j < i)) {
		p = p->next;
		++j;
	}
	return p;
}

bool DulInsert(DuLinkList& L, int i, int e) {
	DuLinkList p;
	if (!(p = Get_Dul(L, i)))return false;
	DuLinkList s = new DuLNode;
	s->Ddata = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return true;
}

bool DulDelete(DuLinkList& L, int i) {
	DuLinkList p;
	if (!(p = Get_Dul(L, i))) return false;
	DuLinkList s = new DuLNode;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	delete p;
	return true;
}

void CreateDul(DuLinkList& L,int n) {
	DuLinkList r = L;
	int e;
	for (int i = 0; i < n; i++) {
		DuLinkList s = new DuLNode;
		cin >> e;
		s->Ddata = e;
		r->next = s;
		s->prior = r;
		s->next = nullptr;
		r = s;
	}
}

