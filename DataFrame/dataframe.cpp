#include "dataframe.h"

constexpr auto MAXSIZE = 100;

//初始化顺序表
int InitList(SqList& L) {
	L.elem = new int[MAXSIZE];
	if (!L.elem) return -1;
	L.length = 0;
}

//顺序表取值
/*
* L:传入需要操作的顺序表；
* i:需要取值的位置(位序而非下标，表示第i个元素)；
* e:传入一个变量，将取到的值赋给e;
*/
int GetElem(SqList L, int i, int& e) {
	if (i<1 || i>L.length) return -1;
	e = L.elem[i - 1];
	return 0;
}

//顺序表的查找
/*
* L:需要操作的顺序表;
* e:查找的元素；
* 函数返回元素所在的下标；
*/
int LocateElem(SqList L, int e) {
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e) return i;
	}
	return -1;
}

//顺序表的插入
/*
* L:需要操作的顺序表;
* i:插入的位置，是位序而非下标；
* e:插入的元素；
*/
int ListInsert(SqList& L, int i, int e) {
	if ((i < 1) || (i > L.length + 1)) return -1;
	if (L.length == MAXSIZE) return -1;
	for (int j = L.length - 1; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j];
	L.elem[i - 1] = e;
	++L.length;
	return 0;
}

//顺序表的删除
/*
* L:需要操作的顺序表;
* i:需要删除元素的位序；
*/
int ListDelete(SqList& L, int i) {
	if ((i < 1) || (i > L.length)) return -1;
	for (int j = i; j <= L.length - 1; j++)
		L.elem[j - 1] = L.elem[j];
	--L.length;
	return 0;
}

void TraverseList(SqList L) {
	for (int i = 0; i < L.length; i++) {
		cout << L.elem[i]<<endl;
	}
}

//初始化单链表（带头结点）
void InitLinkList(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	return;
}

//单链表取值
/*
* L:要取值的链表;
* i:取值的位置;
* e:将取到的值赋给e;
*/
int GetLinkElem(LinkList L, int i, int& e) {
	LinkList p;
	p = L->next;
	int j = 1;
	while (p && j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i) return -1;
	e = p->data;
	return 0;
}

//单链表的按值查找
/*
* L:需要查找的链表;
* e:需要查找的值;
* 函数返回所查找值的地址
*/
LNode* LocateLinkElem(LinkList L, int e) {
	LinkList p;
	p = L->next;
	while (p && p->data != e)
		p = p->next;
	return p;
}

//单链表的插入
/*
* L:要插入的链表;
* i:插入的位序;
* e:插入的值;
*/
int ListLinkInsert(LinkList& L, int i, int e) {
	LinkList p = L;
	int j = 0;
	while (p && (j < i - 1)) {
		p = p->next;
		++j;
	}
	if (!p || (j > i - 1)) return -1;
	LNode* s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return 0;
}

//单链表的删除
/*
* L:要操作的链表;
* i:删除的位置;
*/
int ListLinkDelete(LinkList& L, int i) {
	LinkList p = L;
	int j = 0;
	while ((p->next) && (j < i - 1)) {
		p = p->next;
		++j;
	}
	if (!(p->next) || (j > i - 1)) return -1;
	LinkList q = p->next;
	p->next = q->next;
	delete q;
	return 0;
}

