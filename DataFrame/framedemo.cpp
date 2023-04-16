#include "dataframe.h"
#include "otherstruct.h"

int main() {
	CirLink L;
	InitCirLink(L);
	CirLinkInsert(L, 1, 23);
	CirLinkInsert(L, 1, 24);
	CirLink p;
	p = L;
	while (p->next != L) {
		p = p->next;
		cout << p->cdata << endl;
	}
	return 0;
}

/*
* 	LinkList L;
	CreteList_R(L, 4);
	LinkList p = L->next;
	while (p) {
		cout << p->data << endl;
		p = p->next;
	}
*/