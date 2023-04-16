#include "dataframe.h"

constexpr auto MAXSIZE = 100;

//��ʼ��˳���
int InitList(SqList& L) {
	L.elem = new int[MAXSIZE];
	if (!L.elem) return -1;
	L.length = 0;
}

//˳���ȡֵ
/*
* L:������Ҫ������˳���
* i:��Ҫȡֵ��λ��(λ������±꣬��ʾ��i��Ԫ��)��
* e:����һ����������ȡ����ֵ����e;
*/
int GetElem(SqList L, int i, int& e) {
	if (i<1 || i>L.length) return -1;
	e = L.elem[i - 1];
	return 0;
}

//˳���Ĳ���
/*
* L:��Ҫ������˳���;
* e:���ҵ�Ԫ�أ�
* ��������Ԫ�����ڵ��±ꣻ
*/
int LocateElem(SqList L, int e) {
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e) return i;
	}
	return -1;
}

//˳���Ĳ���
/*
* L:��Ҫ������˳���;
* i:�����λ�ã���λ������±ꣻ
* e:�����Ԫ�أ�
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

//˳����ɾ��
/*
* L:��Ҫ������˳���;
* i:��Ҫɾ��Ԫ�ص�λ��
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

//��ʼ����������ͷ��㣩
void InitLinkList(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	return;
}

//������ȡֵ
/*
* L:Ҫȡֵ������;
* i:ȡֵ��λ��;
* e:��ȡ����ֵ����e;
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

//������İ�ֵ����
/*
* L:��Ҫ���ҵ�����;
* e:��Ҫ���ҵ�ֵ;
* ��������������ֵ�ĵ�ַ
*/
LNode* LocateLinkElem(LinkList L, int e) {
	LinkList p;
	p = L->next;
	while (p && p->data != e)
		p = p->next;
	return p;
}

//������Ĳ���
/*
* L:Ҫ���������;
* i:�����λ��;
* e:�����ֵ;
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

//�������ɾ��
/*
* L:Ҫ����������;
* i:ɾ����λ��;
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

