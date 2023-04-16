#include "dataframe.h"

int main() {
	LinkList L;
	CreteList_R(L, 4);
	LinkList p = L->next;
	while (p) {
		cout << p->data << endl;
		p = p->next;
	}
	return 0;
}

/*
* 	LinkList L;
	InitLinkList(L);
	ListLinkInsert(L, 1, 15);
	ListLinkInsert(L, 2, 52);
	ListLinkInsert(L, 3, 69);
	int elem;
	GetLinkElem(L, 2, elem);
	LinkList index;
	index=LocateLinkElem(L, 52);
	LinkList p;
	p = L->next;
	while (p) {
		cout << p->data<<endl;
		p=p->next;
	}
	cout << "第二个元素是：" << elem<<endl;
	cout << "数值为52的元素位置是：" << index << endl;
	cout << index->data << " " << index->next << endl;
*/
/*
 	SqList L;
	InitList(L);
	ListInsert(L, 1, 18);
	ListInsert(L, 1, 52);
	ListInsert(L, 1, 96);
	int search;
	GetElem(L, 2, search);
	int index = LocateElem(L, 96);
	cout << search << endl;
	cout << index << endl;
	TraverseList(L);
*/