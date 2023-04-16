#include "otherstruct.h"

/*������Ҫ��д�α���������������ʮ���ٵ����ݽṹ*/
/*��Щ��������ݽṹ�������д��������*/

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

