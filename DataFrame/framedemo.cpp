
#include "otherstruct.h"

int main() {
	DuLinkList L;
	InitDuLink(L);
	CreateDul(L, 2);
	DulInsert(L, 1, 5);
	DuLinkList p = L;
	while (p->next != nullptr) {
		p=p->next;
		cout << p->Ddata << endl;
	}
	return 0;
}

